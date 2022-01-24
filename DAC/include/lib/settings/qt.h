#pragma once

#include "thirdparty/json/single_include/nlohmann/json.hpp"

namespace lib
{
    namespace setting
    {
        /**
         * Qt Widgets specific settings
         */
        using qt = struct qt
        {
            /**
             * Show system borders and title bar
             */
            bool system_title_bar = false;
        };

        void to_json(nlohmann::json &j, const qt &q);

        void from_json(const nlohmann::json &j, qt &q);
    }
}
