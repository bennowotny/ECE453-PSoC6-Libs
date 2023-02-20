/*
 * console.h
 *
 *  Created on: Jan 21, 2022
 *      Author: Joe Krachey
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"


/* ADD CODE */
#define PIN_CONSOLE_TX 	P5_1
#define PIN_CONSOLE_RX	P5_0


#define DEBUG_MESSAGE_MAX_LEN   (100u)
#define INT_PRIORITY_CONSOLE	3

#define RX_SIZE 80

#define CR '\r'
#define LF '\n'

extern bool RX_READY;
extern char RX_DATA[RX_SIZE];
extern uint32_t cidx;
extern uint32_t pidx;


/* Public Function API */
void console_init(void);


#endif /* CONSOLE_H_ */
