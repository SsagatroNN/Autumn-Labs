#include <cstdlib>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "./vbuddy.cpp"
#include "Vlfsr.h"

int main(int argc, char **argv, char **env){

    Vlfsr * lfsr = new Vlfsr;

    if (!vbdOpen()){
        return EXIT_FAILURE;
    }

    //Assign initial input values
    lfsr->clk = 1;
    lfsr->en = 0;
    lfsr->rst = 0;

    for (int i = 0; i < 100000; i++){
        for (int tick = 0; tick < 2; tick++){
            lfsr->clk = !lfsr->clk;
            lfsr->eval();
        } 
        vbdCycle(i);

        vbdHex(1, lfsr->dout & 0xF);
        vbdBar(lfsr->dout & 0xFF);
        vbdSetMode(1);

        lfsr->en = vbdFlag();

        if (Verilated::gotFinish() || vbdGetkey() == 'q') exit(0);

    }
    vbdClose(); 
    exit(0);
}