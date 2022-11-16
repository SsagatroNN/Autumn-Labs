module top #(
    parameter WIDTH = 8
) (
    input logic clk,
    input logic en, 
    input logic rst,
    input logic [WIDTH-1:0] N,
    input logic trigger,
    output logic [7:0] dout,
    output logic cmd_seq,
    output logic cmd_delay,
    output logic [WIDTH-1:0] n
);

logic delay;
logic mtick;
logic muxout;
assign muxout = cmd_seq ? mtick : delay;


clktick clktickr(
    .clk(clk),
    .en(cmd_seq),
    .N(N),
    .rst(rst),
    .tick(mtick)//output
);

lfsr randomdelayer(
    .clk(clk),
    .en(en),
    .rst(rst),
    .dout(n) //output
);

delay delayer(
    .n(n),
    .clk(clk),
    .rst(rst),
    .trigger(cmd_delay),
    .time_out(delay) //output
);

f1fsm f1fsm(
    .en(muxout),
    .clk(clk),
    .rst(rst),
    .trigger(trigger),
    .dout(dout),
    .cmd_delay(cmd_delay),
    .cmd_seq(cmd_seq)
);

  
endmodule
