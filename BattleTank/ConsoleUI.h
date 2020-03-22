#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include <iostream>
#include <Windows.h>

#include "Constants.h"

class ConsoleUI
{
public:
    ~ConsoleUI();
    static ConsoleUI& getInstance();
    void              clearInputBuffer();
    void              render();

    void              setChar(int x, int y, wchar_t c, COLOR color);
    wchar_t           getChar(int x, int y) const;

private:

    ConsoleUI();

    static ConsoleUI* instance_;

    HANDLE            console_;
    HANDLE            consoleIn_;

    CHAR_INFO*        buffer_;
    COORD             bufferCoord_;
    COORD             bufferSize_;
    SMALL_RECT        writeRegion_;
};

#endif // !CONSOLE_UI_H



