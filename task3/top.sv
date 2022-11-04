module top #(
    parameter WIDTH = 16
) (
    input logic clk,
    input logic en, 
    input logic rst,
    input logic [WIDTH-1:0] N,
    output logic tick,
    output logic [7:0] dout

);
    
clktick clktickr(
    .clk(clk),
    .en(en),
    .N(N),
    .rst(rst),
    .tick(tick)
);

f1fsm fsm(
    .en(tick),
    .clk(clk),
    .rst(rst),
    .dout(dout)
);

    
endmodule
