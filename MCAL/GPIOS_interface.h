/****************************************************************************************************************************************/
/***********************************************	Author  : ABS Team      *************************************************************/
/***********************************************	Date    : 2- 1- 2022    *************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/

#ifndef _GPIOS_INTERFACE_H_
#define _GPIOS_INTERFACE_H_




/********************************************************  Clock control register (RCC_CR) ***********************************************/
/*****************************************************************************************************************************************/

/*
 * For Inputs Modes chosen to GPIOS
 */
#define GPIOS_INPUT_ANALOGE   	          0x00
#define GPIOS_INPUT_FLOATING  	          0X04
#define GPIOS_INPUT_PULL_UP_DOWN          0x08

/*
 * For Outputs Modes chosen to GPIOS
 */
#define GPIOS_OUTPUT_PUSH_PULL_10MHZ      0x01
#define GPIOS_OUTPUT_PUSH_PULL_2MHZ       0X02
#define GPIOS_OUTPUT_PUSH_PULL_50MHZ      0x03
#define GPIOS_OUTPUT_OPEN_DRAIN_10MHZ     0X05
#define GPIOS_OUTPUT_OPEN_DRAIN_2MHZ      0x05
#define GPIOS_OUTPUT_OPEN_DRAIN_50MHZ     0X07
#define GPIOS_OUTPUT_AF_OPEN_DRAIN_10MHZ  0x0D
#define GPIOS_OUTPUT_AF_OPEN_DRAIN_2MHZ   0X0E
#define GPIOS_OUTPUT_AF_OPEN_DRAIN_50MHZ  0X0F
#define GPIOS_OUTPUT_AF_PUSH_PULL_10MHZ   0x09
#define GPIOS_OUTPUT_AF_PUSH_PULL_2MHZ    0X0A
#define GPIOS_OUTPUT_AF_PUSH_PULL_50MHZ   0x0B

/*
 * Output Pin Configurations
 */
#define GPIOS_HIGH   1
#define GPIOS_LOW    0

/*
 * Output Pin Configurations
 */
#define GPIOS_PULL_UP      1
#define GPIOS_PULL_DOWN    0



/*
 * Ports Numbers
 */
enum GPIOS_PORTS
{
	GPIOS_PORTA,
	GPIOS_PORTB,
	GPIOS_PORTC,
};
/*
 * Pins Numbers
 */
enum GPIOS_PINS
{
	PIN_0   ,
	PIN_1	,
	PIN_2	,
	PIN_3	,
	PIN_4	,
	PIN_5	,
	PIN_6	,
	PIN_7	,
	PIN_8	,
	PIN_9	,
	PIN_10	,
	PIN_11	,
	PIN_12	,
	PIN_13	,
	PIN_14	,
	PIN_15  ,
	PIN_16
};







/********************************************************  Functions  ***********************************************/
/********************************************************************************************************************/


/*
 * Prototype   : u8 GPIOS_u8SetPinDir(u8 Copy_u8PORT, u8 Copy_u8PIN,u8 Copy_u8Mode);
 * Description : Setting the pin Direction
 * Arguments   : Port number ,Pin Number , Pin Mode
 * return      : u8 the status of Function if it work properly or not
 */
extern u8 GPIOS_u8SetPinDir(u8 Copy_u8PORT, u8 Copy_u8PIN,u8 Copy_u8Mode);

/*
 * Prototype   : u8 GPIOS_u8SetPortDir(u8 Copy_u8PORT,u8 Copy_u8Mode);
 * Description : Setting the whole Port with same direction
 * Arguments   : Port number ,Port Mode
 * return      : u8 the status of Function if it work properly or not
 */
extern u8 GPIOS_u8SetPortDir(u8 Copy_u8PORT,u8 Copy_u8Mode);

/*
 * Prototype   : u8 GPIOS_VoidSetPortVal(u8 Copy_u8PORT,u32 Copy_u8PortVal);
 * Description : Setting the Port Value
 * Arguments   : Port number , Pin Mode
 * return      : u8 the status of Function if it work properly or not
 */
extern u8 GPIOS_u8SetPortVal(u8 Copy_u8PORT,u32 Copy_u8PortVal);

/*
 * Prototype   : u8 GPIOS_VoidGetPinVal(u8 Copy_u8PORT,u8 Copy_u8PIN ,u8 *Copy_U8ptrPinVal);
 * Description : Reading the pin Value
 * Arguments   : Port number ,Pin Number , pointer to savle the value in it
 * return      : u8 the status of Function if it work properly or not
 */
extern u8 GPIOS_u8GetPinVal(u8 Copy_u8PORT,u8 Copy_u8PIN ,u8 *Copy_U8ptrPinVal);

/*
 * Prototype   : u8 GPIOS_VoidSetPinVal(u8 Copy_u8PORT,u8 Copy_u8PIN, u8 Copy_u8PinVal);
 * Description : Setting the pin Value if output (push ,pull ->High Low) if input Pull up/down(1 up ,0 down)
 * 				 (not used IN Pin val as BSRR ,BRR are faster)
 * Arguments   : Port number ,Pin Number , Pin Value
 * return      : u8 the status of Function if it work properly or not
 */
extern u8 GPIOS_u8SetPinVal(u8 Copy_u8PORT,u8 Copy_u8PIN, u8 Copy_u8PinVal);

/*
 * Prototype   : u8 GPIOS_VoidClearPin(u8 Copy_u8PORT,u8 Copy_u8PIN);
 * Description : Clearing the pin in any port (BBR is very fast and commonly used it Clearing pin)
 * Arguments   : Port number ,Pin Number
 * return      : u8 the status of Function if it work properly or not
 */
extern u8 GPIOS_u8ClearPin(u8 Copy_u8PORT,u8 Copy_u8PIN);

/*
 * Prototype   : u8 GPIOS_VoidClearPort(u8 Copy_u8PORT);
 * Description : Clearing whole Port Pins
 * Arguments   : Port number
 * return      : u8 the status of Function if it work properly or not
 */
extern u8 GPIOS_u8ClearPort(u8 Copy_u8PORT);

/*
 * Prototype   : u8 GPIOS_VoidSetPin(u8 Copy_u8PORT,u8 Copy_u8PIN);
 * Description : Setting the pin to 1 in any port (BBSR is very fast and commonly used it Setting pin)
 * Arguments   : Port number ,Pin Number
 * return      : u8 the status of Function if it work properly or not
 */
extern u8 GPIOS_u8SetPin(u8 Copy_u8PORT,u8 Copy_u8PIN);

/*
 * Prototype   : u8 GPIOS_VoidSetPort(u8 Copy_u8PORT);
 * Description : Setting whole Port Pins
 * Arguments   : Port number
 * return      : u8 the status of Function if it work properly or not
 */
extern u8 GPIOS_u8SetPort(u8 Copy_u8PORT);

/*
 * Prototype   : u8 GPIOS_VoidLockPort(u8 Copy_u8PORT);
 * Description : Locking whole Port Pins and can't configure them until reset MCu
 * Arguments   : Port number
 * return      : u8 the status of Function if it work properly or not
 */
extern u8 GPIOS_u8LockPort(u8 Copy_u8PORT);

/*
 * Prototype   : u8 GPIOS_VoidLockPin(u8 Copy_u8PORT,u8 Copy_u8PIN);
 * Description : Locking Pin and can't configure it until reset MCu
 * Arguments   : Port number ,Pin Number
 * return      : u8 the status of Function if it work properly or not
 */
extern u8 GPIOS_u8LockPin(u8 Copy_u8PORT,u8 Copy_u8PIN );







#endif
