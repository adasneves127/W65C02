#include "6502.h"


W65C02::W65C02(){
    
    
    doReset();
}

void W65C02::doReset(){
    PCL = read_mem(0xFFFC);
    PCH = read_mem(0xFFFD);
    status_reg = 0b00110100;
}



void W65C02::clock(){
    
}

