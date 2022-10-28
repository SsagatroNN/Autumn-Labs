//mandatory header files used for all c++ files

#include "Vsinegen.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env){
    //countes number of clock cycles

    int i;
    int clk;

    //intialize vconter

    Vsinegen * sinegenone = new Vsinegen;

    //turn on signal tracing

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    sinegenone->trace (tfp,99);
    tfp->open ("counter.vcd");

    //init vbuddy 
    if (vbdOpen() != 1) return (-1);
    vbdHeader("Lab 1: Counter");

    //intitialize simulation inputs

    sinegenone->clk = 1;
    sinegenone->rst = 0;
    sinegenone->en = 1;

    //loop to run for many clock cycles:

    for(i = 0; i < 300; i++){

        for (clk = 0; clk < 2; clk++){
            tfp->dump (2 * i + clk);
            sinegenone->clk = !sinegenone->clk;
            sinegenone->eval ();
        }

        vbdPlot();
        vbdCycle( i + 1);

        if (Verilated::gotFinish() ||  ) exit(0);

    }

    vbdClose();    //+++++++
    tfp->close();
    exit(0);
}
