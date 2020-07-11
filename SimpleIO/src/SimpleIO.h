#pragma once

#include <Windows.h>

namespace SimpleIO
{
    namespace Mouse
    {
        struct Button
        {
            DWORD downValue;
            DWORD upValue;

            Button(DWORD downVal, DWORD upVal);
        };

        namespace Buttons
        {
            const Button left = Button(MOUSEEVENTF_LEFTDOWN, MOUSEEVENTF_LEFTUP);
            const Button right = Button(MOUSEEVENTF_RIGHTDOWN, MOUSEEVENTF_RIGHTUP);
            const Button middle = Button(MOUSEEVENTF_MIDDLEDOWN, MOUSEEVENTF_MIDDLEUP);
        }

        struct Position
        {
            int x;
            int y;

            Position(int xPoint, int yPoint);
        };
        
        void hold(Button button);

        void release(Button button);

        void click(Button button);

        void moveTo(int x, int y);
        void moveTo(Position& pos);

        Position getPos();
    }

    namespace Keyboard
    {
        struct Key
        {
            short keyValue;

            Key(char keyVal);
            Key(short keyVal);
        };

        namespace Keys
        {
            /*
            const Key a = Key('a'), b = Key('b'), c = Key('c'), d = Key('d'), e = Key('e'),
                f = Key('f'), g = Key('g'), h = Key('h'), i = Key('i'), j = Key('j'), 
                k = Key('k'), l = Key('l'), m = Key('m'), n = Key('n'), o = Key('o'),
                p = Key('p'), q = Key('q'), r = Key('r'), s = Key('s'), t = Key('t'),
                u = Key('u'), v = Key('v'), w = Key('w'), x = Key('x'), y = Key('y'),
                z = Key('z'); // ...
                */
            
            const Key tab = Key((short)VK_TAB), caps = Key((short)VK_CAPITAL), leftShift = Key((short)VK_LSHIFT),
                leftCtrl = Key((short)VK_LCONTROL), win = Key((short)VK_LWIN), alt = Key((short)VK_MENU), space = Key((short)VK_SPACE),
                rightCtrl = Key((short)VK_RCONTROL), rightShift = Key((short)VK_RSHIFT), enter = Key((short)VK_RETURN),
                backspace = Key((short)VK_BACK); // ...
        }

        void hold(Key key); // ERRO: NÃO TA SEGURANDO A TECLA! SÓ TA CLICANDO 1 VEZ!
        // void hold(char key);
        // void hold(short key);

        void release(Key key);
        // void release(char key);
        // void release(short key);

        void press(Key key);
        // void press(char key);
        // void press(short key);

        void write(const char* sentence);
        // void write(const char* sentence);

        // virtual void onPress(Key key);
    }
}
