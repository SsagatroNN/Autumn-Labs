module rom #(
    parameter   ADDRESS_WIDTH = 8,
                DATA_WIDTH = 8

    )(
        input logic                     clk,
        input logic [ADDRESS_WIDTH-1:0] addr0,
        input logic [ADDRESS_WIDTH-1:0] addr1,
        output logic [DATA_WIDTH-1:0]   dout0,
        output logic [DATA_WIDTH-1:0]   dout1
    );

    logic [DATA_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];

    initial begin 
        $display("Loading rom.");
        $readmemh("sinerom.mem", rom_array);
    end;

    always_ff @(posedge clk) 
        begin 
    // output is synchronus 
        dout0 <= rom_array [addr0];
        dout1 <= rom_array [addr1];
        end;

endmodule
