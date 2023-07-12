#include <cstdio>


#define NMI (input_pins)      & 1
#define RDY (input_pins >> 1) & 1
#define SOB (input_pins >> 2) & 1
#define RST (input_pins >> 3) & 1
#define BE  (input_pins >> 4) & 1
#define IRQ (input_pins >> 5) & 1


#define s_Carry     status_reg |= 0b00000001;
#define s_Zero      status_reg |= 0b00000010;
#define s_iDis      status_reg |= 0b00000100;
#define s_Dec       status_reg |= 0b00001000;
#define s_Over      status_reg |= 0b01000000;
#define s_Neg       status_reg |= 0b10000000;


#define c_Carry     status_reg &= 0b11111110;
#define c_Zero      status_reg &= 0b11111101;
#define c_iDis      status_reg &= 0b11111011;
#define c_Dec       status_reg &= 0b11110111;
#define c_Over      status_reg &= 0b10111111;
#define c_Neg       status_reg &= 0b01111111;

#define g_Carry     (status_reg >> 1)   & 1
#define g_Zero      (status_reg >> 2)   & 1
#define g_iDis      (status_reg >> 4)   & 1
#define g_Dec       (status_reg >> 8)   & 1
#define g_Over      (status_reg >> 64)  & 1
#define g_Neg       (status_reg >> 128) & 1


class W65C02 {
    public:
        W65C02(void (*update)());
        ~W65C02();

        void doReset();

        __uint8_t dataBus;
        __uint16_t addressBus;

        void clock();

        __uint8_t output_pins, input_pins;
    private:
        __uint8_t A, X, Y;
        __uint8_t *pA, *pX, *pY;
        

        __uint8_t IR = 0;

        __uint8_t PCL, PCH;
        __uint8_t SP;

        __uint8_t status_reg;

        __uint8_t readMem(__uint16_t addr);
        void writeMem(__uint16_t addr, __uint8_t data);


        void (*update)();

        void push(__uint8_t);
        __uint8_t pop();


        void invalid_opcode();

        void fetch(), decode(), execute(), store();


        __uint8_t nextMem();

        void inc_pc();
};