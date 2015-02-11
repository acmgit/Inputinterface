#include <iostream>

#include "Allegro_Input.h"
#include "allegro.h"

using namespace std;

int main()
{

    allegro_init();

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0)
    {
        cout << "Couldn't set graphic mode!" << endl;
        return false;
    }

    Allegro_Input MyInput;

    enable_hardware_cursor();

    MyInput.readKey();
    Allegro_Input::Key MyKey;
    MyKey = MyInput.getKey();

    cout << endl;


    Allegro_Input::MouseButtonStatus ButtonTest;
    ButtonTest = MyInput.getMouseButton();

    cout << endl;

    MyInput.hasMousemoved();

    cout << endl;

    return 0;
}

END_OF_MAIN()
