#ifndef ALLEGRO_INPUT_H
#define ALLEGRO_INPUT_H

#include "Inputinterface.h"

class Allegro_Input: public Inputinterface
{
    public:
        Allegro_Input();
        ~Allegro_Input();

    // Keyboard
    bool readKey();
    Key getKey();

    // Mouse
    bool hasMousemoved();
    MousePosition getMousePosition();
    MouseButtonStatus getMouseButton();

    protected:
    private:
    void needPoll();

    bool firstMousePosition;
    MousePosition LastMousePosition;
};

#endif // ALLEGRO_INPUT_H
