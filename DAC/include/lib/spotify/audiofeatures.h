#pragma once

//#include "include/lib/audiofeatures.h"
#include "include/lib/format.h"
#include "include/lib/spotify/audiofeatureenum.h"
//#include "include/lib/strings.h"
#include "include/lib/spotify/audiokey.h"
#include "include/lib/spotify/audiomode.h"
#include "include/lib/spotify/audiofeature.h"
#include "thirdparty/json/single_include/nlohmann/json.hpp"

#include <string>
#include <map>
#include <vector>

namespace lib
{
	namespace spt
	{
		/**
		 * Audio analysis features
		 */
		class audio_features
		{
		public:
			audio_features() = default;

			auto items() const -> const std::vector<lib::spt::audio_feature> &;

			void add(lib::audio_feature feature, float value);
			void add(audio_key key);
			void add(audio_mode mode);

			static auto to_audio_feature(const std::string &feature) -> lib::audio_feature;

		private:
			std::vector<lib::spt::audio_feature> values;
		};

		/** JSON -> Audio features */
		void from_json(const nlohmann::json &j, audio_features &a);
	}
}
