#pragma once
#include <string>
#include "index_giver.h"
#include "database.h"

using std::wstring;

static index_giver IndexGiver;

class user {
    wstring Password;
    uint32_t UserIndex;
protected:
    wstring Name;
public:
    user() {
        UserIndex = 0;
    }

    virtual void registrate(wstring name, wstring password) {
        Name = name;
        Password = password;
    }

    virtual bool login(wstring name, uint32_t userindex, wstring password) {
        return (Name == name) && (UserIndex == userindex) && (Password == password);
    }

    void get_userindex() {
        if (UserIndex == 0) {
            UserIndex = IndexGiver.give_userindex();
        }
    }

    void tell_secretly(database& database_t) {

    }

    uint32_t userindex() {
        return UserIndex;
    }

    wstring& name() {
        return Name;
    }
};

