#include <cstdio>

class W65C02 {
    public:
        W65C02();
        ~W65C02();

        void doReset();

        __uint8_t dataBus;
        __uint16_t addressBus;

        void clock();

    private:
        __uint8_t A, X, Y;
        __uint8_t *pA, *pX, *pY;
        

        __uint8_t IR = 0;

        __uint8_t PCL, PCH;
        __uint8_t SP;

        __uint8_t status_reg;
};