module sigdelay#(
    parameter A_WIDTH = 9,
              D_WIDTH
)(
    input logic         clk,
    input logic         rst,
    input logic         en,
    input logic         wr,
    input logic         rd,
    input logic [A_WIDTH-1:0] offset,
    input logic [D_WIDTH-1:0] mic_signal,
    output logic [D_WIDTH-1:0] delayed_signal
);

logic [A_WIDTH-1:0]  readAddress;
logic [A_WIDTH-1:0]  writeAddress;


counter wAddrCounter(
    .clk(clk),
    .rst (rst),
    .en (en),
    .count (writeAddress)
);

counter rAddrCounter(
    .clk(clk),
    .rst (rst),
    .en (en),
    .count (readAddress)
);

rom dualPortRom(
    .clk(clk),
    .wr(wr),
    .rd(rd),
    .mic_signal(mic_signal),
    .offset(offset),
    .addr0(readAddress),
    .addr1(writeAddress),
    .dout(delayed_signal)
);

endmodule
