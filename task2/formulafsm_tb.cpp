#include <cstdlib>
#include <verilated.h>
#include <Vformulafsm.h>
#include "vbuddy.cpp"


int main(int argc, char **argv, char **env){
    
    Verilated::commandArgs(argc, argv);
    
    Vformulafsm *top = new Vformulafsm;

    if (!vbdOpen()){
        return EXIT_FAILURE;
    }

    top->clk = 1;


    for (int i = 0; i < 100000; i++){
        for (int tick = 0; tick < 2; tick++){
            top->clk = !top->clk;
            top->eval();
        }
        
        vbdSetMode(1);
        top->en = vbdFlag();
        vbdCycle(i);

        vbdBar(top->dout & 0xFF);
        // vbdHex(int(top->dout), 1);
        // vbdHex(int(top->dout), 2);        
        // vbdHex(int(top->dout), 3);
        // vbdHex(int(top->dout), 4);
        
        if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
            exit(0);

        }
    
vbdClose();
exit(0);
}