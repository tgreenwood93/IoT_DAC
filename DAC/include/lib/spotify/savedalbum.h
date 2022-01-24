#pragma once

#include <string>

#include "include/lib/spotify/album.h"

namespace lib
{
	namespace spt
	{
		class saved_album
		{
		public:
			saved_album() = default;

			std::string added_at;

			lib::spt::album album;
		};

		/**
		 * Saved album -> JSON
		 */
		void to_json(nlohmann::json &j, const saved_album &s);

		/**
		 * JSON -> Saved album
		 */
		void from_json(const nlohmann::json &j, saved_album &s);
	}
}
