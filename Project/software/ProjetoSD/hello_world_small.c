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


void write_uart(int tamanho, char *comando)
{
    unsigned long status = 0;
    int i;
    //acenderLeds(1, 0);
    // Verifica até que seja possível a transmissão de dados
    while((status & 0x00000040) != 0x00000040)
    {
        status = IORD_ALTERA_AVALON_UART_STATUS(UART_1_BASE);
    }

    for (i = 0; i < tamanho; i++) {
    	printf("%c", comando[i]);
    	IOWR_ALTERA_AVALON_UART_TXDATA(UART_1_BASE, comando[i]);
    }
    IOWR_ALTERA_AVALON_UART_TXDATA(UART_1_BASE, '\\');
    IOWR_ALTERA_AVALON_UART_TXDATA(UART_1_BASE, 'r');
    IOWR_ALTERA_AVALON_UART_TXDATA(UART_1_BASE, '\\');
    IOWR_ALTERA_AVALON_UART_TXDATA(UART_1_BASE, 'n');
}

char read_uart()
{
	char a = 'X';
	while (1) {
		a = IORD_ALTERA_AVALON_UART_RXDATA(UART_1_BASE);
		if (a == 'K') {
			return a;
		}
	}
	return a;
	/*
    char x;
    x = IORD_ALTERA_AVALON_UART_RXDATA(UART_1_BASE);
    return x;*/
}

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
	lugar = lugar - 1;

	int i;
	/* Set the Cursor to the home position */
	ALT_CI_LCD_0(LCD_WR_COMMAND_REG, 0x02);
	usleep(2000);

	/* Display clear */
	ALT_CI_LCD_0(LCD_WR_COMMAND_REG, 0x01);
	usleep(2000);
	//printf("%i",strlen(word));
	for (i = 0; i < strlen(word); i++) {
		//printf("PALAVRA: %c \n", word[lugar][i]);
		ALT_CI_LCD_0(LCD_WR_DATA_REG, word[lugar][i]);
		usleep(100);
	}
}

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

int main() {
	printf("Hello from Nioss II!!\n");

	int sw_value, sw_value1, sw_value2, sw_value3;
	int opcao = 1;
	int entrouOpcao = 0, liberado = 1;

	// INICIALIZAÇÃO DO LCD
	lcd_init();
	char bemVindo[1][16] = { " SEJA BEM VINDO" };
	char options[5][16] = { "1 opcao", "2 opcao", "3 opcao", "4 opcao",
			"5 opcao" };
	//char options2[5][16] = {"1 opcao","2 opcao","3 opcao","4 opcao","5 opcao"};
	char options2[5][16] = { "Entrou no 1", "Entrou no 2", "Entrou no 3",
			"Entrou no 4", "Entrou no 5" };
	// Enviando palavra para ser exibida no LCD

	// Desligar todos os LEDS
	IOWR_ALTERA_AVALON_PIO_DATA(LED1_BASE, 1);
	IOWR_ALTERA_AVALON_PIO_DATA(LED2_BASE, 1);
	IOWR_ALTERA_AVALON_PIO_DATA(LED3_BASE, 1);
	IOWR_ALTERA_AVALON_PIO_DATA(LED4_BASE, 1);
	IOWR_ALTERA_AVALON_PIO_DATA(LED5_BASE, 1);

	printalcd(bemVindo, opcao);
	usleep(2000000);
	printalcd(options, opcao);


	char comando[] = "AT";
	char resposta;
	printf("%d",strlen(comando));
	write_uart(strlen(comando), comando);
	resposta = read_uart();

	printf("%c", resposta);
	if (resposta == 'K') {
		acenderLeds(1, 0);
	}


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
