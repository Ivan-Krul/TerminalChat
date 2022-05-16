#pragma once
#include <iostream>
#include <conio.h>

using std::wstring;
using std::wcout;

void edit(wstring& str) {
    wchar_t sym = '\0';
    wcout << L"\nInput : ";
    wcout << str;
    while (sym != 13) {
        if (_kbhit()) {
            sym = _getwch();

            if (sym != 13) {

                if (sym != L'\b') {
                    str += sym;
                    wcout << sym;
                }
                else if (str.size() != 0) {
                    str.erase(str.end() - 1);
                    wcout << L"\b \b";
                }

            }

        }
    }

    for (int i = 0;i < str.size() + 11;i++) wcout << L"\b \b";
    wcout << str << '\n';
}