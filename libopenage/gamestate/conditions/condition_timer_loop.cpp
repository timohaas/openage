// Copyright 2015-2016 the openage authors. See copying.md for legal info.

#include "condition_timer_loop.h"

namespace openage {

	ConditionTimerLoop::ConditionTimerLoop(uint32_t ms) {
		this->ms = ms;
	}

	ConditionTimerLoop::~ConditionTimerLoop() {

	}

	bool ConditionTimerLoop::check(uint32_t gametime,uint32_t update) {
		if( gametime - this->last > this->ms ) {
			// needed if check is not called every tick
			while(gametime - this->last > this->ms) {
				this->last += this->ms;
			}
			return true;
		}
		return false;
	}

	Json::Value ConditionTimerLoop::toJson() {
		Json::Value json;
		json["type"]  = "timer-loop";
		json["value"] = this->ms;
		return json;
	}
}
