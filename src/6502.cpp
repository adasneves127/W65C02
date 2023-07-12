#include "6502.h"



W65C02::W65C02(void (*update)()){
    this->update = update;
    
    doReset();


    printf("%i", status_reg);
}

void W65C02::doReset(){
    PCL = readMem(0xFFFC);
    PCH = readMem(0xFFFD);
    status_reg = 0b00110100;
}



void W65C02::clock(){
    if(BE & ~RDY){
        fetch();
        decode();
        execute();
        store();
    }
}


void W65C02::fetch(){
    this->IR = nextMem();
    
}

void W65C02::decode(){}

void W65C02::execute(){}

void W65C02::store(){}


__uint8_t W65C02::readMem(__uint16_t addr){
    this->output_pins |= 0b000100;      // Set the 'RWB' bit

    addressBus = (PCH << 8) | PCL;      // Set the address bus

    this->update();                     // Request a system update

    __uint8_t data = dataBus;           // Get the new data from the bus

    this->output_pins &= 0b111011;      // Clear the RWB bit

    return data;                        // Return the data
}


W65C02::~W65C02(){

}

void W65C02::invalid_opcode(){
    printf("Invalid Opcode %2x", this->IR);
}


void W65C02::inc_pc(){
    PCL++;              // Increment the lower half of the PC
    if(PCL == 0){       // If we roll over to 0
        PCH++;          // Increment the upper portion.
    }
}

__uint8_t W65C02::nextMem(){
    __uint8_t data = readMem((PCH << 8) | PCL);
    inc_pc();
    return data;
}