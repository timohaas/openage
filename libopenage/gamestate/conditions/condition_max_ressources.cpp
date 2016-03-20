// Copyright 2015-2016 the openage authors. See copying.md for legal info.

#include "condition_max_ressources.h"

namespace openage {

	ConditionMaxRessources::ConditionMaxRessources(uint32_t player,game_resource resource, float value) {
		this->player   = player;
		this->resource = resource;
		this->value    = value;
	}

	ConditionMaxRessources::~ConditionMaxRessources() {

	}

	bool ConditionMaxRessources::check(uint32_t gametime,uint32_t update) {
		if( this->game->get_player(this->player)->amount(this->resource) <= this->value ) {
			return true;
		}
		return false;
	}

	picojson::value ConditionMaxRessources::toJson() {
		picojson::object json;
		json["type"]     = picojson::value("max-resources");
		json["player"]   = picojson::value( (double) this->player );
		json["value"]    = picojson::value( this->value );
		json["resource"] = picojson::value( this->getResourceString(this->resource) );
		return picojson::value(json);
	}
}
