#include "./obj_dir/Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env){
    //countes number of clock cycles

    int i;
    int clk;

    //intialize vconter

    // Vcounter* top = new Vcounter;
    Vtop *topmod = new Vtop;

    //turn on signal tracing

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    topmod->trace (tfp,99);
    tfp->open ("counter.vcd");

    //init vbuddy 
    if (vbdOpen() != 1) return (-1);
    vbdHeader("Lab 1: Counter");

    //intitialize simulation inputs

    topmod->clk = 1;
    topmod->rst = 0;
    topmod->en = 1;
    topmod->v = 0;
    

    //loop to run for many clock cycles:

    for( i = 0;i < 300; i++){
        for (clk = 0; clk < 2; clk++){
            tfp-> dump (2 * i + clk);
            topmod-> clk = !topmod-> clk;
            topmod-> eval ();
        }

        //+++++ send count value to vbuddy
        vbdHex(4, (int(topmod->bcd) >> 16) & 0xF);
        vbdHex(3, (int(topmod->bcd) >> 8) & 0xF);
        vbdHex(2, (int(topmod->bcd) >> 4) & 0xF);
        vbdHex(1, int(topmod->bcd) & 0xF);
        vbdCycle(i + 1);

    

        if (Verilated::gotFinish()) exit(0);

    }
    
    vbdClose();    //+++++++
    tfp->close();
    exit(0);
}

