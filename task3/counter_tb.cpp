//mandatory header files used for all c++ files

#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env){
    //countes number of clock cycles

    int i;
    int clk;

    //intialize vconter

    Vcounter* top = new Vcounter;

    //turn on signal tracing

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp,99);
    tfp->open ("counter.vcd");

    //init vbuddy 
    if (vbdOpen() != 1) return (-1);
    vbdHeader("Lab 1: Counter");

    //intitialize simulation inputs

    top->clk =1;
    top->rst=0;
    

    //loop to run for many clock cycles:

    for(i=0;i<300;i++){
        for (clk=0;clk<2;clk++){
            tfp->dump (2*i+clk);
            top->clk = !top->clk;
            top->eval ();
        }

        //+++++ send count value to vbuddy
        vbdHex(4, (int(top->count) >> 16) & 0xF);
        vbdHex(3, (int(top->count) >> 8) & 0xF);
        vbdHex(2, (int(top->count) >> 4) & 0xF);
        vbdHex(1, int(top->count) & 0xF);
        vbdCycle(i+1);
        //----- end of vbuddy output section
        top->en = vbdFlag();

        if (top->en == 0){
            top->count = top->count - 1;
        }
        
        //adjust rst and en signals
        //with counting stopping at a count of 9

        // top->rst = (i<2) | (i==19);
        // top->en = ((14>i) && (i>=5)) || i > 15 ;
        if (Verilated::gotFinish()) exit(0);

    }

    vbdClose();    //+++++++
    tfp->close();
    exit(0);
}

