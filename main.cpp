#include <iostream>

#include "Allegro_Input.h"
#include "allegro.h"

using namespace std;

int main()
{

    allegro_init();
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0)
    {
        allegro_message("Couldn't set graphic mode!");
        //cout << "Couldn't set graphic mode!" << endl;
        return false;

    } // if set_gfx_mode

    Allegro_Input MyInput;

    MyInput.readKey();
    Allegro_Input::Key MyKey;
    MyKey = MyInput.getKey();
    cout << endl;

    Allegro_Input::MouseButtonStatus ButtonTest;
    ButtonTest = MyInput.getMouseButton();
    cout << endl;

    MyInput.hasMousemoved();
    cout << endl;

    int Len = 4;
    cout << "GetString .... (" << Len << " Char's)" << endl << endl;

    std::string MyString;
    MyString = MyInput.inputString(Len);
    cout << "Eingegebener String: " << MyString << endl;

    return 0;

} // main

END_OF_MAIN()
