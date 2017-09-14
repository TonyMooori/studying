
module AND2TEST;

reg a,b;
wire out;

AND2 bbb(a,b,out);

initial begin
    $dumpfile("and2test.vcd");
    $dumpvars(0,AND2TEST);
    $monitor("%t:a=%b,b=%b,out=%b",$time,a,b,out);
    
    a = 0; b = 0;
    #10 a = 1;
    #10 a = 0; b = 1;
    #10 a = 1;
    #10 a = 0; b = 0;
    #10 $finish;
end

endmodule

module AND2(A,B,X);

input A,B;
output X;

    and AAA(X,A,B);

endmodule
