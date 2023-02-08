/****************************************************************************************************************************************/
/***********************************************	Author  : APS Team  	*************************************************************/
/***********************************************	Date    : 1-2- 2022 	*************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/*SPI Enables
 * Options:
 * 		  ENABLE
 * 		  DISABLE
 *
 */
#define USART1_ENABLE	  ENABLE
#define USART2_ENABLE	  DISABLE
#define USART3_ENABLE	  DISABLE
#define UART4_ENABLE	  DISABLE
#define UART5_ENABLE	  DISABLE


		/************************************* USART 1 ****************************************/
		/*************************************************************************************/

#if USART1_ENABLE==ENABLE

	/* Receiver is enabled and begins searching for a start bit
	 *  Receiver enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART1_RX_ENABLE  ENABLE

	/*
	 *  Transimiter enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART1_TX_ENABLE  ENABLE

	/*
	 * RXNE interrupt enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART1_RX_INTERRUPT_ENABLE  DISABLE


	/*
	 * TXNE interrupt enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART1_TX_INTERRUPT_ENABLE  DISABLE

	/*a parity error occurs in receiver mode
	 * Parity error
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART1_PARITY_ERROR  DISABLE

	#if UART1_PARITY_ERROR==ENABLE

    /*UART Parity Type Selection
	 * Options:
	 *          UART_PARITY_EVEN
	 *          UART_PARITY_ODD
	 */
	#define  UART1_PARITY_SELECT  UART_PARITY_EVEN
	#endif

	/*Transmission complete interrupt enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART1_TX_COMPLETE_INTERRUPT  DISABLE

	/*Error Interrupt Enable Bit is required to enable interrupt generation in case of a
			- framing error
			- overrun error 
			- noise   error
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART1_ERROR_INTERRUPT  DISABLE

	/* This bit determines the word length
	 * Options:
	 *         UART_WORD_8
	 *         UART_WORD_9
	 */
	#define  UART1_WORD_LENGTH  UART_WORD_8

	/* DMA enable transmitter
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART1_DMA_TRANSMITER  DISABLE

	/* DMA enable Reciever
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART1_DMA_RECIEVER  DISABLE

   /*
    * These bits are used for programming the stop bits
    * Options:
    * 			UART_STOP_BIT_1
	* 			UART_STOP_BIT_2
	*/
	#define  UART1_STOP_BITS_NUM    UART_STOP_BIT_1

	/*
	 * Clock Polarity -> idel state of the SPI
	 * Options:
	 *         UART_CK_LOW_POLARITY
	 *         UART_CK_HIGH_POLARITY
	 */
	#define UART1_CK_POLARITY    UART_CK_LOW_POLARITY

	/*
	 * Clock Phase -> first edge reading or writing
	 * Options:
	 *         UART_CP_READ_WRITE
	 *         UART_CP_WRITE_READ
	 */
	#define UART1_CLK_PHASE   UART_CP_WRITE_READ

    /*This bit is not available for UART4 & UART5.
	 * Clock enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define UART1_CLK_ENABLE   DISABLE


#endif


		/************************************* USART 2 ****************************************/
		/*************************************************************************************/

#if USART2_ENABLE==ENABLE

	/* Receiver is enabled and begins searching for a start bit
	 *  Receiver enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART2_RX_ENABLE  ENABLE

	/*
	 *  Transimiter enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART2_TX_ENABLE  ENABLE

	/*
	 * RXNE interrupt enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART2_RX_INTERRUPT_ENABLE  DISABLE


	/*
	 * TXNE interrupt enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART2_TX_INTERRUPT_ENABLE  DISABLE

	/*a parity error occurs in receiver mode
	 * Parity error
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART2_PARITY_ERROR  DISABLE

	#if UART2_PARITY_ERROR==ENABLE

    /*UART Parity Type Selection
	 * Options:
	 *          UART_PARITY_EVEN
	 *          UART_PARITY_ODD
	 */
	#define  UART2_PARITY_SELECT  UART_PARITY_EVEN
	#endif

	/*Transmission complete interrupt enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART2_TX_COMPLETE_INTERRUPT  DISABLE

	/*Error Interrupt Enable Bit is required to enable interrupt generation in case of a
			- framing error
			- overrun error 
			- noise   error
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART2_ERROR_INTERRUPT  DISABLE

	/* This bit determines the word length
	 * Options:
	 *         UART_WORD_8
	 *         UART_WORD_9
	 */
	#define  UART2_WORD_LENGTH  UART_WORD_8

	/* DMA enable transmitter
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART2_DMA_TRANSMITER  DISABLE

	/* DMA enable Reciever
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART2_DMA_RECIEVER  DISABLE

   /*
    * These bits are used for programming the stop bits
    * Options:
    * 			UART_STOP_BIT_1
	* 			UART_STOP_BIT_2
	*/
	#define  UART2_STOP_BITS_NUM    UART_STOP_BIT_1

	/*
	 * Clock Polarity -> idel state of the SPI
	 * Options:
	 *         UART_CK_LOW_POLARITY
	 *         UART_CK_HIGH_POLARITY
	 */
	#define UART2_CK_POLARITY    UART_CK_LOW_POLARITY

	/*
	 * Clock Phase -> first edge reading or writing
	 * Options:
	 *         UART_CP_READ_WRITE
	 *         UART_CP_WRITE_READ
	 */
	#define UART2_CLK_PHASE   UART_CP_WRITE_READ

    /*This bit is not available for UART4 & UART5.
	 * Clock enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define UART2_CLK_ENABLE   DISABLE


#endif

		/************************************* USART 3****************************************/
		/*************************************************************************************/

#if USART3_ENABLE==ENABLE

	/* Receiver is enabled and begins searching for a start bit
	 *  Receiver enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART3_RX_ENABLE  ENABLE

	/*
	 *  Transimiter enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART3_TX_ENABLE  ENABLE

	/*
	 * RXNE interrupt enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART3_RX_INTERRUPT_ENABLE  DISABLE


	/*
	 * TXNE interrupt enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART3_TX_INTERRUPT_ENABLE  DISABLE

	/*a parity error occurs in receiver mode
	 * Parity error
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART3_PARITY_ERROR  DISABLE

	#if UART3_PARITY_ERROR==ENABLE

    /*UART Parity Type Selection
	 * Options:
	 *          UART_PARITY_EVEN
	 *          UART_PARITY_ODD
	 */
	#define  UART3_PARITY_SELECT  UART_PARITY_EVEN
	#endif

	/*Transmission complete interrupt enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART3_TX_COMPLETE_INTERRUPT  DISABLE

	/*Error Interrupt Enable Bit is required to enable interrupt generation in case of a
			- framing error
			- overrun error 
			- noise   error
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART3_ERROR_INTERRUPT  DISABLE

	/* This bit determines the word length
	 * Options:
	 *         UART_WORD_8
	 *         UART_WORD_9
	 */
	#define  UART3_WORD_LENGTH  UART_WORD_8

	/* DMA enable transmitter
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART3_DMA_TRANSMITER  DISABLE

	/* DMA enable Reciever
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART3_DMA_RECIEVER  DISABLE

   /*
    * These bits are used for programming the stop bits
    * Options:
    * 			UART_STOP_BIT_1
	* 			UART_STOP_BIT_2
	*/
	#define  UART3_STOP_BITS_NUM    UART_STOP_BIT_1

	/*
	 * Clock Polarity -> idel state of the SPI
	 * Options:
	 *         UART_CK_LOW_POLARITY
	 *         UART_CK_HIGH_POLARITY
	 */
	#define UART3_CK_POLARITY    UART_CK_LOW_POLARITY

	/*
	 * Clock Phase -> first edge reading or writing
	 * Options:
	 *         UART_CP_READ_WRITE
	 *         UART_CP_WRITE_READ
	 */
	#define UART3_CLK_PHASE   UART_CP_WRITE_READ

    /*This bit is not available for UART4 & UART5.
	 * Clock enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define UART3_CLK_ENABLE   DISABLE


#endif

		/************************************* UART 4****************************************/
		/*************************************************************************************/

#if UART4_ENABLE==ENABLE

	/* Receiver is enabled and begins searching for a start bit
	 *  Receiver enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART4_RX_ENABLE  ENABLE

	/*
	 *  Transimiter enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART4_TX_ENABLE  ENABLE

	/*
	 * RXNE interrupt enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART4_RX_INTERRUPT_ENABLE  DISABLE


	/*
	 * TXNE interrupt enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART4_TX_INTERRUPT_ENABLE  DISABLE

	/*a parity error occurs in receiver mode
	 * Parity error
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART4_PARITY_ERROR  DISABLE

	#if UART4_PARITY_ERROR==ENABLE

    /*UART Parity Type Selection
	 * Options:
	 *          UART_PARITY_EVEN
	 *          UART_PARITY_ODD
	 */
	#define  UART4_PARITY_SELECT  UART_PARITY_EVEN
	#endif

	/*Transmission complete interrupt enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART4_TX_COMPLETE_INTERRUPT  DISABLE

	/*Error Interrupt Enable Bit is required to enable interrupt generation in case of a
			- framing error
			- overrun error 
			- noise   error
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART4_ERROR_INTERRUPT  DISABLE

	/* This bit determines the word length
	 * Options:
	 *         UART_WORD_8
	 *         UART_WORD_9
	 */
	#define  UART4_WORD_LENGTH  UART_WORD_8

	/* DMA enable transmitter
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART4_DMA_TRANSMITER  DISABLE

	/* DMA enable Reciever
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART4_DMA_RECIEVER  DISABLE

   /*
    * These bits are used for programming the stop bits
    * Options:
    * 			UART_STOP_BIT_1
	* 			UART_STOP_BIT_2
	*/
	#define  UART4_STOP_BITS_NUM    UART_STOP_BIT_1

	/*
	 * Clock Polarity -> idel state of the SPI
	 * Options:
	 *         UART_CK_LOW_POLARITY
	 *         UART_CK_HIGH_POLARITY
	 */
	#define UART4_CK_POLARITY    UART_CK_LOW_POLARITY

	/*
	 * Clock Phase -> first edge reading or writing
	 * Options:
	 *         UART_CP_READ_WRITE
	 *         UART_CP_WRITE_READ
	 */
	#define UART4_CLK_PHASE   UART_CP_WRITE_READ

    /*This bit is not available for UART4 & UART5.
	 * Clock enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define UART4_CLK_ENABLE   DISABLE


#endif

		/************************************* UART 5****************************************/
		/*************************************************************************************/

#if UART5_ENABLE==ENABLE

	/* Receiver is enabled and begins searching for a start bit
	 *  Receiver enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART5_RX_ENABLE  ENABLE

	/*
	 *  Transimiter enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART5_TX_ENABLE  ENABLE

	/*
	 * RXNE interrupt enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART5_RX_INTERRUPT_ENABLE  DISABLE


	/*
	 * TXNE interrupt enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */

	#define  UART5_TX_INTERRUPT_ENABLE  DISABLE

	/*a parity error occurs in receiver mode
	 * Parity error
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART5_PARITY_ERROR  DISABLE

	#if UART5_PARITY_ERROR==ENABLE

    /*UART Parity Type Selection
	 * Options:
	 *          UART_PARITY_EVEN
	 *          UART_PARITY_ODD
	 */
	#define  UART5_PARITY_SELECT  UART_PARITY_EVEN
	#endif

	/*Transmission complete interrupt enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART5_TX_COMPLETE_INTERRUPT  DISABLE

	/*Error Interrupt Enable Bit is required to enable interrupt generation in case of a
			- framing error
			- overrun error 
			- noise   error
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART5_ERROR_INTERRUPT  DISABLE

	/* This bit determines the word length
	 * Options:
	 *         UART_WORD_8
	 *         UART_WORD_9
	 */
	#define  UART5_WORD_LENGTH  UART_WORD_8

	/* DMA enable transmitter
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART5_DMA_TRANSMITER  DISABLE

	/* DMA enable Reciever
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define  UART5_DMA_RECIEVER  DISABLE

   /*
    * These bits are used for programming the stop bits
    * Options:
    * 			UART_STOP_BIT_1
	* 			UART_STOP_BIT_2
	*/
	#define  UART5_STOP_BITS_NUM    UART_STOP_BIT_1

	/*
	 * Clock Polarity -> idel state of the SPI
	 * Options:
	 *         UART_CK_LOW_POLARITY
	 *         UART_CK_HIGH_POLARITY
	 */
	#define UART5_CK_POLARITY    UART_CK_LOW_POLARITY

	/*
	 * Clock Phase -> first edge reading or writing
	 * Options:
	 *         UART_CP_READ_WRITE
	 *         UART_CP_WRITE_READ
	 */
	#define UART5_CLK_PHASE   UART_CP_WRITE_READ

    /*This bit is not available for UART5 & UART5.
	 * Clock enable
	 * Options:
	 *         ENABLE
	 *         DISABLE
	 */
	#define UART5_CLK_ENABLE   DISABLE


#endif



#endif
