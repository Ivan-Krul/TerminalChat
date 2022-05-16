
#include <iostream>
#include <string>
#include "user.h"
#include "message.h"
#include "interface.h"

using std::wstring;
using std::wcout;

int main()
{
    user User;
    user User1;
    User.registrate(L"ABCD", L"SASA");
    User1.registrate(L"ABCD", L"SASA");
    User.get_userindex();
    User1.get_userindex();

    message msg;

    msg.write(L"Hello!", User);
    edit(msg.edit());

    wcout << '"' << msg.text() << "\" by " << msg.author_name()<< " #"<<msg.author_index() << '\n';
    wcout << User1.name() << " #" << User1.userindex() << '\n';
}
