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

    top->clk = 1;
    top->rst = 0;
    top->en = 1;
    top->ld = 1;
    

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
        
        // vbdPlot(int(top->count), 0, 255);
        vbdSetMode(1);
        vbdCycle(i+1);
        //----- end of vbuddy output section
        

        // if (top->en == 0){
        //     top->count = top->count - 1;
        // }

        // if (vbdFlag()){
        //     top->v = vbdValue();
        //     top->ld = 1;
        // }else {
        //     top->ld = 0;
        // }

        // top->en = vbdFlag();

        top->v = top->count;

        if (vbdFlag()){
            top->v = top->count + 1;
        }



        if (Verilated::gotFinish()) exit(0);

    }
    
    vbdClose();    //+++++++
    tfp->close();
    exit(0);
}

