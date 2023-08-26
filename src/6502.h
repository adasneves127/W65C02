#include <stdlib.h>

using word = __uint16_t;
using byte = __uint8_t;
using s64 = __int64_t;

class W65C02{
    public:
        /// @brief Initializes a new 6502 CPU
        /// @param read Function Pointer to read function from memory
        /// @param write Function Pointer to write function in memory
        W65C02(byte (*read)(word), void (*write)(word, byte));

    private:
        /// @brief Accumulator
        byte A; 
        /// @brief X Register
        byte X;
        /// @brief Y Register
        byte Y; 
        /// @brief Carry Flag
        byte C;
        /// @brief Zero Flag
        byte Z;
        /// @brief Interrupt Disable
        byte I;
        /// @brief Decimal Mode
        byte D;
        /// @brief Break flag
        byte B;
        /// @brief Overflow Flag
        byte O;
        /// @brief Negative Flag
        byte N;
        /// @brief System Stack Pointer
        byte SP;
        /// @brief System Program Counter
        word PC;

        /// @brief Write into Memory. Function provided upon initialization.
        void (*writeMem)(word, byte);
        /// @brief Read from memory. Function provided upon initialization.
        byte (*readMem)(word);

        /// @brief Executes the next instruction in memory
        /// @return The number of cycles it took to execute.
        s64 doInstruction();
        /// @brief Executes a set number of cycles
        /// @param cyclesRequested The number of cycles to be executed
        /// @return The difference in cycles requested, vs executed.
        s64 executeCycles(s64 cyclesRequested);

        // Instruction Definitions
        static constexpr byte
        LDA_IMM = 0xA9,
        LDA_ZPG = 0xA5,
        LDA_ZPX = 0xB5,
        LDA_ABS = 0xAD,
        LDA_ABX = 0xBD,
        LDA_ABY = 0xB9,
        LDA_INY = 0xA1,
        LDA_INY = 0xB1
        ;

};