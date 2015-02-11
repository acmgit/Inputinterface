#ifndef MOUSEINTERFACE_H
#define MOUSEINTERFACE_H


class Mouseinterface
{
    public:
        struct MousePosition
        {
            int mouse_x;
            int mouse_y;
        };

        struct MouseButtonStatus
        {
            bool mouse_left;
            bool mouse_right;
        };

        virtual MousePosition getMousePosition() = 0;
        virtual MouseButtonStatus getMouseButton() = 0;

};

#endif // MOUSEINTERFACE_H
