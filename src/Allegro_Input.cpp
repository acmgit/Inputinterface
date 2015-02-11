#ifndef ALLEGRO_INPUT_CPP
#define ALLEGRO_INPUT_CPP

#include "Allegro_Input.h"
#include <iostream>
#include <allegro.h>

Allegro_Input::Allegro_Input()
{
    install_keyboard();
    install_mouse();
    install_timer();
    firstMousePosition = false;

    enable_hardware_cursor();
    show_os_cursor(MOUSE_CURSOR_ARROW);
}

Allegro_Input::~Allegro_Input()
{
    //dtor
    remove_keyboard();
    remove_mouse();
}

Allegro_Input::Key Allegro_Input::getKey()
{
    Allegro_Input::Key Test;
    int myKey;
    myKey = readkey();

    Test.Key = (char) myKey;
    Test.Scancode = myKey >> 8;
    Test.Strg = false;
    Test.Alt = false;
    Test.Shift = false;

    std::cout << "Es steht die Taste " << Test.Key << " im Tastaturpuffer." << std::endl;
    std::cout << "Mit dem Scancode " << Test.Scancode << "." << std::endl;

    return Test;
}

bool Allegro_Input::readKey()
{
    int myKey;
    myKey = keypressed();

    if(myKey)
    {
        std::cout << "Es wurde eine Taste gedrückt ..." << std::endl;
        return true;
    }
    else
    {
        std::cout << "Es wurde keine Taste gedrückt ..." << std::endl;
        return false;
    }

}

bool Allegro_Input::hasMousemoved()
{
    needPoll();
    if(firstMousePosition == false)
    {
        firstMousePosition = true;
        LastMousePosition = getMousePosition();

        std::cout << "Die Maus hat ihre Position nicht verändert ..." << std::endl;
        return false;
    }

    MousePosition MyMousePosition = getMousePosition();

    if((MyMousePosition.mouse_x == LastMousePosition.mouse_x) && (MyMousePosition.mouse_y == LastMousePosition.mouse_y))
    {
        std::cout << "Die Maus hat ihre Position nicht verändert ..." << std::endl;
        return false;
    }
    else
    {
        std::cout << "Die Maus hat ihre Position verändert ..." << std::endl;
        return true;
    }

}

Allegro_Input::MouseButtonStatus Allegro_Input::getMouseButton()
{
    needPoll();

    Allegro_Input::MouseButtonStatus Test;

    Test.mouse_left = mouse_b & 1;
    Test.mouse_right = mouse_b & 2;

    if(Test.mouse_left)
    {
        std::cout << "Die linke Maustaste ist gedrückt ..." << std::endl;
    }
    else
    {
        std::cout << "Die linke Maustaste ist nicht gedrückt ..." << std::endl;
    }

    if(Test.mouse_right)
    {
        std::cout << "Die rechte Maustaste ist gedrückt ..." << std::endl;
    }
    else
    {
        std::cout << "Die rechte Maustaste ist nicht gedrückt ..." << std::endl;
    }

    return Test;
}

Allegro_Input::MousePosition Allegro_Input::getMousePosition()
{
    needPoll();

    Allegro_Input::MousePosition Test;

    Test.mouse_x = mouse_pos >> 16;
    Test.mouse_y = mouse_pos & 0x0000ffff;

    std::cout << "Die Maus steht an Position X = " << Test.mouse_x << " und Position Y = " << Test.mouse_y << " ..." << std::endl;

    return Test;
}

void Allegro_Input::needPoll()
{
    if(mouse_needs_poll())
    {
        poll_mouse();
    }

    if(keyboard_needs_poll())
    {
        poll_keyboard();
    }
}
#endif // ALLEGRO_INPUT_CPP
