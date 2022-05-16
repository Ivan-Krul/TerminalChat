#pragma once
#include "user.h"
#include "message.h"
#include <list>

using std::list;

class chat {
	user Null;
	user& UserAlpha = Null;
	user& UserBeta = Null;

	list<message> messages;
public:
	virtual void create(user& user_alpha, user& user_beta) {
		UserAlpha = user_alpha;
		UserBeta = user_beta;
	}

	virtual void send(message& msg) {
		messages.push_back(msg);
	}

	message show(size_t bias) {
		list<message>::iterator iter;
		for (iter = messages.begin();iter != messages.end() && bias != 0;iter++) {}

		return *iter;
	}

};
