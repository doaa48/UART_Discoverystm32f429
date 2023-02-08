/****************************************************************************************************************************************/
/***********************************************	Author  :ABS Team       *************************************************************/
/***********************************************	Date    : 2- 1- 2022    *************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/
#include "../LIB/CHECK_ERROR.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/STDTYPES.h"
#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"
#include "GPIOS_Interface.h"
#include <stdarg.h>
#include <stdio.h>
#include "string.h"
#include "math.h"
#include <stdio.h>

void (*UART_voidPinter[5])(u8 ptr) = {NULL};

u8 Global_pu8ReadingData;

u8 Global_u8EnteringState=0;

static u8 Floating_ApproximatingTo3Disimal(f32 Copy_f32Floating)
{
    if(Copy_f32Floating<0.5)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

void UART_u8SetBaudRate(u8 Copy_u8CLK_In_Miga,u32 Copy_U32BaudRate,u8 Copy_u8UARTNumber)
{
    f32 Local_f32UART_Div=(f32)(Copy_u8CLK_In_Miga*1000000)/(f32)(16*Copy_U32BaudRate);
    f32 Local_f32Fraction=(Local_f32UART_Div-(u32)(Local_f32UART_Div) )*16;
    f32 local_f32ApproximatedFraction;

    switch(Copy_u8UARTNumber)
    {
        case USART1_SEL:{
            if ( Local_f32Fraction >15)
            {
                USART1->BRR=((u32)(Local_f32UART_Div) +1)<<4;
            }
            else
            {

                local_f32ApproximatedFraction=Floating_ApproximatingTo3Disimal(Local_f32Fraction-(u32)(Local_f32Fraction));

                if(local_f32ApproximatedFraction==0)
                {

                    USART1->BRR=((u32)(Local_f32UART_Div)<<4)|((u8)(Local_f32Fraction));


                }
                else if(local_f32ApproximatedFraction==1)
                {

                    USART1->BRR=((u32)(Local_f32UART_Div)<<4)|((u32)(Local_f32Fraction)+1);
                }

            }
            break;
        }

        case USART2_SEL:{
            if ( Local_f32Fraction >15)
            {
                USART2->BRR=((u32)(Local_f32UART_Div) +1)<<4;
            }
            else
            {

                local_f32ApproximatedFraction=Floating_ApproximatingTo3Disimal(Local_f32Fraction-(u32)(Local_f32Fraction));

                if(local_f32ApproximatedFraction==0)
                {
                    USART2->BRR=((u32)(Local_f32UART_Div)<<4)|((u32)(Local_f32Fraction));

                }
                else if(local_f32ApproximatedFraction==1)
                {

                    USART2->BRR=((u32)(Local_f32UART_Div)<<4)|((u32)(Local_f32Fraction)+1);
                }

            }
            break;
        }

        case USART3_SEL:{
            if ( Local_f32Fraction >15)
            {
                USART3->BRR=((u32)(Local_f32UART_Div) +1)<<4;
            }
            else
            {

                local_f32ApproximatedFraction=Floating_ApproximatingTo3Disimal(Local_f32Fraction-(u32)(Local_f32Fraction));

                if(local_f32ApproximatedFraction==0)
                {
                    USART3->BRR=((u32)(Local_f32UART_Div)<<4)|(u32)(Local_f32Fraction);

                }
                else if(local_f32ApproximatedFraction==1)
                {

                    USART3->BRR=((u32)(Local_f32UART_Div)<<4)|((u32)(Local_f32Fraction)+1);
                }

            }
            break;
        }

        case UART4_SEL:{
            if ( Local_f32Fraction >15)
            {
                UART4->BRR=((u32)(Local_f32UART_Div) +1)<<4;
            }
            else
            {

                local_f32ApproximatedFraction=Floating_ApproximatingTo3Disimal(Local_f32Fraction-(u32)(Local_f32Fraction));

                if(local_f32ApproximatedFraction==0)
                {
                    UART4->BRR=((u32)(Local_f32UART_Div)<<4)|(u32)(Local_f32Fraction);

                }
                else if(local_f32ApproximatedFraction==1)
                {

                    UART4->BRR=((u32)(Local_f32UART_Div)<<4)|((u32)(Local_f32Fraction)+1);
                }

            }
            break;
        }

        case UART5_SEL:{
            if ( Local_f32Fraction >15)
            {
                UART5->BRR=((u32)(Local_f32UART_Div) +1)<<4;
            }
            else
            {

                local_f32ApproximatedFraction=Floating_ApproximatingTo3Disimal(Local_f32Fraction-(u32)(Local_f32Fraction));

                if(local_f32ApproximatedFraction==0)
                {
                    UART5->BRR=((u32)(Local_f32UART_Div)<<4)|(u32)(Local_f32Fraction);

                }
                else if(local_f32ApproximatedFraction==1)
                {

                    UART5->BRR=((u32)(Local_f32UART_Div)<<4)|((u32)(Local_f32Fraction)+1);
                }

            }
            break;
        }


    }

}

void UART_voidEnableOrDisableIntrrupt(u8 Copy_u8Enable_Disable,u8 Copy_u8UARTNumber)
{
    /*USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register */
    if (Copy_u8Enable_Disable == ENABLE)
    {
        switch(Copy_u8UARTNumber)
        {
            case USART1_SEL:	SET_BIT(USART1->CR1,RXNEIE); break;
            case USART2_SEL:	SET_BIT(USART2->CR1,RXNEIE); break;
            case USART3_SEL:	SET_BIT(USART3->CR1,RXNEIE); break;
            case UART4_SEL :	SET_BIT(UART4->CR1,RXNEIE); break;
            case UART5_SEL :	SET_BIT(UART5->CR1,RXNEIE); break;
        }

    }
    else
    {
        switch(Copy_u8UARTNumber)
        {
            case USART1_SEL:	CLR_BIT(USART1->CR1,RXNEIE); break;
            case USART2_SEL:	CLR_BIT(USART2->CR1,RXNEIE); break;
            case USART3_SEL:	CLR_BIT(USART3->CR1,RXNEIE); break;
            case UART4_SEL :	CLR_BIT(UART4->CR1,RXNEIE); break;
            case UART5_SEL :	CLR_BIT(UART5->CR1,RXNEIE); break;
        }
    }

}

void UART_voidInit(void)
{
    /*                                   USART 1                               */

#if USART1_ENABLE==ENABLE

    /*USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register */
#if UART1_RX_INTERRUPT_ENABLE == ENABLE
    {
			SET_BIT(USART1->CR1,RXNEIE);
		}
#else
    {
        CLR_BIT(USART1->CR1,RXNEIE);
    }
#endif


#if UART1_TX_INTERRUPT_ENABLE == ENABLE
    {
			SET_BIT(USART1->CR1,TXEIE);
		}
#else
    {
        CLR_BIT(USART1->CR1,TXEIE);
    }
#endif

    /*a parity error occurs in receiver mode*/
#if UART1_PARITY_ERROR == ENABLE
    {
			SET_BIT(USART1->CR1,PCE);
			#if UART1_PARITY_SELECT == UART_PARITY_ODD
			{
				SET_BIT(USART1->CR1,PS);
			}
			#else
			{
				CLR_BIT(USART1->CR1,PS);
			}
			#endif

		}
#else
    {
        CLR_BIT(USART1->CR1,PCE);
    }
#endif

    /*Transmission complete interrupt enable */
#if UART1_TX_COMPLETE_INTERRUPT == ENABLE
    {
			SET_BIT(USART1->CR1,TCIE);
		}
#else
    {
        CLR_BIT(USART1->CR1,TCIE);
    }
#endif


    /*Error Interrupt Enable Bit is required to enable interrupt generation in case of a framing error, overrun error or noise error (FE=1 or ORE=1 or NE=1 in the USART_SR register) in case of Multi Buffer Communication
     * Error interrupt enable */
#if UART1_ERROR_INTERRUPT == ENABLE
    {
			SET_BIT(USART1->CR3,EIE);
		}
#else
    {
        CLR_BIT(USART1->CR3,EIE);
    }
#endif


    /* This bit determines the word length*/
#if UART1_WORD_LENGTH == UART_WORD_9
    {
			SET_BIT(USART1->CR1,M);
		}
#else
    {
        CLR_BIT(USART1->CR1,M);
    }
#endif

    /* DMA enable transmitter*/
#if UART1_DMA_TRANSMITER == ENABLE
    {
			SET_BIT(USART1->CR3,DMAT);
		}
#else
    {
        CLR_BIT(USART1->CR3,DMAT);
    }
#endif

    /* DMA enable Reciever*/
#if UART1_DMA_RECIEVER == ENABLE
    {
			SET_BIT(USART1->CR3,DMAR);
		}
#else
    {
        CLR_BIT(USART1->CR3,DMAR);
    }
#endif

    /* These bits are used for programming the stop bits*/
#if UART1_STOP_BITS_NUM == UART_STOP_BIT_2
    {
			SET_BIT(USART1->CR2,STOP1);
			CLR_BIT(USART1->CR2,STOP0);
		}
#else
    {
        CLR_BIT(USART1->CR2,STOP1);
        CLR_BIT(USART1->CR2,STOP0);
    }
#endif

    /* Clock Polarity -> idel state of the UART*/
#if UART1_CK_POLARITY == UART_CK_HIGH_POLARITY
    {
			SET_BIT(USART1->CR2,CPOL);
		}
#else
    {
        CLR_BIT(USART1->CR2,CPOL);
    }
#endif

    /* Clock Phase -> first edge reading or writing*/
#if UART1_CLK_PHASE == UART_CP_WRITE_READ
    {
        SET_BIT(USART1->CR2,CPHA);
    }
#else
    {
			CLR_BIT(USART1->CR2,CPHA);
		}
#endif



    /*This bit is not available for UART4 & UART5.
     * Clock enable*/
#if UART1_CLK_ENABLE == ENABLE
    {
			SET_BIT(USART1->CR2,CLK_EN);
		}
#else
    {
        CLR_BIT(USART1->CR2,CLK_EN);
    }
#endif

    /* Receiver is enabled and begins searching for a start bit*/
#if UART1_RX_ENABLE == ENABLE
    {
        SET_BIT(USART1->CR1,RE);
    }
#else
    {
			CLR_BIT(USART1->CR1,RE);
		}
#endif

    /*Transimiter enable*/
#if UART1_TX_ENABLE == ENABLE
    {
        SET_BIT(USART1->CR1,TE);
    }
#else
    {
			CLR_BIT(USART1->CR1,TE);
		}
#endif

    /* Power ON the UART */
    SET_BIT(USART1->CR1,UE);

    /* Clearing status register */
    USART1 -> SR = 0;

#endif

#if USART2_ENABLE==ENABLE


    /*USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register */
		#if UART2_RX_INTERRUPT_ENABLE == ENABLE
		{
			SET_BIT(USART2->CR1,RXNEIE);
		}
		#else
		{
			CLR_BIT(USART2->CR1,RXNEIE);
		}
		#endif

		#if UART2_TX_INTERRUPT_ENABLE == ENABLE
		{
			SET_BIT(USART2->CR1,TXEIE);
		}
		#else
		{
			CLR_BIT(USART2->CR1,TXEIE);
		}
		#endif



		/*a parity error occurs in receiver mode*/
		#if UART2_PARITY_ERROR == ENABLE
		{
			SET_BIT(USART2->CR1,PCE);
			#if UART2_PARITY_SELECT == UART_PARITY_ODD
			{
				SET_BIT(USART2->CR1,PS);
			}
			#else
			{
				CLR_BIT(USART2->CR1,PS);
			}
			#endif

		}
		#else
		{
			CLR_BIT(USART2->CR1,PCE);
		}
		#endif

		/*Transmission complete interrupt enable */
		#if UART2_TX_COMPLETE_INTERRUPT == ENABLE
		{
			SET_BIT(USART2->CR1,TCIE);
		}
		#else
		{
			CLR_BIT(USART2->CR1,TCIE);
		}
		#endif


		/*Error Interrupt Enable Bit is required to enable interrupt generation in case of a framing error, overrun error or noise error (FE=1 or ORE=1 or NE=1 in the USART_SR register) in case of Multi Buffer Communication
		 * Error interrupt enable */
		#if UART2_ERROR_INTERRUPT == ENABLE
		{
			SET_BIT(USART2->CR3,EIE);
		}
		#else
		{
			CLR_BIT(USART2->CR3,EIE);
		}
		#endif


		/* This bit determines the word length*/
		#if UART1_WORD_LENGTH == UART_WORD_9
		{
			SET_BIT(USART2->CR1,M);
		}
		#else
		{
			CLR_BIT(USART2->CR1,M);
		}
		#endif

		/* DMA enable transmitter*/
		#if UART2_DMA_TRANSMITER == ENABLE
		{
			SET_BIT(USART2->CR3,DMAT);
		}
		#else
		{
			CLR_BIT(USART2->CR3,DMAT);
		}
		#endif

		/* DMA enable Reciever*/
		#if UART2_DMA_RECIEVER == ENABLE
		{
			SET_BIT(USART2->CR3,DMAR);
		}
		#else
		{
			CLR_BIT(USART2->CR3,DMAR);
		}
		#endif

	   /* These bits are used for programming the stop bits*/
		#if UART2_STOP_BITS_NUM == UART_STOP_BIT_2
		{
			SET_BIT(USART2->CR2,STOP1);
			CLR_BIT(USART2->CR2,STOP0);
		}
		#else
		{
			CLR_BIT(USART2->CR2,STOP1);
			CLR_BIT(USART2->CR2,STOP0);
		}
		#endif

		/* Clock Polarity -> idel state of the UART*/
		#if UART2_CK_POLARITY == UART_CK_HIGH_POLARITY
		{
			SET_BIT(USART2->CR2,CPOL);
		}
		#else
		{
			CLR_BIT(USART2->CR2,CPOL);
		}
		#endif

		/* Clock Phase -> first edge reading or writing*/
		#if UART2_CLK_PHASE == UART_CP_WRITE_READ
		{
			SET_BIT(USART2->CR2,CPHA);
		}
		#else
		{
			CLR_BIT(USART2->CR2,CPHA);
		}
		#endif



	    /*This bit is not available for UART4 & UART5.
		 * Clock enable*/
		#if UART2_CLK_ENABLE == ENABLE
		{
			SET_BIT(USART2->CR2,CLK_EN);
		}
		#else
		{
			CLR_BIT(USART2->CR2,CLK_EN);
		}
		#endif
		/* Receiver is enabled and begins searching for a start bit*/
		#if UART2_RX_ENABLE == ENABLE
		{
			SET_BIT(USART2->CR1,RE);
		}
		#else
		{
			CLR_BIT(USART2->CR1,RE);
		}
		#endif

		/*Transimiter enable*/
		#if UART2_TX_ENABLE == ENABLE
		{
			SET_BIT(USART2->CR1,TE);
		}
		#else
		{
			CLR_BIT(USART2->CR1,TE);
		}
		#endif


		/* Power ON the UART */
		SET_BIT(USART2->CR1,UE);

		/* Clearing status register */
		USART2 -> SR = 0;

#endif

#if USART3_ENABLE==ENABLE


    /*USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register */
		#if UART3_RX_INTERRUPT_ENABLE == ENABLE
		{
			SET_BIT(USART3->CR1,RXNEIE);
		}
		#else
		{
			CLR_BIT(USART3->CR1,RXNEIE);
		}
		#endif



		/*a parity error occurs in receiver mode*/
		#if UART3_PARITY_ERROR == ENABLE
		{
			SET_BIT(USART3->CR1,PCE);
			#if UART3_PARITY_SELECT == UART_PARITY_ODD
			{
				SET_BIT(USART3->CR1,PS);
			}
			#else
			{
				CLR_BIT(USART3->CR1,PS);
			}
			#endif

		}
		#else
		{
			CLR_BIT(USART3->CR1,PCE);
		}
		#endif

		/*Transmission complete interrupt enable */
		#if UART3_TX_COMPLETE_INTERRUPT == ENABLE
		{
			SET_BIT(USART3->CR1,TCIE);
		}
		#else
		{
			CLR_BIT(USART3->CR1,TCIE);
		}
		#endif


		/*Error Interrupt Enable Bit is required to enable interrupt generation in case of a framing error, overrun error or noise error (FE=1 or ORE=1 or NE=1 in the USART_SR register) in case of Multi Buffer Communication
		 * Error interrupt enable */
		#if UART3_ERROR_INTERRUPT == ENABLE
		{
			SET_BIT(USART3->CR3,EIE);
		}
		#else
		{
			CLR_BIT(USART3->CR3,EIE);
		}
		#endif


		/* This bit determines the word length*/
		#if UART3_WORD_LENGTH == UART_WORD_9
		{
			SET_BIT(USART3->CR1,M);
		}
		#else
		{
			CLR_BIT(USART3->CR1,M);
		}
		#endif

		/* DMA enable transmitter*/
		#if UART3_DMA_TRANSMITER == ENABLE
		{
			SET_BIT(USART3->CR3,DMAT);
		}
		#else
		{
			CLR_BIT(USART3->CR3,DMAT);
		}
		#endif

		/* DMA enable Reciever*/
		#if UART3_DMA_RECIEVER == ENABLE
		{
			SET_BIT(USART3->CR3,DMAR);
		}
		#else
		{
			CLR_BIT(USART3->CR3,DMAR);
		}
		#endif

	   /* These bits are used for programming the stop bits*/
		#if UART3_STOP_BITS_NUM == UART_STOP_BIT_2
		{
			SET_BIT(USART3->CR2,STOP1);
			CLR_BIT(USART3->CR2,STOP0);
		}
		#else
		{
			CLR_BIT(USART3->CR2,STOP1);
			CLR_BIT(USART3->CR2,STOP0);
		}
		#endif

		/* Clock Polarity -> idel state of the UART*/
		#if UART3_CK_POLARITY == UART_CK_HIGH_POLARITY
		{
			SET_BIT(USART3->CR2,CPOL);
		}
		#else
		{
			CLR_BIT(USART3->CR2,CPOL);
		}
		#endif

		/* Clock Phase -> first edge reading or writing*/
		#if UART3_CLK_PHASE == UART_CP_WRITE_READ
		{
			SET_BIT(USART3->CR2,CPHA);
		}
		#else
		{
			CLR_BIT(USART3->CR2,CPHA);
		}
		#endif



	    /*This bit is not available for UART4 & UART5.
		 * Clock enable*/
		#if UART3_CLK_ENABLE == ENABLE
		{
			SET_BIT(USART3->CR2,CLK_EN);
		}
		#else
		{
			CLR_BIT(USART3->CR2,CLK_EN);
		}
		#endif
		/* Receiver is enabled and begins searching for a start bit*/
		#if UART3_RX_ENABLE == ENABLE
		{
			SET_BIT(USART3->CR1,RE);
		}
		#else
		{
			CLR_BIT(USART3->CR1,RE);
		}
		#endif

		/*Transimiter enable*/
		#if UART3_TX_ENABLE == ENABLE
		{
			SET_BIT(USART3->CR1,TE);
		}
		#else
		{
			CLR_BIT(USART3->CR1,TE);
		}
		#endif

		/* Power ON the UART */
		SET_BIT(USART3->CR1,UE);

		/* Clearing status register */
		USART3 -> SR = 0;

#endif

#if UART4_ENABLE==ENABLE

    /*USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register */
		#if UART4_RX_INTERRUPT_ENABLE == ENABLE
		{
			SET_BIT(UART4->CR1,RXNEIE);
		}
		#else
		{
			CLR_BIT(UART4->CR1,RXNEIE);
		}
		#endif

		/*a parity error occurs in receiver mode*/
		#if UART4_PARITY_ERROR == ENABLE
		{
			SET_BIT(UART4->CR1,PCE);
			#if UART4_PARITY_SELECT == UART_PARITY_ODD
			{
				SET_BIT(UART4->CR1,PS);
			}
			#else
			{
				CLR_BIT(UART4->CR1,PS);
			}
			#endif

		}
		#else
		{
			CLR_BIT(UART4->CR1,PCE);
		}
		#endif

		/*Transmission complete interrupt enable */
		#if UART4_TX_COMPLETE_INTERRUPT == ENABLE
		{
			SET_BIT(UART4->CR1,TCIE);
		}
		#else
		{
			CLR_BIT(UART4->CR1,TCIE);
		}
		#endif


		/*Error Interrupt Enable Bit is required to enable interrupt generation in case of a framing error, overrun error or noise error (FE=1 or ORE=1 or NE=1 in the USART_SR register) in case of Multi Buffer Communication
		 * Error interrupt enable */
		#if UART4_ERROR_INTERRUPT == ENABLE
		{
			SET_BIT(UART4->CR3,EIE);
		}
		#else
		{
			CLR_BIT(UART4->CR3,EIE);
		}
		#endif


		/* This bit determines the word length*/
		#if UART4_WORD_LENGTH == UART_WORD_9
		{
			SET_BIT(UART4->CR1,M);
		}
		#else
		{
			CLR_BIT(UART4->CR1,M);
		}
		#endif

		/* DMA enable transmitter*/
		#if UART4_DMA_TRANSMITER == ENABLE
		{
			SET_BIT(UART4->CR3,DMAT);
		}
		#else
		{
			CLR_BIT(UART4->CR3,DMAT);
		}
		#endif

		/* DMA enable Reciever*/
		#if UART4_DMA_RECIEVER == ENABLE
		{
			SET_BIT(UART4->CR3,DMAR);
		}
		#else
		{
			CLR_BIT(UART4->CR3,DMAR);
		}
		#endif

	   /* These bits are used for programming the stop bits*/
		#if UART4_STOP_BITS_NUM == UART_STOP_BIT_2
		{
			SET_BIT(UART4->CR2,STOP1);
			CLR_BIT(UART4->CR2,STOP0);
		}
		#else
		{
			CLR_BIT(UART4->CR2,STOP1);
			CLR_BIT(UART4->CR2,STOP0);
		}
		#endif

		/* Clock Polarity -> idel state of the UART*/
		#if UART4_CK_POLARITY == UART_CK_HIGH_POLARITY
		{
			SET_BIT(UART4->CR2,CPOL);
		}
		#else
		{
			CLR_BIT(UART4->CR2,CPOL);
		}
		#endif

		/* Clock Phase -> first edge reading or writing*/
		#if UART4_CLK_PHASE == UART_CP_WRITE_READ
		{
			SET_BIT(UART4->CR2,CPHA);
		}
		#else
		{
			CLR_BIT(UART4->CR2,CPHA);
		}
		#endif



	    /*This bit is not available for UART4 & UART5.
		 * Clock enable*/
		#if UART4_CLK_ENABLE == ENABLE
		{
			SET_BIT(UART4->CR2,CLK_EN);
		}
		#else
		{
			CLR_BIT(UART4->CR2,CLK_EN);
		}
		#endif

		/* Receiver is enabled and begins searching for a start bit*/
		#if UART4_RX_ENABLE == ENABLE
		{
			SET_BIT(UART4->CR1,RE);
		}
		#else
		{
			CLR_BIT(UART4->CR1,RE);
		}
		#endif

		/*Transimiter enable*/
		#if UART4_TX_ENABLE == ENABLE
		{
			SET_BIT(UART4->CR1,TE);
		}
		#else
		{
			CLR_BIT(UART4->CR1,TE);
		}
		#endif

		/* Power ON the UART */
		SET_BIT(UART4->CR1,UE);

		/* Clearing status register */
		UART4 -> SR = 0;

#endif



#if UART5_ENABLE==ENABLE

    /*USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register */
		#if UART5_RX_INTERRUPT_ENABLE == ENABLE
		{
			SET_BIT(UART5->CR1,RXNEIE);
		}
		#else
		{
			CLR_BIT(UART5->CR1,RXNEIE);
		}
		#endif



		/*a parity error occurs in receiver mode*/
		#if UART5_PARITY_ERROR == ENABLE
		{
			SET_BIT(UART5->CR1,PCE);
			#if UART5_PARITY_SELECT == UART_PARITY_ODD
			{
				SET_BIT(UART5->CR1,PS);
			}
			#else
			{
				CLR_BIT(UART5->CR1,PS);
			}
			#endif

		}
		#else
		{
			CLR_BIT(UART5->CR1,PCE);
		}
		#endif

		/*Transmission complete interrupt enable */
		#if UART5_TX_COMPLETE_INTERRUPT == ENABLE
		{
			SET_BIT(UART5->CR1,TCIE);
		}
		#else
		{
			CLR_BIT(UART5->CR1,TCIE);
		}
		#endif


		/*Error Interrupt Enable Bit is required to enable interrupt generation in case of a framing error, overrun error or noise error (FE=1 or ORE=1 or NE=1 in the USART_SR register) in case of Multi Buffer Communication
		 * Error interrupt enable */
		#if UART5_ERROR_INTERRUPT == ENABLE
		{
			SET_BIT(UART5->CR3,EIE);
		}
		#else
		{
			CLR_BIT(UART5->CR3,EIE);
		}
		#endif


		/* This bit determines the word length*/
		#if UART5_WORD_LENGTH == UART_WORD_9
		{
			SET_BIT(UART5->CR1,M);
		}
		#else
		{
			CLR_BIT(UART5->CR1,M);
		}
		#endif

		/* DMA enable transmitter*/
		#if UART5_DMA_TRANSMITER == ENABLE
		{
			SET_BIT(UART5->CR3,DMAT);
		}
		#else
		{
			CLR_BIT(UART4->CR3,DMAT);
		}
		#endif

		/* DMA enable Reciever*/
		#if UART5_DMA_RECIEVER == ENABLE
		{
			SET_BIT(UART5->CR3,DMAR);
		}
		#else
		{
			CLR_BIT(UART5->CR3,DMAR);
		}
		#endif

	   /* These bits are used for programming the stop bits*/
		#if UART5_STOP_BITS_NUM == UART_STOP_BIT_2
		{
			SET_BIT(UART5->CR2,STOP1);
			CLR_BIT(UART5->CR2,STOP0);
		}
		#else
		{
			CLR_BIT(UART5->CR2,STOP1);
			CLR_BIT(UART5->CR2,STOP0);
		}
		#endif

		/* Clock Polarity -> idel state of the UART*/
		#if UART5_CK_POLARITY == UART_CK_HIGH_POLARITY
		{
			SET_BIT(UART5->CR2,CPOL);
		}
		#else
		{
			CLR_BIT(UART5->CR2,CPOL);
		}
		#endif

		/* Clock Phase -> first edge reading or writing*/
		#if UART5_CLK_PHASE == UART_CP_WRITE_READ
		{
			SET_BIT(UART5->CR2,CPHA);
		}
		#else
		{
			CLR_BIT(UART5->CR2,CPHA);
		}
		#endif



	    /*This bit is not available for UART4 & UART5.
		 * Clock enable*/
		#if UART5_CLK_ENABLE == ENABLE
		{
			SET_BIT(UART5->CR2,CLK_EN);
		}
		#else
		{
			CLR_BIT(UART5->CR2,CLK_EN);
		}
		#endif
		/* Receiver is enabled and begins searching for a start bit*/
		#if UART5_RX_ENABLE == ENABLE
		{
			SET_BIT(UART5->CR1,RE);
		}
		#else
		{
			CLR_BIT(UART5->CR1,RE);
		}
		#endif

		/*Transimiter enable*/
		#if UART5_TX_ENABLE == ENABLE
		{
			SET_BIT(UART5->CR1,TE);
		}
		#else
		{
			CLR_BIT(UART5->CR1,TE);
		}
		#endif

		/* Power ON the UART */
		SET_BIT(UART5->CR1,UE);

		/* Clearing status register */
		UART5 -> SR = 0;

#endif
}

void UART_voidSendChar(u8 Copy_u8Char,u8 Copy_u8UARTNumber)
{

    switch(Copy_u8UARTNumber)
    {
        case USART1_SEL:{
            USART1->DR=Copy_u8Char;
            while(GET_BIT(USART1->SR,TC)==0);
            break;
        }

        case USART2_SEL:{
            USART2->DR=Copy_u8Char;
            while(GET_BIT(USART2->SR,TC)==0);
            break;
        }
        case USART3_SEL:{
            USART3->DR=Copy_u8Char;
            while(GET_BIT(USART3->SR,TC)==0);
            break;
        }
        case UART4_SEL:{
            UART4->DR=Copy_u8Char;
            while(GET_BIT(UART4->SR,TC)==0);
            break;
        }
        case UART5_SEL:{
            UART5->DR=Copy_u8Char;
            while(GET_BIT(UART5->SR,TC)==0);
            break;
        }


    }
}

void UART_voidTransmit_Synch(u8 *Copy_pu8Data,u8 Copy_u8UARTNumber)
{
    u8 Local_u8Iterator=0;
    switch(Copy_u8UARTNumber)
    {
        case USART1_SEL:{
            while( Copy_pu8Data[Local_u8Iterator]!='\0')
            {
                USART1->DR=Copy_pu8Data[Local_u8Iterator];
                while(GET_BIT(USART1->SR,TC)==0);
                Local_u8Iterator++;
            }
            break;
        }

        case USART2_SEL:{
            while( Copy_pu8Data[Local_u8Iterator]!='\0')
            {
                USART2->DR=Copy_pu8Data[Local_u8Iterator];
                while(GET_BIT(USART2->SR,TC)==0);
                Local_u8Iterator++;
            }
            break;
        }
        case USART3_SEL:{
            while( Copy_pu8Data[Local_u8Iterator]!='\0')
            {
                USART3->DR=Copy_pu8Data[Local_u8Iterator];
                while(GET_BIT(USART3->SR,TC)==0);
                Local_u8Iterator++;
            }
            break;
        }
        case UART4_SEL :{
            while( Copy_pu8Data[Local_u8Iterator]!='\0')
            {
                UART4->DR=Copy_pu8Data[Local_u8Iterator];
                while(GET_BIT(UART4->SR,TC)==0);
                Local_u8Iterator++;
            }
            break;
        }
        case UART5_SEL :{
            while( Copy_pu8Data[Local_u8Iterator]!='\0')
            {
                UART5->DR=Copy_pu8Data[Local_u8Iterator];
                while(GET_BIT(UART5->SR,TC)==0);
                Local_u8Iterator++;
            }
            break;
        }
    }
}

u8 UART_u8Receive_Synch(u8 Copy_u8UARTNumber)
{
    u8 Local_u8RecievedData=0;

    switch(Copy_u8UARTNumber)
    {
        case USART1_SEL:{
            while(GET_BIT(USART1->SR,RXNE)==0);
            Local_u8RecievedData=USART1->DR;
            break;
        }

        case USART2_SEL:{
            while(GET_BIT(USART2->SR,RXNE)==0);
            Local_u8RecievedData=USART2->DR;
            break;
        }
        case USART3_SEL:{
            while(GET_BIT(USART3->SR,RXNE)==0);
            Local_u8RecievedData=USART3->DR;
            break;
        }
        case UART4_SEL :{
            while(GET_BIT(UART4->SR,RXNE)==0);
            Local_u8RecievedData=UART4->DR;
            break;
        }
        case UART5_SEL :{
            while(GET_BIT(UART5->SR,RXNE)==0);
            Local_u8RecievedData=UART5->DR;
            break;
        }
    }

    return Local_u8RecievedData;
}

void USART_voidReiceve_Asynch(u8 *Copy_pu8DataInterrupt,u8 Copy_u8UARTNumber)
{
    *Copy_pu8DataInterrupt=Global_pu8ReadingData;

    switch(Copy_u8UARTNumber)
    {
        case USART1_SEL:SET_BIT(USART1->CR1,RXNEIE); break;
        case USART2_SEL:SET_BIT(USART2->CR1,RXNEIE); break;
        case USART3_SEL:SET_BIT(USART3->CR1,RXNEIE); break;
        case UART4_SEL :SET_BIT(UART4->CR1,RXNEIE);  break;
        case UART5_SEL :SET_BIT(UART5->CR1,RXNEIE);  break;
    }

}

void UART_ReceiveString(u8 *str)
{
    u8 i = 0;
    str[i] = UART_u8Receive_Synch(0);
    while(str[i] != '#')
    {
        i++;
        str[i] = UART_u8Receive_Synch(0);
    }
    str[i] = '\0';


}

void UART_VoidSendIntNumber(u32 Copy_u32Number, u8 Copy_u8UARTNumber)
{
	u8 Local_Char_Converted[16];
				u32  Local_Temp=Copy_u32Number;
				u8 Counter=0;
				while(Local_Temp>=1)
				{
					Counter++;
					Local_Temp/=10;
				}
				Local_Temp=Copy_u32Number;

				for(u8 i=0;i<Counter;i++)
				{

					Local_Char_Converted[i]=Local_Temp%10+'0';

					Local_Temp/=10;
				}

				for (int i = Counter-1; i >=0 ; i--)
				{
					UART_voidSendChar(Local_Char_Converted[i],Copy_u8UARTNumber);
				}

}

void UART_VoidSendFloatNumber(f64 Copy_f64Number, u8 Copy_u8UARTNumber)
{

    u32 DecimalNum=100000*(Copy_f64Number-(u32)Copy_f64Number);
    UART_VoidSendIntNumber(Copy_f64Number,Copy_u8UARTNumber);
    UART_voidSendChar('.',Copy_u8UARTNumber);
    UART_VoidSendIntNumber(DecimalNum,Copy_u8UARTNumber);



}

static u8 CountParameters(const u8 *String)
{
    u8 counter=0;
    for (u8 i=0; i<strlen(String);i++)
    {
        if(String[i]=='%')
        {
            counter++;
        }

    }

    return counter;
}

void log_print ( const u8 *StringOut ,...)
{
    u32 iterator=0;
    va_list args;
    u8 num=CountParameters(StringOut);
    va_start(args, num);

    while (*StringOut != '\0')
    {
        if ((*StringOut == '%')&&(*(StringOut+1) == 'd'))
        {
            int IntegerNum = (int)va_arg(args, int);

            if(IntegerNum<0)
            	UART_voidSendChar('-',0);

            UART_VoidSendIntNumber(abs(IntegerNum),0);
            ++StringOut;
        }
        else if ((*StringOut == '%')&&(*(StringOut+1) =='f'))
        {
            double FloatNumber =(double ) va_arg(args, double);
            int valInt=(int)FloatNumber;


            if(valInt!=0)
            {
                if(FloatNumber<0)
                	UART_voidSendChar('-',0);
                UART_VoidSendFloatNumber(fabs(FloatNumber), 0);


            }
            else
            {
                if(valInt<0)
                	UART_voidSendChar('-',0);
                UART_VoidSendIntNumber(abs(valInt),0);
            }

            ++StringOut;
        }
        else if ((*StringOut == '%')&&(*(StringOut+1) == 'c'))
        {

            int Char = va_arg(args, int);

            UART_voidSendChar(Char,0);


            ++StringOut;
        }
        else if ((*StringOut == '%')&&(*(StringOut+1) == 's'))
        {
            u8 *String = va_arg(args, int);
            UART_voidTransmit_Synch(String,USART1_SEL);
            ++StringOut;
        }
        else if ((*StringOut == '\\' )&&(*(StringOut+1) == 'n'))
        {

            for(u8 i=0;i<70-iterator;i++)
            {
            	UART_voidSendChar(' ',0);

            }
            iterator=0;
        }
        else if ((*StringOut == '\\')&&(*(StringOut+1) == 't'))
        {
            for(u8 i=0;i<7;i++)
            {
            	UART_voidSendChar(' ',0);
            }
        }


        else
        {

        	UART_voidSendChar(*StringOut,0);

        }
        ++StringOut;
        iterator++;
    }

    va_end(args);


}

u8 UART_u8SetCallBack(void (*UART_Func)(u8),u8 Copy_u8UARTNumber)
{
    u8 local_u8Status=RT_OK  ;

    if(UART_Func!=NULL)
    {

        UART_voidPinter[Copy_u8UARTNumber]=UART_Func;
    }
    else

    {
        local_u8Status=NULL_POINTER  ;
    }

    return local_u8Status;
}

void USART1_IRQHandler(void)
{
    /*Reading the recieved Value */
    Global_pu8ReadingData=USART1->DR;

    CLR_BIT(USART1->SR,RXNE);

    UART_voidPinter[0](Global_pu8ReadingData);

}

void USART2_IRQHandler(void)
{
    /*Reading the recieved Value */
    Global_pu8ReadingData=USART2->DR;


    CLR_BIT(USART2->SR,RXNE);

    UART_voidPinter[1](Global_pu8ReadingData);

}

void USART3_IRQHandler(void)
{
    /*Reading the recieved Value */
    Global_pu8ReadingData=USART3->DR;

    CLR_BIT(USART3->SR,RXNE);

    UART_voidPinter[2](Global_pu8ReadingData);

}

void USART4_IRQHandler(void)
{
    /*Reading the recieved Value */
    Global_pu8ReadingData=UART4->DR;

    CLR_BIT(UART4->SR,RXNE);

    UART_voidPinter[3](Global_pu8ReadingData);

}

void USART5_IRQHandler(void)
{
    /*Reading the recieved Value */
    Global_pu8ReadingData=UART5->DR;

    CLR_BIT(UART5->SR,RXNE);

    UART_voidPinter[4](Global_pu8ReadingData);

}





void MUSART1_voidInit(void)
{
    /*	baud rate = 9600		*/
    USART1 -> BRR = 0x341;

    SET_BIT((USART1-> CR1), 3);			/* Enabling Transmitter */
    SET_BIT((USART1-> CR1), 2);			/* Enabling Receiver */
    SET_BIT((USART1-> CR1), 13);			/* Enabling USART */

    USART1 -> SR = 0;						/* Clearing status register */
}

u8 MUSART1_u8Receive(void)
{
    u8 Loc_u8ReceivedData = 0;
    while((GET_BIT((USART1 -> SR), 5)) == 0);
    Loc_u8ReceivedData = USART1 -> DR;
    return (Loc_u8ReceivedData);
}
void MUSART1_voidTransmit(u8 *arr)
{
    u8 i = 0;
    while(arr[i] != '\0'){
        USART1 -> DR = arr[i];
        while((GET_BIT((USART1 -> SR), 6)) == 0);
        i++;
    }

}




