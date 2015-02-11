#ifndef KEYBOARDINTERFACE_H
#define KEYBOARDINTERFACE_H


class Keyboardinterface
{
    public:

        // Public Struct to get Key's
        struct Key
        {
            char Key;
            int Scancode;
            bool Shift;
            bool Strg;
            bool Alt;
        };

        virtual bool readKey() = 0;         // Is a Key pressed?
        virtual Key getKey() = 0;           // Ok, get the Key

};

#endif // KEYBOARDINTERFACE_H
