#include "include/lib/spotify/api.h"

using namespace lib::spt;

// Currently unavailable:
// artists

void api::artist(const std::string &id,
	lib::callback<lib::spt::artist> &callback)
{
	get(lib::fmt::format("artists/{}", id), callback);
}

void api::top_tracks(const lib::spt::artist &artist,
	lib::callback<std::vector<lib::spt::track>> &callback)
{
	get(lib::fmt::format("artists/{}/top-tracks?country=from_token",
		artist.id), [callback](const nlohmann::json &json)
	{
		callback(json.at("tracks"));
	});
}

void api::related_artists(const lib::spt::artist &artist,
	lib::callback<std::vector<lib::spt::artist>> &callback)
{
	get(lib::fmt::format("artists/{}/related-artists",
		artist.id), [callback](const nlohmann::json &json)
	{
		callback(json.at("artists"));
	});
}

void api::albums(const lib::spt::artist &artist,
	lib::callback<std::vector<lib::spt::album>> &callback)
{
	get_items(lib::fmt::format("artists/{}/albums?country=from_token",
		artist.id), callback);
}
