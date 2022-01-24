#pragma once

#include "include/lib/spotify/audiofeatureenum.h"
#include "include/lib/spotify/audiofeature.h"
#include "include/lib/spotify/audiokey.h"
#include "include/lib/spotify/audiomode.h"
#include "include/lib/log.h"

#include <string>

namespace lib
{
	namespace spt
	{
		class audio_feature
		{
		public:
			/**
			 * Audio feature with value
			 * @param feature Category
			 * @param value Value
			 */
			audio_feature(lib::audio_feature feature, float value);

			/** Audio feature with key */
			explicit audio_feature(audio_key key);

			/** Audio feature with mode */
			explicit audio_feature(audio_mode mode);

			/**
			 * Get audio feature
			 * @return String representation
			 */
			auto get_feature() const -> std::string;

			/**
			 * Get name of value
			 * @return String representation
			 */
			auto get_name() const -> std::string;

			/**
			 * Get raw value
			 */
			auto get_value() const -> float;

			/**
			 * Get minimum possible value
			 */
			auto get_min() const -> float;

			/**
			 * Get maximum possible value
			 */
			auto get_max() const -> float;

			/**
			 * Get value description
			 */
			auto get_description() const -> std::string;

		private:
			lib::audio_feature feature = lib::audio_feature::unknown;
			float minimum = 0.F;
			float maximum = 1.F;
			float value = 0.F;
			std::string name;

			auto acousticness() const -> std::string;
			auto danceability() const -> std::string;
			auto energy() const -> std::string;
			auto instrumentalness() const -> std::string;
			auto liveness() const -> std::string;
			auto loudness(float &min, float &max) const -> std::string;
			auto speechiness() const -> std::string;
			auto tempo(float &max) const -> std::string;
			auto valence() const -> std::string;
			auto time_signature(float &max) const -> std::string;

			static auto to_string(audio_key key) -> std::string;
			static auto to_string(audio_mode mode) -> std::string;
		};
	}
}
