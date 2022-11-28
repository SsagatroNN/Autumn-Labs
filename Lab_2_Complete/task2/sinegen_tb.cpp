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

    for(i = 0; i < 1000000; i++){

        for (clk = 0; clk < 2; clk++){
            tfp->dump (2 * i + clk);
            sinegenone->clk = !sinegenone->clk;
            sinegenone->eval ();
        }


        sinegenone->phase = (vbdValue()*1.27);
        //sinegenone->phase = vbdValue();

        //+++++ send count value to vbuddy
        vbdPlot(int(sinegenone->dout0), 0, 255);
        vbdPlot(int(sinegenone->dout1), 0, 255);
        vbdCycle( i + 1 );
        //----- end of vbuddy output section

        //adjust rst and en signals
        //with counting ssinegenoneping at a count of 9

        if (Verilated::gotFinish() || vbdGetkey() == 'q') exit(0);


    }

    vbdClose();    //+++++++
    tfp->close();
    exit(0);
}
