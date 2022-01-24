#include "include/lib/spotify/context.h"

void lib::spt::from_json(const nlohmann::json &j, context &p)
{
	if (!j.is_object())
	{
		return;
	}

	j.at("uri").get_to(p.uri);
	j.at("type").get_to(p.type);
}
