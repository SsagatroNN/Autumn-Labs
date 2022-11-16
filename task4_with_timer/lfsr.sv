module lfsr(
    input logic rst,
    input logic en,
    input logic clk,
    output logic [7:0] dout 
);

    logic [7:0] sreg = 8'b1;
    
    assign dout = sreg;

    always_ff @(posedge clk) begin
        if (rst)
            sreg <= 8'b1;
        
        else if(en)
            sreg <= {sreg[6:0], sreg[7] ^ sreg[6] ^ sreg[1] ^ sreg[0]};
    
    end

endmodule
