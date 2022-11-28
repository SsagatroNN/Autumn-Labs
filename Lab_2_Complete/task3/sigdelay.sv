module sigdelay#(
    parameter A_WIDTH = 9,
              D_WIDTH = 8
)(
    input logic         clk,
    input logic         rst,
    input logic         wr,
    input logic         rd,
    input logic [A_WIDTH-1:0] offset,
    input logic [D_WIDTH-1:0] mic_signal,
    output logic [D_WIDTH-1:0] delayed_signal
);

logic [A_WIDTH-1:0]  readAddress = 9'b0;
logic [A_WIDTH-1:0]  writeAddress = readAddress + offset;


counter wAddrCounter(
    .clk(clk),
    .rst (rst),
    .en (1),
    .count (writeAddress)
);

counter rAddrCounter(
    .clk(clk),
    .rst (rst),
    .en (1),
    .count (readAddress)
);

ram dualPortRam(
    .clk(clk),
    .wr(wr),
    .rd(rd),
    .mic_signal(mic_signal),
    .addr0(readAddress),
    .addr1(writeAddress),
    .dout(delayed_signal)
);

endmodule
