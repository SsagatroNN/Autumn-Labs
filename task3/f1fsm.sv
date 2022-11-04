module f1fsm(
    input logic en, 
    input logic clk, 
    input logic rst, 
    output logic [7:0] dout
);

    logic [7:0] num = 8'b0;
    assign dout = num;

    always_ff @(posedge clk) begin
    
    if (rst)
        num <= 8'b0;

    if (en)
        if (num == 8'hff)
            num <= 8'b0;

        else
            num <= {{num[6:0]}, en};
    else 
        num <= num;
    
    end

endmodule
