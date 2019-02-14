# PBL-SD-3
Repositório referente a solução do terceiro problema do modulo integrador de Sistemas Digitais. Assuntos abordados:
'''
Instruções customizadas para monipulação de LCD
''''
Contrução e envio de pacotes MQTT
'''
Manipulação de dados em um barramento RS232

## Maquina de Estados - "Lamaquina.sv" (nome do arquivo)
Existem duas instâncias da maquina em verilog, uma em "verilog files" essa que é completamente separada da UART e está junto ao seu teste de execução.
Já na pasta Project existe a instancia da maquina em que é instânciado uma UART dentro dela e é usado como saída os pinos diretos do TX e RX da UART

## Project
Pasta com os arquivos desenvolvidos no quartus

## Verilog Files
Pasta com os arquivos em verilgo usados na maquina de estados, a maquina em si e seu devido teste

## Test_Reports
Pasta contendo imagens de reports de testes vindos da execução no model sim do arquivo "Test_Lamaquina.v" junto a maquian de estados em si


