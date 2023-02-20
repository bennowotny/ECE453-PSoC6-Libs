/*
 * console.c
 *
 */

#include "console.h"

bool RX_READY = false;
char RX_DATA[RX_SIZE];
uint32_t cidx;
uint32_t pidx;


/*******************************************************************************
* Function Name: console_event_handler
********************************************************************************
* Summary:
* UART Handler used to receive characters from the console.
*
* Parameters:
*  void
*
* Return:
*
*
*******************************************************************************/
void console_event_handler(void *handler_arg, cyhal_uart_event_t event)
{
    (void) handler_arg;
    cy_rslt_t rslt;
    size_t to_read = 1;

    rslt = cyhal_uart_read(&cy_retarget_io_uart_obj, &RX_DATA[pidx], &to_read);
    while (CY_RSLT_SUCCESS != rslt); // stall if bad

    if (RX_DATA[pidx] == CR || RX_DATA[pidx] == LF) {
    	RX_READY = true;
    }

    pidx = (pidx + 1) % RX_SIZE;

}

/*******************************************************************************
* Function Name: console_init_irq
********************************************************************************
* Summary:
* Enables and Registers all interrupt sources for the ECE453 Base project
*
* Parameters:
*  void
*
* Return:
*
*
*******************************************************************************/
static void console_init_irq(void)
{
    // Enable Console Rx Interrupts
	/* The UART callback handler registration */
	cyhal_uart_register_callback(&cy_retarget_io_uart_obj, &console_event_handler, NULL);
	/* Enable required UART events */
	cyhal_uart_enable_event(&cy_retarget_io_uart_obj, CYHAL_UART_IRQ_RX_NOT_EMPTY, INT_PRIORITY_CONSOLE, true);

}

/*******************************************************************************
* Set up the console retarget IO
*******************************************************************************/
static void console_init_retarget(void)
{

    /* Initialize retarget-io to use the debug UART port, 8N1 */
	cy_retarget_io_init(PIN_CONSOLE_TX, PIN_CONSOLE_RX, 115200);

}

/*******************************************************************************
* Function Name: console_init
********************************************************************************
* Summary:
* 	Enables the SCB used for console interface.  Rx interrupts are turned on
*
* Parameters:
*  void
*
* Return:
*
*
*******************************************************************************/
void console_init(void)
{
	console_init_retarget();
	console_init_irq();
}






