/*
 * push_button.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Joe Krachey
 */

#include "push_button.h"

volatile bool ALERT_PUSH_BUTTON = false;

/* IO Pin Handler Struct */
cyhal_gpio_callback_data_t push_button_cb_data =
{
    .callback     = push_button_handler,
    .callback_arg = (void*)NULL
};


/** IRQ handler for SW401
 *
 * @param
 *
 */
void push_button_handler(void* handler_arg, cyhal_gpio_event_t event)
{
	ALERT_PUSH_BUTTON= true;

    /* Toggle LED401 when an interrupt has been detected */

}

/** Configure SW401 to generate an interrupt when the push button
 * has been pressed
 *
 * @param
 *
 */
static void push_button_irq_init(void)
{
	/* You will need to examine the HAL API to determine how to
	 * register a callback function when an interrupt has been detected
	 */

	/* You will need to examine the HAL API to enable falling edge event to
	 * generate an interrupt
	 */
}

/** Initialize the pin connected to SW401 to be an input pin
 *
 * @param
 *
 */
static void push_button_io_init(void)
{
	/* Initialize SW401.  You will need to examine the HAL API to determine how to
	 * initialize an IO pin an input
	 */
}


/** Initialize the push button on the ECE453 MCU Dev Board
 *  to generate interrupts
 *
 * @param
 *
 */
void push_button_init(void)
{
	push_button_io_init();
	push_button_irq_init();
}
