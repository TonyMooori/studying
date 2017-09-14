module addbit(
	a,
	b,
	ci,
	sum,
	co
);

input a;
input b;
input ci;

output sum;
output co;

wire a,b,ci,sum,co;

assign{co,sum}=a+b+ci;

endmodule
/*

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
*/
