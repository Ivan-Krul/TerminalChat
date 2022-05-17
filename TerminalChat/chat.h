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

	//bool check_message(message& msg) {
	//	return (msg.author_name() == UserAlpha.name() || msg.author_name() == UserBeta.name()) && (msg.author_index() == UserAlpha.userindex() || msg.author_index() == UserBeta.userindex());
	//}
public:
	virtual void create(user& user_alpha, user& user_beta) {
		UserAlpha = user_alpha;
		UserBeta = user_beta;
	}

	virtual void send(message& msg) {
		//if(check_message(msg))
			messages.push_back(msg);
	}

	virtual void send(wstring text, user& author) {
		message msg;
		msg.write(text, author);
		messages.push_back(msg);
	}

	size_t size() {
		return messages.size();
	}

	message show(size_t bias) {
		list<message>::iterator iter = messages.begin();
		while (iter != messages.end() && bias != 0) {
			bias--;
			iter++;
		}

		return *iter;
	}

};
