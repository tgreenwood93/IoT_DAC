#pragma once

//#include "enum/palette.hpp"
//#include "enum/playlistorder.hpp"
//#include "enum/spotifycontext.hpp"
#include "log.h"
#include "paths.h"
#include "thirdparty/json/single_include/nlohmann/json.hpp"
#include "thirdparty/filesystem/include/ghc/filesystem.hpp"
#include "settings/general.h"
#include "settings/account.h"
#include "settings/spotify.h"
#include "settings/qt.h"
#include "include/lib/json.h"

#include <mutex>

namespace lib
{
    /**
     * Application settings
     */
    class settings
    {
    public:
        /**
         * Create new instance and attempt to load from file
         */
        explicit settings(const paths &paths);

        /**
         * Format settings in settings
         * @return JSON
         */
        auto to_json() const -> nlohmann::json;

        /**
         * Load settings from json
         * @param json JSON
         */
        void from_json(const nlohmann::json &json);

        /**
         * Save settings to file
         */
        void save();

        /**
         * Load settings from file
         */
        void load();

        /**
         * Account settings
         */
        setting::account account;

        /**
         * General settings
         */
        setting::general general;

        /**
         * Spotify settings
         */
        setting::spotify spotify;

        /**
         * Qt settings
         */
        auto qt() -> setting::qt &;

        /**
         * Qt settings (constant)
         */
        auto qt_const() const -> const setting::qt &;

        /**
         * Reset client_id and client_secret properties
         */
        void remove_client();

        /**
         * Reset access_token and refresh_token properties
         */
        void remove_tokens();

        /**
         * Get if dark theme should be used
         * @return Use dark theme
         */
        auto get_dark_theme() const -> bool;

        /**
         * Set if dark theme should be used
         * @param value Dark theme should be used
         */
        void set_dark_theme(bool value);

        /**
         * Get config file name
         * @return File name with path
         */
        auto file_name() const -> std::string;

        /**
         * Get path to config file name
         * @return Path
         */
        auto file_path() const -> std::string;

    private:
        /**
         * paths implementation
         */
        const paths &path;

        /**
         * Mutex for making sure we don't write to settings from multiple
         * threads
         */
        std::mutex mutex;

        /**
         * Qt settings
         */
        setting::qt qt_settings;

        /**
         * Set value from JSON in a "safe" way
         * @param json JSON object to try and find value from
         * @param key Key of value in root of JSON
         * @param value Value to write to
         * @deprecated Use lib::json::get
         */
        template<typename T>
        static void setValue(const nlohmann::json &json, const std::string &key,
            T &value)
        {
            if (!json.contains(key))
            {
                return;
            }

            try
            {
                json.at(key).get_to(value);
            }
            catch (const nlohmann::json::exception &e)
            {
                log::error("Failed to parse settings for key: {} ({})",
                    key, e.what());
            }
        }
    };
}
