#include "include/lib/spotify/api.h"

using namespace lib::spt;

void api::search(const std::string &query, lib::callback<lib::spt::search_results> &callback)
{
	get(lib::fmt::format("search?q={}&type=album,artist,playlist,track&limit=50&market=from_token",
		query), callback);
}
