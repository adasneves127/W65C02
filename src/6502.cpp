#include "6502.h"


W65C02::W65C02(byte (*read)(word), void (*write)(word, byte)){
    this->readMem = read;
    this->writeMem = write;
}


s64 W65C02::doInstruction(){
    switch(this->readMem(PC++)) {
        
    }
}

s64 W65C02::executeCycles(s64 cyclesRequested){
    s64 cyclesExecuted = 0;
    while(cyclesExecuted < cyclesRequested){
        byte currentCycleCount = doInstruction();
        if(currentCycleCount == 0) break;
        cyclesExecuted += currentCycleCount;
    }

    return cyclesRequested - cyclesExecuted;
}