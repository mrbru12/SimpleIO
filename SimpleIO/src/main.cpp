#include "SimpleIO.h"
#include <Windows.h>

int main()
{
    // SimpleIO::Keyboard::write("teste a ");

    for (;;)
    {
        if (GetKeyState(VK_CAPITAL) & WM_KEYDOWN)
        {
            SimpleIO::Mouse::click(SimpleIO::Mouse::Buttons::left);

            // Sleep(10);
        }

        Sleep(1); // Sleep(10);
    }
}