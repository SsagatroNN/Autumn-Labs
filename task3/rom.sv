module rom #(
    parameter   ADDRESS_WIDTH = 9,
                DATA_WIDTH = 8

    )(
        input logic                     clk,
        input logic                     wr,
        input logic                     rd,
        input logic [DATA_WIDTH-1:0]    mic_signal,
        input logic [ADDRESS_WIDTH-1:0] offset,
        input logic [ADDRESS_WIDTH-1:0] addr0, // read
        input logic [ADDRESS_WIDTH-1:0] addr1, // write
        output logic [DATA_WIDTH-1:0]   dout0
    );

    logic [DATA_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];

    always_ff @(posedge clk) 

    if (wr == 1){
        (rom_array[addr1] <= mic_signal)

    }
    
    dout0 <= '1b0';

endmodule
