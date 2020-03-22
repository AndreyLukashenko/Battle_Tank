#include "ConsoleUI.h"

ConsoleUI* ConsoleUI::instance_ = nullptr;

ConsoleUI::ConsoleUI() 
{
    SetConsoleTitle(static_cast<LPCWSTR>(L"BATTLE CITY"));
    SMALL_RECT windowSize = { 0,0, FIELD_WIDTH, FIELD_HEIGHT };
    COORD windowBufsize = { FIELD_WIDTH, FIELD_HEIGHT };

    console_ = GetStdHandle(STD_OUTPUT_HANDLE);
    consoleIn_ = GetStdHandle(STD_INPUT_HANDLE);

    if (!SetConsoleScreenBufferSize(console_, windowBufsize))
        std::cout << GetLastError() << std::endl;
    if (!SetConsoleWindowInfo(console_, TRUE, &windowSize))
        std::cout << GetLastError() << std::endl;

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console_, &cursorInfo);
    cursorInfo.bVisible = false;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(console_, &cursorInfo);

    buffer_ = new CHAR_INFO[(FIELD_WIDTH) * (FIELD_HEIGHT)];

    bufferSize_.X = FIELD_WIDTH;
    bufferSize_.Y = FIELD_HEIGHT;

    bufferCoord_.X = 0;
    bufferCoord_.Y = 0;

    writeRegion_.Left = 0;
    writeRegion_.Top = 0;
    writeRegion_.Right = FIELD_WIDTH;
    writeRegion_.Bottom = FIELD_HEIGHT;
}


ConsoleUI::~ConsoleUI()
{
    if (instance_ != nullptr)
        delete instance_;
    if (buffer_ != nullptr)
        delete buffer_;
}


ConsoleUI& ConsoleUI::getInstance()
{
    if (instance_ == nullptr)
        instance_ = new ConsoleUI();
    return *instance_;
}


void ConsoleUI::clearInputBuffer()
{
    if(!FlushConsoleInputBuffer(consoleIn_))
        std::cout << "Input Error" << GetLastError();
}


void ConsoleUI::render()
{
    if (!WriteConsoleOutput(console_, buffer_, bufferSize_, bufferCoord_, &writeRegion_))
        std::cout << "Output Error" << GetLastError() << std::endl;
}


void ConsoleUI::setChar(int x, int y, wchar_t c, COLOR color)
{
    buffer_[x + (FIELD_WIDTH)*y].Char.UnicodeChar = c;
    buffer_[x + (FIELD_WIDTH)*y].Attributes = static_cast<WORD>(color);

}


wchar_t ConsoleUI::getChar(int x, int y) const
{
    return buffer_[x + (FIELD_WIDTH)*y].Char.AsciiChar;
}