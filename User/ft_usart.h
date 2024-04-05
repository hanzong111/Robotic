#ifndef FT_USART_H
#define FT_USART_H	

#include "stm32f10x.h" // Include the appropriate STM32F1 series header file
#include "stm32f10x_usart.h" // Include the USART library


/* UART peripheral definitions */
#define UART_PORT               USART1                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
#define UART_GPIO_PORT          GPIOB
#define UART_TX_PIN             GPIO_Pin_6
#define UART_RX_PIN             GPIO_Pin_7

void UART_Configuration(void);

#endif
