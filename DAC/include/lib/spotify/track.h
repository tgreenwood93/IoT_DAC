#pragma once

#include "include/lib/format.h"
#include "include/lib/spotify/entity.h"

#include "thirdparty/json/single_include/nlohmann/json.hpp"

#include <string>

namespace lib
{
	namespace spt
	{
		/**
		 * A music track
		 */
		class track : public entity
		{
		public:
			track() = default;

			/**
			 * Local track, not streamed from Spotify
			 */
			bool is_local = false;

			/**
			 * Playable in current region
			 */
			bool is_playable = true;

			/**
			 * Track duration in milliseconds
			 */
			int duration = 0;

			/**
			 * ISO date when it was added to the context
			 */
			std::string added_at;

			/**
			 * Album track belongs in
			 */
			entity album;

			/**
			 * Artist track is made by
			 */
			std::vector<entity> artists;

			/**
			 * URL to cover of album
			 */
			std::string image;

			/**
			 * Format track as "{artist} - {name}" or "(no track)"
			 * @note Only shows first artist, to show all, use details()
			 */
			auto title() const -> std::string;

			/**
			 * Format track as "{artists}\n{name}" or "(no track)"
			 * @note Multiple artists are separated using commas
			 */
			auto details() const -> std::string;

			/**
			 * Has a valid name and artist
			 */
			auto is_valid() const -> bool override;
		};

		/**
		 * track -> json
		 */
		void to_json(nlohmann::json &j, const track &t);

		/**
		 * json -> track
		 */
		void from_json(const nlohmann::json &j, track &t);
	}
}
