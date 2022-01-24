#pragma once

#include "thirdparty/json/single_include/nlohmann/json.hpp"
#include "include/lib/spotify/track.h"
#include "include/lib/spotify/device.h"
#include "include/lib/format.h"
#include "include/lib/spotify/context.h"
#include "include/lib/spotify/repeatstate.h"

namespace lib
{
	namespace spt
	{
		class playback
		{
		public:
			playback() = default;

			/**
			 * Metadata for MPRIS
			 */
			auto metadata() const -> nlohmann::json;

			/**
			 * Current volume, fetched from active device
			 */
			auto volume() const -> int;

			/**
			 * Context currently playing from
			 */
			lib::spt::context context;

			/**
			 * Repeat mode
			 */
			lib::repeat_state repeat = lib::repeat_state::off;

			/**
			 * Current playing track
			 */
			lib::spt::track item;

			/**
			 * Is currently playing something
			 */
			bool is_playing = false;

			/**
			 * Shuffle tracks
			 */
			bool shuffle = false;

			/**
			 * Progress in current track, in milliseconds
			 */
			int progress_ms = 0;

			/**
			 * Current active device
			 */
			lib::spt::device device;
		};

		/**
		 * json -> playback
		 */
		void from_json(const nlohmann::json &j, playback &p);

		/**
		 * playback -> json
		 */
		void to_json(nlohmann::json &j, const playback &p);
	}
}
