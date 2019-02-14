// Quartus II Verilog Template
// 4-State Moore state machine

// A Moore machine's outputs are dependent only on the current state.
// The output is written only when the state changes.  (State
// transitions are synchronous.)

module Lamaquina
(
	input	clk, input [31:0]dataa, input reset, input enable, input rx,
	output reg [31:0] result, output reg tx, output reg done
);

	//reg [2:0] state = SEND_STATE;
	 reg rdy_clr;  // Limpar a entrada
	 wire rdy; //controle de leitura na uart
	 wire wr_en; // controle da escrita na uart
	 wire tx_busy;

  	uart uart_instance(.din(SendUart), .wr_en(wr_en), .clk_50m(clk), .tx(tx), .tx_busy(tx_busy), .rx(rx), .rdy(rdy), .rdy_clr(rdy_clr), .dout(ReadUart));

	reg [7:0]ReadUart;
	reg [7:0]SendUart;

	// Declare state register
	reg		[2:0]state;

	// Declare states
	parameter Idle=3'b000, Checksum=3'b001, TimeOut1=3'b010, SendBack=3'b011, TryAlarm=3'b100, Alarm=3'b101, Timer=3'b110;

	//Parameters para o funcionamento da maquina
	integer tempo = 0;
   integer timer2 = 0;
   integer timer3 = 0;

   parameter integer temp = 10000;
   parameter integer temp2 = 3;

   reg [7:0] firstbyte = 8'b1000_0000;
   reg [7:0] secondbyte = 8'b1000_0000;
   reg [7:0] checkdado;
	
	reg [31:0]dataa_old;
	reg [7:0]ReadUart_old;
	
	reg countbyte = 0; 
   	reg countSend = 0;

	// Output depends only on the state
	always @ (state) begin
		case (state)
			Idle:begin
				done <= 0;
			end
			Checksum:begin
			end
			TimeOut1:begin
				result <= 4'b110;
				done <= 1;
			end
			SendBack:begin
				result <= firstbyte;
				done <= 1;
			end
			TryAlarm:begin
				if(timer3 >= temp2)begin
					result <= 4'b1011; //CODIGO PARA BUG NO BUFFER
					done <= 1'b1;
				end
			end
			Alarm:begin
				SendUart = 8'b000;
				result = 3'b000;
				done = 1;
			end
			Timer:begin
				if (tempo >= temp)begin
					countSend = 0;
				end
				else if (((enable && dataa != dataa_old) && (tempo < temp)))begin
					if (countbyte == 1)begin
						countSend =0;
					end
				end
				if(countSend == 0)begin
						SendUart = dataa[7:0];// CODIGO DE REQUISIÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¢O VINDA DO NIOS
						wr_en = 1;
						countSend = 1;
				end 
				else if (countSend == 1)begin
					wr_en = 0;
				end
			end
		endcase
	end

	// Determine the next state
	always @ (posedge clk or posedge reset) begin
		if (reset)begin
			state <= Idle;
		end
		else
			case (state)
				Idle:begin
					//$display("Idle");
					//$display("Readuart: %b", ReadUart);
					//$display("ReadUart_old: %b", ReadUart_old);
					if (dataa != dataa_old)begin// Se tiver algo na requisiao va para o timer
						state <= Timer;
						$display("Chegou coisa nova no dataa");
					end
					else if (enable && ReadUart != ReadUart_old)begin// Se tiver algo vindo da UART va para o checksum
						state <= Checksum;
						$display("Enable ligado foi pro checksum");
					end
					else
						state <= Idle; 
				end
				Checksum:begin
					$display ("CheckSum");
					checkdado = firstbyte ^ 8'b0011_0111;

					if (checkdado == secondbyte && firstbyte != 8'b0000_0000)begin // Se o dado estiver correto e for um dado requisitado, va para send back
						state <= SendBack;
						$display("Checksum deu certo!");
					end
					else if (checkdado != secondbyte)begin// Se o dado vier "corrompido" va para o teste de alarme
						state <= TryAlarm;
						$display("Checksum deu errado");
					end
					else if (checkdado == secondbyte && firstbyte == 8'b0000_0000)// Se o dado estiver correto e for o alarme va para alarme
						state <= Alarm;
					else
						state <= Idle;
				end
				TimeOut1:begin
					$display("TimeOut1");
					state <= Idle;
				end
				SendBack:begin
					$display ("SendBack");
            		state <= Idle;
				end
				TryAlarm:begin
					$display ("TryAlarm");
					if (enable && dataa != dataa_old)// Se ainda estiver em tempo, e receber algo na UART va para o checksum
						begin
							state <= Checksum;
						end
					else if (timer3 >= temp2)// Caso o tempo estoure va para o idle e grave um "bug" no buffer
						begin
							$display("estourou bug timer");
							state <= TimeOut1;
							timer3 = 0;
						end
					else
						begin
							timer3 = timer3 + 1;
							state <= TryAlarm;
						end
				end
				Alarm:begin
					$display ("Alarm");
					state <= Idle;
				end
				Timer:begin
					//$display ("Timer");
					
					if ((tempo >= temp))begin
							SendUart <=8'bx;
							state <= TimeOut1;
							tempo = 0;
					end
					else if ((( ReadUart != ReadUart_old) && (tempo < temp)))begin
						$display("CountByte: %b", countbyte);
						if (countbyte == 0)begin
							$display("if do firstbyte = %b", countbyte);
							$display("firstbute antes: %b",firstbyte);
							firstbyte <= ReadUart;
							$display("firstbute depois: %b",firstbyte);
							countbyte <= 1;
							state <= Timer;
						end
						else if (countbyte == 1)begin
							$display("if do secondbyte, count = %b", countbyte);
							$display("secondbyte antes: %b",secondbyte);
							secondbyte <= ReadUart;
							$display("secondbyte antes: %b",secondbyte);
							countbyte <= 1'b0;
							state <= Checksum;
							SendUart <=8'bx;
						end
						//$display ("RecevUart: %b",ReadUart);
						$display ("Firstbyte: %b",firstbyte);
						$display ("secondbyte: %b",secondbyte);
					end
					// Inserting 'else' block to prevent latch inference
					else begin
						tempo <= tempo + 1;
						state <= Timer;
					end
					
				end
			endcase
		dataa_old <= dataa;
		ReadUart_old <= ReadUart;
	end

endmodule
