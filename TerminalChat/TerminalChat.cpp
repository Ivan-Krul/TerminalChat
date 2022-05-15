
#include <iostream>
#include <string>

using std::wstring;
using std::wcout;

class user {
    wstring Password;
    uint32_t UserIndex;
protected:
    wstring Login;
public:
    virtual void registrate(wstring login, wstring password) {
        Login = login;
        Password = password;
    }
};

class message {
    uint32_t AuthorIndex;
protected:
    wstring Text;
public:
    virtual void write(wstring input,uint32_t author_index) {
        Text = input;
        AuthorIndex = author_index;
    }

    wstring text() {
        return Text;
    }

    uint32_t author() {
        return AuthorIndex;
    }
};

int main()
{
    message msg;
    msg.write(L"Hello!", 1231);

    wcout << msg.text()<<" by "<<msg.author();
}
