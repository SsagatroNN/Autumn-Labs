#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"
#include <iostream>

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 100000

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges
  int lights = 0; // state to toggle LED lights

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vtop * top = new Vtop;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("top.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L3T4:F1 Game");
  vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation inputs
  top->clk = 1;
  top->rst = 0;
  top->en = 0;
  top->N = vbdValue();
  int x = 0;
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }
    vbdCycle(simcyc);
    
    top->trigger = vbdFlag(); 
    vbdBar(top->dout);
    top->rst = (simcyc < 2);
    top->en = (simcyc > 2);
    top->N = vbdValue();

    
    if (top->dout + x == 255){
      vbdInitWatch();
    }

    if(top->trigger == 1){
      int time = vbdElapsed();
      vbdHex(4, (int(time) >> 16) & 0xF);
      vbdHex(3, (int(time) >> 8) & 0xF);
      vbdHex(2, (int(time) >> 4) & 0xF);
      vbdHex(1, int(time) & 0xF);
    }

    x = top->dout;

    if (Verilated::gotFinish())  exit(0);
  }

  vbdClose();
  tfp->close(); 
  exit(0);
}
