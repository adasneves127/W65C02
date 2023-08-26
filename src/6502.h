#include <stdlib.h>

using word = __uint16_t;
using byte = __uint8_t;

class W65C02{
    public:
        W65C02(void (*read)(word, byte), byte (*write)(word, byte));

    private:
        byte A, X, Y, C, Z, I, D, B, O, N, SP;
        word PC;

        void (*writeMem)(word, byte);
        byte (*readMem)(word);

        // Instruction Definitions

};