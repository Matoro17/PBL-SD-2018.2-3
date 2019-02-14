
`timescale 1ns / 1ps

module testeArbitro();

 parameter Halfcycle = 5; //half period is 5ns
    
 localparam Cycle = 2*Halfcycle;
 
 localparam loops = 50;
 
 	 

 
 
 //entradas
  reg [31:0]dataa;
  reg [7:0]rx;
  reg Clock;
  reg reset;
  reg enable;
  
 //wire saidas
  wire [7:0]tx;
  wire [31:0]result;
  wire done;
  wire estado123;
  
  reg count=0;
 
 	initial begin 
 
		Clock = 0; 
		dataa <= 32'b111;
		reset <= 1;
		reset <= 0;

	end

	always # 10 Clock = ~Clock;

	initial begin
		reset =1;
		#2;
		reset =0;
		dataa <= 32'b1;
		enable = 1;
		rx = 8'b0000_0000;#1;
		rx = 8'b0000_0000 ^ 8'b0011_0111;#1;
		enable =0;

 	end
 
	SM1 TESTE(.clock(Clock),
        .reset(reset),
		  .dataa(dataa),
		  .RX(rx),
		  .TX(tx),
		  .result(result),
		  .done(done),
		  .estado(estado123),
		  .enable(enable));

  always @(posedge Clock)begin
	
		if(tx==8'b1)begin
			enable =1;
			rx = 8'b0000_1111;
			rx = 8'b0000_1111 ^ 8'b0011_0111;
			enable =0;
			#10;
		end

  		dataa <= 32'b1; 
		dataa <= 32'b0;  
		enable = 1;#1;
  		rx = 8'b0000_0000;
		rx = 8'b0000_0000 ^ 8'b0011_0111;
		enable =0;
		
		if (done)begin
			if (result == 8'b0000_0000) begin
			$display("ALARME OK");
			end
			else if (result == 8'b0000_0100)begin
				$display("Sensor 1 - safe");
			end
			else if (result == 8'b0000_0111)begin
				$display("Sensor 2 - safe");
			end
			else if (result == 8'b0000_1100)begin
				$display("timeOut");
			end
			else
				$display("ALARME FAIL");
		end

  end


endmodule