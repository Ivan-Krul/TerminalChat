#pragma once
#include <list>
#include <string>
#include "chat.h"
#include "user.h"

using std::list;
using std::wstring;

class database {
	chat chats;
	list<user> users;
public:
	void write_user(user& user_t) {
		users.push_back(user_t);
	}

	void save() {

	}
};