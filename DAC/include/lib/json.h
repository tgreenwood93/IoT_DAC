#pragma once

#include "thirdparty/json/single_include/nlohmann/json.hpp"
#include "include/lib/log.h"
#include "thirdparty/filesystem/include/ghc/filesystem.hpp"

#include <fstream>

namespace lib
{
    /**
     * JSON utilities
     */
    class json
    {
    public:
        /**
         * Try to find an item and set if found
         * @param json JSON object to search in
         * @param names Names of keys to search for
         * @param item Item to set value to
         * @return If an item was found
         */
        template<typename T>
        static auto get_property(const nlohmann::json &json,
            const std::initializer_list<std::string> &names, T &item) -> bool
        {
            for (const auto &name : names)
            {
                if (json.contains(name) && !json.at(name).is_null())
                {
                    json.at(name).get_to(item);
                    return true;
                }
            }
            return false;
        }

        /**
         * Combine two JSON arrays
         * @param item1 First array
         * @param item2 Second array
         * @return Combined array, or an empty one on failure
         */
        static auto combine(const nlohmann::json &item1,
            const nlohmann::json &item2) -> nlohmann::json;

        /**
         * Get item from JSON if found
         * @param json JSON to find item in
         * @param key Key to try and find
         * @param item Item to set value to
         */
        template<typename T>
        static void get(const nlohmann::json &json, const std::string &key, T &item)
        {
            if (json.contains(key) && !json.at(key).is_null())
            {
                json.at(key).get_to(item);
            }
        }

        /**
         * Load and parse JSON from file
         * @param path Path to json file, including extension
         * @return JSON object, or null object on failure
         */
        static auto load(const ghc::filesystem::path &path) -> nlohmann::json;

        /**
         * Convenience method to parse generic class from JSON,
         * returns instance of T on failure
         */
        template<typename T>
        static auto load(const ghc::filesystem::path &path) -> T
        {
            auto json = load(path);
            if (json.is_null())
            {
                return T();
            }
            return json;
        }

        /**
         * Save specified item to a json file
         * @param path Path to json file, including extension
         * @param item Item to save
         */
        static void save(const ghc::filesystem::path &path, const nlohmann::json &json);

    private:
        json() = default;
    };
}
