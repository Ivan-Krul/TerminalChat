
#include <iostream>
#include <string>
#include "user.h"
#include "message.h"
#include "interface.h"
#include "chat.h"

using std::wstring;
using std::wcout;

int main()
{
    user User;
    user User1;
    interface_t interf;
    User.registrate(L"Alice", L"SASA");
    User1.registrate(L"Bob", L"SASA");
    User.get_userindex();
    User1.get_userindex();

    chat Chat;

    Chat.create(User, User1);

    interf.write_chat(Chat, User);
    interf.show_chat(Chat);
    interf.write_chat(Chat, User1);
    interf.show_chat(Chat);
    interf.write_chat(Chat, User);
    interf.show_chat(Chat);
    interf.write_chat(Chat, User1);
    interf.show_chat(Chat);
    interf.write_chat(Chat, User);
    interf.show_chat(Chat);
    interf.write_chat(Chat, User1);
    interf.show_chat(Chat);

}
