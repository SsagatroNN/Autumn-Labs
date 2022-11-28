module f1fsm(
    input logic clk,
    input logic en, 
    input logic rst,
    input logic trigger,
    output logic [7:0] dout,
    output logic cmd_delay,
    output logic cmd_seq    
);

    logic [7:0] num = 8'b0;
    
    typedef enum {IDLE, S0, S1, S2, S3, S4, S5, S6, S7} light_state;
    light_state current_state, next_state;

    // assign current_state = IDLE;

    always_ff @(posedge clk) begin
        if (rst) current_state <= IDLE;
        
        if (current_state == IDLE) begin
            if (trigger) current_state <= next_state;
        end
        
        else begin
            if (en) current_state <= next_state;
            else current_state <= current_state;
        end

    end

    always_comb begin
        case (current_state)
        IDLE:   next_state = S0;
        S0:     next_state = S1;
        S1:     next_state = S2;
        S2:     next_state = S3;     
        S3:     next_state = S4;
        S4:     next_state = S5;
        S5:     next_state = S6;
        S6:     next_state = S7;
        S7:     next_state = IDLE;        
        endcase    
    end

    always_comb begin
        case(current_state)
                IDLE:   begin 
                        num = 8'b0;
                        cmd_delay = 1'b0;
                        cmd_seq = 1'b0;
                end
                
                S0:     begin 
                        num = 8'b1;
                        cmd_seq = 1'b1;
                end
                S1:     num = 8'b11;     
                S2:     num = 8'b111;     
                S3:     num = 8'b1111;
                S4:     num = 8'b11111;
                S5:     num = 8'b111111;
                S6:     num = 8'b1111111;
                S7:     begin
                        num = 8'b11111111;
                        cmd_delay = 1'b1;
                        cmd_seq = 1'b0;
                end
        endcase
    end

    assign dout = num;

endmodule
