#pragma once
#include <iostream>
#include <conio.h>
#include "chat.h"

using std::wstring;
using std::wcout;

class interface_t {
    bool IsWork;
public:
    bool edit(wstring& str) {
        wchar_t sym = '\0';
        wcout << L"Input : ";
        wcout << str;
        while (sym != 13) {
            if (_kbhit()) {
                sym = _getwch();

                if (sym != 13) {
                    if (sym != 0x1b) {
                        if (sym != L'\b') {
                            str += sym;
                            wcout << sym;
                        }
                        else if (str.size() != 0) {
                            str.erase(str.end() - 1);
                            wcout << L"\b \b";
                        }
                    }
                    else
                        return false;
                }


            }
        }

        for (int i = 0;i < str.size() + 11;i++) wcout << L"\b \b";
        wcout << str << '\n';
        return true;
    }

    void write_chat(chat& chat_t, user& author) {
        if (IsWork) {
            wstring msg;
            wcout << author.name() << "\t#" << std::hex << author.userindex() << std::dec << '\n';
            bool a = edit(msg);
            wcout << '\n';
            if (a)
                chat_t.send(msg, author);
            else IsWork = false;
        }
        else wcout << "\nProcess write_chat() was terminated";
    }

    void show_chat(chat& chat_t) {
        if (IsWork) {
            for (int i = 0;i < chat_t.size();i++) {
                message msg = chat_t.show(i);
                wcout << msg.author_name() << "\t#" << std::hex << msg.author_index() << std::dec << " : " << msg.text() << '\n';
            }
        }
        else wcout << "\nProcess show_chat() was terminated";
    }

    bool is_work() {
        return IsWork;
    }
};
