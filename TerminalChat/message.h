#pragma once
#include <string>
#include "user.h"

using std::wstring;

class message {
    uint32_t AuthorIndex;
    wstring AuthorName;
protected:
    wstring Text;
public:
    virtual void write(const wstring input, user author) {
        Text = input;
        AuthorName = author.name();
        AuthorIndex = author.userindex();
    }

    const wstring text() {
        return Text;
    }

    wstring& edit() {
        return Text;
    }

    uint32_t author_index() {
        return AuthorIndex;
    }

    wstring author_name() {
        return AuthorName;
    }
};
