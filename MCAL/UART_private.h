/****************************************************************************************************************************************/
/***********************************************	Author  : ABS Team  	*************************************************************/
/***********************************************	Date    : 1 -2 -2022    *************************************************************/
/***********************************************	Version : V1            *************************************************************/
/****************************************************************************************************************************************/
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/*
 * Registers Base addresses
 */
#define USART1_BASE_ADDRESS     0x40011000
#define USART2_BASE_ADDRESS     0x40004400 
#define USART3_BASE_ADDRESS     0x40004800
#define UART4_BASE_ADDRESS     	0x40004C00
#define UART5_BASE_ADDRESS      0x40005000

/*================================ Regirters Difinition using struct ========================================*/
/*===========================================================================================================*/
typedef struct
{
	volatile u32 SR  ;
	volatile u32 DR  ;
	volatile u32 BRR ;
	volatile u32 CR1 ;
	volatile u32 CR2 ;
	volatile u32 CR3 ;
	volatile u32 GTPR;

}UART_t;

#define USART1    ((UART_t*)USART1_BASE_ADDRESS)
#define USART2    ((UART_t*)USART2_BASE_ADDRESS)
#define USART3    ((UART_t*)USART3_BASE_ADDRESS)
#define UART4     ((UART_t*)UART4_BASE_ADDRESS )
#define UART5     ((UART_t*)UART5_BASE_ADDRESS )



enum UARTx_SR
{
	PE   ,
	FE   ,
	NF   ,
	ORE  ,
	IDLE ,
	RXNE ,
	TC   ,
	TXE  ,
	LBD  ,
	CTS

};

enum  UARTx_CR1
{
	SBK    		,
	RWU    		,
	RE     		,
	TE     		,
	IDLEIE 		,
	RXNEIE 		,
	TCIE   		,
	TXEIE  		,
	PEIE   		,
	PS     		,
	PCE    		,
	WAKE   		,
	M      		,
	UE	   		,
	OVER8=15
};

enum UARTx_CR2
{
	ADD0    ,
	ADD1    ,
	ADD2    ,
	ADD3    ,
	LBDL=5  ,
	LBDIE   ,
	LBCL=8  ,
	CPHA    ,
	CPOL    ,
	CLK_EN  ,
	STOP0   ,
	STOP1   ,
	LINEN

};


enum UARTx_CR3
{
	EIE    ,
	IREN   ,
	IRLP   ,
	HDSEL  ,
	NACK   ,
	SCEN   ,
	DMAR   ,
	DMAT   ,
	RTSE   ,
	CTSE   ,
	CTSIE  ,
	ONEBIT
};



#endif
