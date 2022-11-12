module lfsr(
    input logic rst,
    input logic en,
    input logic clk,
    output logic [6:0] dout 
);

    logic [6:0] sreg = 7'b1;
    
    assign dout = sreg;

    always_ff @(posedge clk) begin
        if (rst)
            sreg <= 4'b1;
        
        else if(en)
            sreg <= {sreg[5:0], sreg[6] ^ sreg[2]};
    
    end

endmodule
