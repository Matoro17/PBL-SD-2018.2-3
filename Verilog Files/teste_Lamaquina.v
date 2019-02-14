`timescale 1ns / 1ps

module teste_Lamaquina(); 
 
 //entradas
  reg [31:0]dataa;
  reg [7:0]rx;
  reg Clock;
  reg reset;
  reg enable;
  
 //wire saidas
  wire [7:0]tx;
  wire [7:0]result;
  wire done;
  
  reg count=0;
 
 	initial begin 
 
		Clock = 0; 
		dataa <= 32'b111;
		reset <= 1;
		reset <= 0;

	end

	always # 10 Clock = ~Clock;

	initial begin
		reset =1;#1;
		reset =0;
		dataa <= 32'b1;
        
		enable = 1;
        rx = 8'b0100;#1;
		rx = 8'b0000_0010;#1;
        rx = 8'b0000_0000 ^ 8'b0011_0111;
        enable =0;
        enable =1;
		enable =0;

 	end
 
	Lamaquina TESTE(.clk(Clock),
        .reset(reset),
		  .dataa(dataa),
		  .ReadUart(rx),
		  .SendUart(tx),
		  .result(result),
		  .done(done),
		  .enable(enable));

always @(posedge Clock)begin
        if(tx==8'b1)begin
            //enable = 1;#1;
            //rx = 8'b0000_1010;#1;
            //rx = 8'b0000_1010 ^ 8'b0011_0111;
            //enable =0;
        end
end

  always @(posedge Clock)begin

		if (done)begin
			if (result == 8'b0000_0000) begin
			$display("ALARME OK");
			end
			else if (result == 8'b0000_1010)begin
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