module sinegen#(
    parameter A_WIDTH = 8;
              D_WIDTH = 8;
)(
    input logic         clk,
    input logic         rst,
    input logic         en,
    input logic [D_WIDTH-1:0] incr,
    output logic [D_WIDTH-1:0] dout
);

    logic [A_WIDTH-1:0]     address;

counter addrCounter (
    .clk(clk),
    .rst (rst),
    .en (en),
    .incr (incr),
    .count (address)
);

rom sineRom (
    .clk (clk),
    .addr (address),
    .dout (dout)
);

endmodule
