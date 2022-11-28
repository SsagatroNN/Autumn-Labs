module sinegen#(
    parameter A_WIDTH = 8,
              D_WIDTH = 8
)(
    //signals
    input logic         clk,
    input logic         rst,
    input logic         en,
    input logic [D_WIDTH-1:0]  phase,
    output logic [D_WIDTH-1:0] dout0,
    output logic [D_WIDTH-1:0] dout1
);

    logic [A_WIDTH-1:0]     address0;
    logic [A_WIDTH-1:0]     address1;

counter addrCounter0 (
    .clk(clk),
    .rst (rst),
    .en (en),
    .count (address0)
);

counter addrCounter1 (
    .clk(clk),
    .rst (rst),
    .en (en),
    .count (address1)
);

rom sineRom (
    .clk (clk),
    .addr0 (address0),
    .addr1 (address1 + phase),
    .dout0 (dout0),
    .dout1 (dout1)
);

endmodule
