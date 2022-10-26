#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv, char **env){

	Verilated::commandArgs(argc, argv);
	//init top verilog instance
	Vcounter* top = new Vcounter;

	//init trace dump top-> (top*).trace(arg1, arg2)
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	top->trace(tfp, 99);
	tfp->open("counter.vcd");

	//initialize simulation inputs
	top->clk = 1;
	top->rst = 1;
	top->en = 0;

	//run simulation for many clock cycles
	int x = 0;
	for(int i = 0; i < 300; i++){

		//dump variables into VCD file and toggle clock
		for(int tick = 0; tick < 2; tick++){
			tfp->dump(2*i+tick);
			top->clk = !top->clk;
			top->eval();
		}

		top->rst = (i < 2) | (i == 18);
		top->en = (i > 4);

		if((top->count == 9) && (x < 3)){
			top->en = 0;
			x++;
		}

		if (Verilated::gotFinish()) exit(0);

	}

	tfp->close();
	exit(0);
}