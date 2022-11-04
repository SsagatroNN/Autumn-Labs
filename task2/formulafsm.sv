module formulafsm (
    input logic clk,
    input logic en, 
    output logic [7:0] dout
);

    logic [7:0] num = 8'b0;
    assign dout = num;

    always_ff @(posedge clk)
        if (en)
            if (num == 8'hff)
                num <= 8'b0;

            else
                num <= {{num[6:0]}, en};
        else 
            num <= num;
        
        // if (num == 8'hff & en)
        //     num <= 8'b0;
        // else
        //     num <= en ? {{num[6:0]}, en} : num;
   
endmodule
