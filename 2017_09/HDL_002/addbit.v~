module d_ff(d,clk,q,q_bar);

input d,clk;
output q,q_bar;

wire d,clk;
reg q,q_bar;

always @ (posedge clk)
begin
    q <= d;
    q_bar <= !d;
end

endmodule


module test;

reg d_in,c;
wire out1,out2;

d_ff ff_test(d_in,c,out1,out2);

initial begin
    $dumpfile("ff_test.vcd");
    $dumpvars(0,test);
    
    d_in = 0; c = 0;
    #10 d_in = 0; c = 1;
    #10 d_in = 0; c = 0;
    #10 d_in = 1; c = 1;
    #10 d_in = 1; c = 0;
    #10 d_in = 1; c = 1;
    #10 d_in = 1; c = 0;
    #10 d_in = 0; c = 1;
    #10 d_in = 0; c = 0;
end

endmodule
