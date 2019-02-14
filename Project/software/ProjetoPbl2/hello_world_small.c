#include "sys/alt_stdio.h"
#include <stdio.h>
#include <system.h>
#include <altera_avalon_pio_regs.h>
#include "altera_avalon_uart_regs.h"
#define LCD_WR_COMMAND_REG 0x0
#define LCD_WR_DATA_REG 0x1
char button_value = 3;
#define UP_BUTTON 1
#define DOWN_BUTTON 2

/*
 * Função para enviar os caracteres através o TX (transmissor)
 * */
void write_uart(int tamanho, char *comando)
{
	int i;
    unsigned long status = 0;

    // Verifica até que seja possível a transmissão de dados
    while((status & 0x00000040) != 0x00000040)
    {
        status = IORD_ALTERA_AVALON_UART_STATUS(UART_1_BASE);
    }

    for (i = 0; i < tamanho; i++) {
    	IOWR_ALTERA_AVALON_UART_TXDATA(UART_1_BASE, comando[i]);
    	usleep(1000);
    }
    IOWR_ALTERA_AVALON_UART_TXDATA(UART_1_BASE, '\r');
    usleep(1000);
    IOWR_ALTERA_AVALON_UART_TXDATA(UART_1_BASE, '\n');

}

/*
 * Função para enviar os caracteres através o TX (transmissor)
 * */
void write_uart_quick(char comando)
{
	int i;
	unsigned long status = 0;
	//printf("COMANDO: %c", comando);

    // Verifica até que seja possível a transmissão de dados
    while((status & 0x00000040) != 0x00000040)
    {
        status = IORD_ALTERA_AVALON_UART_STATUS(UART_1_BASE);
    }

	IOWR_ALTERA_AVALON_UART_TXDATA(UART_1_BASE, comando);
	usleep(1000);

}

/*
 * Função para receber os caracteres através o rx (receptor)
 * */
char read_uart()
{
	char data;

	while(1){
    	// Verifica se possui dados para serem lidos
    	if(IORD_ALTERA_AVALON_UART_STATUS( UART_1_BASE ) & 0x80 ) {
    		data = IORD_ALTERA_AVALON_UART_RXDATA( UART_1_BASE );
	        printf("%c",data);

	        if(data == 'K'){
	        	break;
	        }
    	}
	}
}

/*
 * Função para selecionar (acender) o LED corretamente através da opção
 */
void acenderLeds(int opcao, int nivelLogico) {
	if (opcao == 1) {
		IOWR_ALTERA_AVALON_PIO_DATA(LED1_BASE, nivelLogico);
	} else if (opcao == 2) {
		IOWR_ALTERA_AVALON_PIO_DATA(LED2_BASE, nivelLogico);
	} else if (opcao == 3) {
		IOWR_ALTERA_AVALON_PIO_DATA(LED3_BASE, nivelLogico);
	} else if (opcao == 4) {
		IOWR_ALTERA_AVALON_PIO_DATA(LED4_BASE, nivelLogico);
	} else if (opcao == 5) {
		IOWR_ALTERA_AVALON_PIO_DATA(LED5_BASE, nivelLogico);
	}
}

/*
 * Função para escrever palavras no LCD
 */
void printalcd(char word[][16], int lugar) {

	int i;
	lugar = lugar - 1;

	/* Set the Cursor to the home position */
	ALT_CI_LCD_0(LCD_WR_COMMAND_REG, 0x02);
	usleep(2000);

	/* Display clear */
	ALT_CI_LCD_0(LCD_WR_COMMAND_REG, 0x01);
	usleep(2000);

	for (i = 0; i < strlen(word); i++) {
		ALT_CI_LCD_0(LCD_WR_DATA_REG, word[lugar][i]);
		usleep(100);
	}
}

/*
 * Função para inicializar o LCD
 */
void lcd_init(void) {
	usleep(15000); /* Wait for more than 15 ms before init */
	/* Set function code four times -- 8-bit, 2 line, 5x7 mode */
	ALT_CI_LCD_0(LCD_WR_COMMAND_REG, 0x38);
	usleep(4100); /* Wait for more than 4.1 ms */
	ALT_CI_LCD_0(LCD_WR_COMMAND_REG, 0x38);
	usleep(100); /* Wait for more than 100 us */
	ALT_CI_LCD_0(LCD_WR_COMMAND_REG, 0x38);
	usleep(5000); /* Wait for more than 100 us */
	ALT_CI_LCD_0(LCD_WR_COMMAND_REG, 0x38);
	usleep(100); /* Wait for more than 100 us */

	/* Set Display to OFF*/
	ALT_CI_LCD_0(LCD_WR_COMMAND_REG, 0x08);
	usleep(100);

	/* Set Display to ON */
	ALT_CI_LCD_0(LCD_WR_COMMAND_REG, 0x0C);
	usleep(100);

	/* Set Entry Mode -- Cursor increment, display doesn't shift */
	ALT_CI_LCD_0(LCD_WR_COMMAND_REG, 0x06);
	usleep(100);

	/* Set the Cursor to the home position */
	ALT_CI_LCD_0(LCD_WR_COMMAND_REG, 0x02);
	usleep(2000);

	/* Display clear */
	ALT_CI_LCD_0(LCD_WR_COMMAND_REG, 0x01);
	usleep(2000);
}

void atTest(){
	// AT TESTE
	int z;
	char comando[] = "AT";
	write_uart(strlen(comando), comando);
	read_uart();
}

void networkConnection(){
	char cmd[] = "AT+CWJAP=\"WLessLEDS\",\"HelloWorldMP31\"";
	//char cmd[] = "AT+CWJAP=\"IEEE_UEFS\",\"ramoIEEEUEFS\"";
	//char cmd[] = "AT+CWJAP=\"Gilberto WiFi\",\"20152015\"";
	write_uart(strlen(cmd), cmd);
	read_uart();

	printf("CONECTOU A REDE!");
}

void tcpConnection(){
	// Iniciando a conexão TCP
	char cmd2[] = "AT+CIPSTART=\"TCP\",\"192.168.1.103\",1883";
	//char cmd2[] = "AT+CIPSTART=\"TCP\",\"test.mosquitto.org\",1883";
	write_uart(strlen(cmd2), cmd2);
	read_uart();

	printf("CONEXAO TCP OK!");
}

void initConnection(){
	int z;
	/*         CONEXÃO
		Tipo da mensagem = 0x10 (Connect)
		Tamanho total da mensagem = 0x11 (17)
		Tamanho do nome do protocolo  = 0x00, 0x04 (4)
		Nome do protocolo = 0x4D, 0x51, 0x54, 0x54 (MQTT)
		Versão do protocolo = x04 (4)
		Flags = 0x02 (2)
		Keep Alive = 0x00, 0x14 (20)
		Tamanho do ID do cliente = 0x00, 0x05 (5)
		ID do cliente = 0x4E, 0x69, 0x6F, 0x73, 0x35 (Nios2)
	*/
	char connect[] = {0x10, 0x11, 0x00, 0x04, 0x4D, 0x51,
			0x54, 0x54, 0x04, 0x02, 0x00, 0x64, 0x00, 0x05,
			0x4E, 0x69, 0x6F, 0x73, 0x36};

	/*      ENVIANDO O PACOTE DE CONEXÃO     */
	char cmd3[] = "AT+CIPSEND=19";
	write_uart(strlen(cmd3),cmd3);

	read_uart();
	//printf("%d", sizeof(connect));
	for(z=0; z < sizeof(connect); z++){
		printf("%c", connect[z]);
		write_uart_quick(connect[z]);
	}
	IOWR_ALTERA_AVALON_UART_TXDATA(UART_1_BASE, '\r');
	usleep(1000);
	IOWR_ALTERA_AVALON_UART_TXDATA(UART_1_BASE, '\n');
	read_uart();

	printf("\nCONEXAO COM O BROKER CONCLUIDA!");
}

void sendPublish(int opcao){
	int z;
	opcao = opcao-1;
	char optop[] = {0x31,0x32,0x33,0x34,0x35};

	/*        PUBLISH PARA teste/teste1 - Opções
		Tipo da mensagem = 0x30 (Publish)
		Tamanho total da mensagem = 0x19 (25)
		Tamaho do tópico = 0x00, 0x0C (12)
		Tópico = 0x74, 0x65, 0x73, 0x74, 0x65, 0x2f, 0x74, 0x65,
				 0x73, 0x74, 0x65, 0x31 (teste/teste1)
		Mensagem = 0x45, 0x6E, 0x74, 0x72, 0x6F, 0x75, 0x20, 0x6E,
				 0x6F, 0x20, 0x31 (Entrou no 1)
	*/
	char publish[] = {0x30, 0x19, 0x00, 0x0C,
			0x74, 0x65, 0x73, 0x74, 0x65, 0x2f, 0x74,
			0x65, 0x73, 0x74, 0x65, 0x31, 0x45, 0x6E,
			0x74, 0x72, 0x6F, 0x75, 0x20, 0x6E, 0x6F,
			0x20, 0x31};

	/*char publish[] = {0x30, 0x18, 0x00, 0x0C,
				0x74, 0x65, 0x73, 0x74, 0x65, 0x2f, 0x74, 0x65, 0x73, 0x74, 0x65, 0x31,
				0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x57, 0x6F, 0x72, 0x6C, 0x64};
	*/
	publish[26] = optop[opcao];
	/*      ENVIANDO O PACOTE DE PUBLISH     */
	char cmd4[] = "AT+CIPSEND=27"; // 27- teste/teste1
	write_uart(strlen(cmd4),cmd4);
	read_uart();

	for(z=0; z < sizeof(publish); z++){
		printf("---------------\n");
		printf("%d",z);
		printf(": %c", publish[z]);
		write_uart_quick(publish[z]);
		printf("---------------\n");
	}
	IOWR_ALTERA_AVALON_UART_TXDATA(UART_1_BASE, '\r');
	usleep(1000);
	IOWR_ALTERA_AVALON_UART_TXDATA(UART_1_BASE, '\n');
	//usleep(1000);
	read_uart();
}

int main() {
	printf("ENTROU");
	/*        PUBLISH PARA teste/teste1 - Hello Word
		Tipo da mensagem = 0x30 (Publish)
		Tamanho total da mensagem = 0x19 (24)
		Tamaho do tópico = 0x00, 0x0C (12)
		Tópico = 0x74, 0x65, 0x73, 0x74, 0x65, 0x2f, 0x74, 0x65,
				 0x73, 0x74, 0x65, 0x31 (teste/teste1)
		Mensagem = 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x57, 0x6F, 0x72,
				 0x6C, 0x64 (Hello World)
	*/
	/*
	char publish[] = {0x30, 0x18, 0x00, 0x0C,
			0x74, 0x65, 0x73, 0x74, 0x65, 0x2f, 0x74, 0x65, 0x73, 0x74, 0x65, 0x31,
			0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64};
	*/

	/*
		Tipo da mensagem = 0xE0 (Desconexão)
		Tamango total da mensagem = 0x00 (0)
	*/
	//char disconnect[] = {0xE0, 0x00};

 	int sw_value, sw_value1, sw_value2, sw_value3;
	int opcao = 1;
	int entrouOpcao = 0, liberado = 1;

	// INICIALIZAÇÃO DO LCD
	lcd_init();
	char bemVindo[1][16] = { " SEJA BEM VINDO" };
	char conectando[1][16] = { " CONECTANDO..." };
	char options[5][16] = { "1 opcao", "2 opcao", "3 opcao", "4 opcao",
			"5 opcao" };
	// Palavras para serem escritas no LCD
	char options2[5][16] = { "Entrou no 1", "Entrou no 2", "Entrou no 3",
			"Entrou no 4", "Entrou no 5" };

	// Desligar todos os LEDS
	IOWR_ALTERA_AVALON_PIO_DATA(LED1_BASE, 1);
	IOWR_ALTERA_AVALON_PIO_DATA(LED2_BASE, 1);
	IOWR_ALTERA_AVALON_PIO_DATA(LED3_BASE, 1);
	IOWR_ALTERA_AVALON_PIO_DATA(LED4_BASE, 1);
	IOWR_ALTERA_AVALON_PIO_DATA(LED5_BASE, 1);

	printalcd(bemVindo, opcao);
	usleep(2000000);
	printalcd(conectando, opcao);

	//_________________________COMANDOS AT__________________________________

	//atTest();

	networkConnection();

	tcpConnection();

	initConnection();

	//_______________________FIM DOS COMANDOS AT____________________________

	printalcd(options, opcao);
	while (1) {
		sw_value = IORD_ALTERA_AVALON_PIO_DATA(PUSHBUTON1_BASE);
		sw_value1 = IORD_ALTERA_AVALON_PIO_DATA(PUSHBUTON2_BASE);
		sw_value2 = IORD_ALTERA_AVALON_PIO_DATA(PUSHBUTON3_BASE);
		sw_value3 = IORD_ALTERA_AVALON_PIO_DATA(PUSHBUTON4_BASE);
		//printf("%x", sw_value3);
		//usleep(150000); /* Wait for more than 15 ms before init */

		if (sw_value == 0 && entrouOpcao == 0 && liberado == 1) { // Aperta o button1
			if (opcao == 1) {
				opcao = 5;
			} else {
				opcao--;
			}
			printalcd(options, opcao);
			liberado = 0;
		} else if (sw_value1 == 0 && entrouOpcao == 0 && liberado == 1) { // Aperta o button2
			if (opcao == 5) {
				opcao = 1;
			} else {
				opcao++;
			}
			printalcd(options, opcao);
			liberado = 0;
		} else if (sw_value2 == 0) { // Aperta o button3
			acenderLeds(opcao, 1);
			entrouOpcao = 0;
			printalcd(options, opcao);
		} else if (sw_value3 == 0 && liberado == 1) { // Aperta o button4
			acenderLeds(opcao, 0);

			// Enviar a opção para árbitro
			int result = ALT_CI_ARBITRO_0(opcao,0x0);
			printf("RESULT: %d \n", result);

			// Envia a opção para ser publicado via MQTT
			sendPublish(opcao);

			printalcd(options2, opcao);
			entrouOpcao = 1;
			liberado = 0;
		}
		//printf("OPCAO: %i \n", opcao);

		// Liberar button
		if (sw_value == 1 && sw_value1 == 1 && sw_value3 == 1) {
			liberado = 1;
		}
	}
	return 0;
}
