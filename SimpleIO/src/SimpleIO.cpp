#include "SimpleIO.h"

using namespace SimpleIO;

// <<<==============================>>> Mouse Buttons Class Implementation <<<==============================>>>

Mouse::Button::Button(DWORD downVal, DWORD upVal) : downValue(downVal), upValue(upVal)
{
}

// <<<==============================>>> Mouse Input Functions Implementation <<<==============================>>>

void Mouse::hold(Button button)
{
    INPUT input = INPUT();

    input.type = INPUT_MOUSE;

    input.mi.dwFlags = button.downValue;

    SendInput(1, &input, sizeof(INPUT));
}

void Mouse::release(Button button)
{
    INPUT input = INPUT();
    
    input.type = INPUT_MOUSE;

    input.mi.dwFlags = button.upValue;
    
    SendInput(1, &input, sizeof(INPUT));
}

void Mouse::click(Button button)
{
    Mouse::hold(button);
    Mouse::release(button);
}

// <<<==============================>>> Mouse Position Functions Implementation <<<==============================>>>

Mouse::Position::Position(const int xPoint, const int yPoint) : x(xPoint), y(yPoint)
{
}

void Mouse::moveTo(int x, int y)
{
    INPUT input = INPUT();
    
    input.type = INPUT_MOUSE;

    int screenWidth = GetSystemMetrics(SM_CXSCREEN) - 1;
    int screenHeight = GetSystemMetrics(SM_CYSCREEN) - 1;
    
    input.mi.dx = x * (65535 / screenWidth); // Pesquisa de onde saiu esse valor hardcoded!
    input.mi.dy = y * (65535 / screenHeight);

    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;

    SendInput(1, &input, sizeof(INPUT));
}

void Mouse::moveTo(Position& pos)
{
    Mouse::moveTo(pos.x, pos.y);
}

Mouse::Position Mouse::getPos()
{
    POINT point = POINT();

    GetCursorPos(&point);

    return Position(point.x, point.y);
}

// <<<==============================>>> Keyboard Key Class Implementation <<<==============================>>>

Keyboard::Key::Key(char keyVal)
{
    keyValue = VkKeyScanA(keyVal);
}

Keyboard::Key::Key(short keyVal)
{
    keyValue = keyVal;
}

// <<<==============================>>> Keyboard Input Functions Implementation <<<==============================>>>

void Keyboard::hold(Key key)
{
    INPUT input = INPUT();

    input.type = INPUT_KEYBOARD;

    input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;

    input.ki.wVk = key.keyValue;

    SendInput(1, &input, sizeof(INPUT));
}

void Keyboard::release(Key key)
{
    INPUT input = INPUT();

    input.type = INPUT_KEYBOARD;

    input.ki.dwFlags = KEYEVENTF_KEYUP;

    input.ki.wVk = key.keyValue;

    SendInput(1, &input, sizeof(INPUT));
}

void Keyboard::press(Key key)
{
    Keyboard::hold(key);
    Keyboard::release(key);
}

void Keyboard::write(const char* sentence)
{
    for (int i = 0; sentence[i] != '\0'; i++)
        Keyboard::press(Key(sentence[i]));
}
