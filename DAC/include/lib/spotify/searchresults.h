#pragma once

#include "include/lib/spotify/album.h"
#include "include/lib/spotify/artist.h"
#include "include/lib/spotify/playlist.h"
#include "include/lib/spotify/track.h"

#include <vector>

namespace lib
{
	namespace spt
	{
		/**
		 * Spotify search results
		 */
		class search_results
		{
		public:
			search_results() = default;

			/**
			 * Albums found
			 */
			std::vector<lib::spt::album> albums;

			/**
			 * Artists found
			 */
			std::vector<lib::spt::artist> artists;

			/**
			 * Tracks found
			 */
			std::vector<lib::spt::track> tracks;

			/**
			 * Playlists found
			 */
			std::vector<lib::spt::playlist> playlists;
		};

		/**
		 * Search results -> JSON
		 */
		void to_json(nlohmann::json &j, const search_results &s);

		/**
		 * JSON -> Search results
		 */
		void from_json(const nlohmann::json &j, search_results &s);
	}
}
