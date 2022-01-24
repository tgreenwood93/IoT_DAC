#pragma once

#include "include/lib/spotify/user.h"
#include "include/lib/spotify/track.h"
#include "include/lib/json.h"

#include <string>

namespace lib
{
	namespace spt
	{
		/**
		 * Playlist
		 */
		class playlist
		{
		public:
			playlist() = default;

			/**
			 * Optional playlist description
			 */
			std::string description;

			/**
			 * Playlist ID
			 */
			std::string id;

			/**
			 * URL to playlist image
			 */
			std::string image;

			/**
			 * Name of playlist
			 */
			std::string name;

			/**
			 * Snapshot ID
			 */
			std::string snapshot;

			/**
			 * Spotify ID of owner
			 */
			std::string owner_id;

			/**
			 * Display name of owner
			 */
			std::string owner_name;

			/**
			 * Collaborative playlist, where anyone can edit it
			 */
			bool collaborative = false;

			/**
			 * Readable and searchable by the public
			 */
			bool is_public = false;

			/**
			 * Tracks in playlist
			 */
			std::vector<lib::spt::track> tracks;

			/**
			 * URL to load tracks from
			 */
			std::string tracks_href;

			/**
			 * Number of tracks in playlist
			 * @note Prefer using track_count()
			 */
			int tracks_total = -1;

			/**
			 * Specified user is the owner of this playlist
			 */
			auto is_owner(const lib::spt::user &user) const -> bool;

			/**
			 * If no playlist has been parsed (invalid ID)
			 */
			auto is_null() const -> bool;

			/**
			 * Compare snapshot and check if playlist is up to date
			 */
			auto is_up_to_date(const std::string &snapshot) const -> bool;
		};

		void to_json(nlohmann::json &j, const playlist &p);

		void from_json(const nlohmann::json &j, playlist &p);
	}
}
