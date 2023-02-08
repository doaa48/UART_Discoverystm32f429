/****************************************************************************************************************************************/
/***********************************************	Author  : ABS Team  	*************************************************************/
/***********************************************	Date    : 2- 1- 2022    *************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/
#ifndef URAT_INTERFACE_H_
#define URAT_INTERFACE_H_



#define ENABLE   1
#define DISABLE  0
/*
 * Parity selection
 */

#define UART_PARITY_EVEN  0
#define UART_PARITY_ODD   1


/*
 *This bit determines the word length
 */

#define UART_WORD_8   0
#define UART_WORD_9   1

/*
 * These bits are used for programming the stop bits
 */

#define UART_STOP_BIT_1   0
#define UART_STOP_BIT_2   2


/*
 * Clock Polarity -> idel state of the UART
 */

#define UART_CK_LOW_POLARITY    0
#define UART_CK_HIGH_POLARITY   1

/*
 * Clock Phase -> first edge reading(sampling) or writing(setup)
 */

#define UART_CP_READ_WRITE    0
#define UART_CP_WRITE_READ    1

/*
 * UART Selection
 */
#define USART1_SEL 0
#define USART2_SEL 1
#define USART3_SEL 2
#define UART4_SEL  3
#define UART5_SEL  4





/*
 * Discription:UART initialization
 * Parameters :No Parameters
 * Return 	  :No return
 */
extern void UART_voidInit(void);



//============================================================>>> 
/*
 * Discription:floating approximation ceiling or floaing
 * Parameters :float number
 * Return 	  :return 0 for flooring and 1 for ceiling
 */
//extern u8 Floating_ApproximatingTo3Disimal(f32 Copy_f32Floating);
//============================================================>>>


/*
 * Discription:UART setting the baud rate in floating
 * Parameters :Used clock frequency , the Baud rate , UART number from 1 to 5
 * Return 	  :No return
 */
extern void UART_u8SetBaudRate(u8 Copy_u8CLK_In_Miga,u32 Copy_U32BaudRate,u8 Copy_u8UARTNumber);

/*
 * Discription:UART Transmiting data
 * Parameters :Data , UART number from 1 to 5
 * Return 	  :No return
 */
extern void UART_voidTransmit_Synch(u8 *Copy_pu8Data,u8 Copy_u8UARTNumber);

/*
 * Discription:UART Recieving data
 * Parameters :UART number from 1 to 5
 * Return 	  :Data
 */
extern u8 UART_u8Receive_Synch(u8 Copy_u8UARTNumber);

/*
 * Discription:UART Recieving data using interrupt
 * Parameters :pointer to data , UART number from 1 to 5
 * Return 	  :No return
 */
extern void USART_voidReiceve_Asynch(u8 *Copy_pu8DataInterrupt,u8 Copy_u8UARTNumber);

/*
 * Discription:UART tacking action in the interrupt
 * Parameters :pointer to function ,UART number from 1 to 5
 * Return 	  :return the status of function if ok return 0 if happen error due to null pointer return 1
 */
extern u8 UART_u8SetCallBack(void (*UART_Func)(u8 x),u8 Copy_u8UARTNumber);


/*
 * Discription: UART ENABLE Or DISABLE interrupt
 * Parameters : ENABLE Or DISABLE ,UART number from 1 to 5
 * Return 	  : No return
 */
extern void UART_voidEnableOrDisableIntrrupt(u8 Copy_u8Enable_Disable,u8 Copy_u8UARTNumber);


/*
 * Discription: UART send Int Number
 * Parameters : u32 number to be send ,UART number from 1 to 5
 * Return 	  : No return
 */
extern void UART_VoidSendIntNumber(u32 Copy_u32Number, u8 Copy_u8UARTNumber);


/*
 * Discription: UART send Float Number
 * Parameters :  f64 number to be send ,UART number from 1 to 5
 * Return 	  : No return
 */
extern void UART_VoidSendFloatNumber(f64 Copy_f64Number, u8 Copy_u8UARTNumber);



/*
 * Discription: UART send char
 * Parameters : u8 char to be send ,UART number from 1 to 5
 * Return 	  : No return
 */
void UART_voidSendChar(u8 Copy_u8Char,u8 Copy_u8UARTNumber);

/*
 * Discription: this function in equivalant to Printf in c standard
 * Parameters : string contain text and % for variable  ,  variable number of values
 * Return 	  : No return
 */
void log_print ( const u8 *StringOut ,...);

/*
 * Discription: UART Recieving String 
 * Parameters : pointer to save received string on it 
 * Return 	  : No return
 */
void UART_ReceiveString(u8 *str);

#endif
