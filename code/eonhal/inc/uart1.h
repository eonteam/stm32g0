/**
 ******************************************************************************
 * @file    uart1.h
 * @author  Pablo Fuentes
 * @version V1.0.1
 * @date    2019
 * @brief   Header de UART Library
 ******************************************************************************
 */

#ifndef __UART1_H
#define __UART1_H

#include "eon_string.h"
#include "pinmap_hal.h"
#include <stdbool.h>
#include <stdint.h>


#if (defined(USART1) || defined(UART1))

/**
 * @brief Initialize the UART
 *
 * @param {baudrate}  Usually 9600
 * @param {tx}  TX2_Pin
 * @param {rx}  RX2_Pin
 */
void uart1_init(uint32_t baudrate, pin_t tx, pin_t rx);

/**
 * @brief Initialize the UART for RS485 Half-Duplex driver
 *
 * @param {baudrate}  Usually 9600
 * @param {tx}  TX2_Pin
 * @param {rx}  RX2_Pin
 * @param {de}  RS485_DE_Pin
 * @param {de_polarity} HIGH or LOW
 */
void uart1_rs485_init(uint32_t baudrate, pin_t tx, pin_t rx, pin_t de,
                      uint8_t de_polarity);

/**
 * @brief Turn off the UART
 *
 */
void uart1_off(void);

/**
 * @brief Write a character
 *
 * @param {c} Character to be written
 */
void uart1_write(unsigned char c);

/**
 * @brief Verify is there any character to be read
 *
 * @return {uint16_t} Total bytes ready to be read
 */
uint16_t uart1_available(void);

/**
 * @brief Read a character
 *
 * @return {int} Character read (-1) if fails
 */
int uart1_read(void);

/**
 * @brief Peek function
 *
 * @return {int} Character (-1) if fails
 */
int uart1_peek(void);

/**
 * @brief Read until a terminator
 *
 * @param {buffer} Buffer to be filled
 * @param {terminator} Terminator character
 */
void uart1_readUntil(char buffer[], uint8_t terminator);

/**
 * @brief Print text
 *
 * @param {s} Message to print
 */
void uart1_print(const char *s);

/**
 * @brief Print an array of characters
 *
 * @param {s} Array of characters
 */
void uart1_printArray(char s[]);

/**
 * @brief Print text and append a new line at the end
 *
 * @param {s} Message to print
 */
void uart1_println(const char *s);

/**
 * @brief Macro for print an integer in base 10
 *
 * @param {__x__} Integer
 */
#define uart1_printInt(__x__) uart1_printIntBase((__x__), 10)

/**
 * @brief Print an integer specifiying the desired base
 *
 * @param {n} Integer
 * @param {base} Base
 */
void uart1_printIntBase(int64_t n, uint8_t base);

/**
 * @brief Macro for print a float
 *
 * @param {__x__} Float number
 */
#define uart1_printFloat(__x__) uart1_printNum((int64_t)((__x__)*100), 1)

/**
 * @brief Macro for print an integer and append a new line at the end
 *
 * @param {__x__} Integer
 */
#define uart1_printlnInt(__x__) uart1_printlnIntBase((__x__), 10)

/**
 * @brief Print an integer specifiying the desired base and append a new line at
 * the end
 *
 * @param {n} Integer
 * @param {base} Base
 */
void uart1_printlnIntBase(int64_t n, uint8_t base);

/**
 * @brief Print a float and append a new line at the end
 *
 * @param {__x__} Float number
 */
#define uart1_printlnFloat(__x__) uart1_printlnNum((int64_t)((__x__)*100), 1)

/**
 * @brief Print a number integer or float in a light way. Float numbers should
 * be written as integer and put true in second argument.
 *
 * @param {n} Number
 * @param {isfloat} True for float print and false for integer print
 */
void uart1_printNum(int64_t n, uint8_t isfloat);

/**
 * @brief Print a number integer or float in a light way. Float numbers should
 * be written as integer and put true in second argument. And append a new line.
 *
 * @param {n} Number
 * @param {isfloat} True for float print and false for integer print
 */
void uart1_printlnNum(int64_t n, uint8_t isfloat);

#endif

#endif
