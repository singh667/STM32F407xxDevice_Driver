#ifndef _STM32F407XX_GPIO_H
#define  _STM32F407XX_GPIO_H


/******************************************************************************************************************************************************************* */
/*
 * Author Name   : akshay singh
 * Date          : 03/06/2022
 * File Name     : STM32f407XX_gpio.h
 *
 *
 * This file related to the all address intilization of the all periphearals code intillization and there address
 *
 *
 */


/************************************START TO INCLUDING THE HEADER FILE********************************************************************/

#include <iostream>
using namespace std;


#include "STM32F407xx.h"

/***********************************END INCLUDING HEADER FILE ********************************************************************************/



/* diffrrent mode of the GPIO pin  *
 * @ these all macro related to the -->>>*GPIO port mode register (GPIOx_MODER) (x = A..I/J/K)*
 * These bits are written by software to configure the I/O direction mode.
   @ 00: Input (reset state)
   @ 01: General purpose output mode
   @ 10: Alternate function mode
   @ 11: Analog mode*/

#define GPIO_MODE_INPUT       0
#define GPIO_MODE_OUTPUT      1
#define GPIO_MODE_ALTERNATE   2
#define GPIO_MODE_ANALOG      3

/* These three macro is diffrenct is not relate to the data sheet */
#define GPIO_MODE_IT_FT       4
#define GPIO_MODE_IT_RT       5
#define GPIO_MODE_IT_RFT      6

/*********************************************end of mode ***************************************************/



/* diffrent mode of GPIO output *
 * @ these all macros related to the ---->GPIO port output type register (GPIOx_OTYPER)
 * @ 0: Output push-pull (reset state)
   @ 1: Output open-drain*/

#define GPIO_OUTPUT_PUSHPULL     0
#define GPIO_OUTPUT_OPENDRAIN    1

/*************************************** end of the GPIO output mode ****************************************/



/*diffrent speed mode of GPIO port
 *  these all macro related to this registor---->GPIO port output speed register (GPIOx_OSPEEDR)
(x = A..I/J/K*\
These bits are written by software to configure the I/O output speed.
	@ 00: Low speed
	@ 01: Medium speed
	@ 10: High speed
1@ 1: Very high speed*/


#define GPIO_LOW_SPEED          0
#define GPIO_MEDIUM_SPEDD       1
#define GPIO_HIGH_SPEED         2
#define GPIO_VERY_HIGH_SPEED    3

/****************************end of the diffrent speed mode *************************************************/




/* GPIO diffrent mode of pull up and pull down
 *  these all macro related to the registor --------->GPIO port pull-up/pull-down register (GPIOx_PUPDR)
(x = A..I/J/K)
These bits are written by software to configure the I/O pull-up or pull-down
	@ 00: No pull-up, pull-down
	@ 01: Pull-up
	@ 10: Pull-down
	@ 11: Reserved*/
#define GPIO_NPULLUP_NOPULLDOWN     0
#define GPIO_PULLP                  1
#define GPIO_PULLDOWN               2

/***********************end of diffrent mode of pull and pull down  *******************************************/



/* this structure related to the configuration pin No */
typedef struct{

	uint8_t GPIO_PinNumber;    /* <! value passess PIN Number  */
	uint8_t GPIO_PinMode;      /* <! value passess PIN Mode  */
	uint8_t GPIO_PinSpeed;     /*<! value passess PIN speed  */
	uint8_t GPIO_PinOutput;    /*<! value passess PIN output  */
	uint8_t GPIO_PinpullUpPd;  /*<! value passess PIN pull and pulldown  */
	uint8_t GPIO_PinaltMethod; /*<! value passess PIN method  */

}gpio_configuration_t;

/* *************************************end of the configuration structure ***************************************************************/


/* deifne the diffrent pin number because every port have 15 pin configuration registor  */
#define GPIO_PIN_0               0
#define GPIO_PIN_1               1
#define GPIO_PIN_2               2
#define GPIO_PIN_3               3
#define GPIO_PIN_4               4
#define GPIO_PIN_5               5
#define GPIO_PIN_6               6
#define GPIO_PIN_7               7
#define GPIO_PIN_8               8
#define GPIO_PIN_9               9
#define GPIO_PIN_10             10
#define GPIO_PIN_11             11
#define GPIO_PIN_12             12
#define GPIO_PIN_13             13
#define GPIO_PIN_14             14
#define GPIO_PIN_15             15

/************************************ end defination of PIN number ****************************************************************************/


class gpio_handl_t{

	public:

	/* this is the instance of the GPIO port */
	GPIO_TypeDef *pGPIOx;

	/* this is the configuration structure pointer */
	gpio_configuration_t  pGPIOx_Config;


	EXTI_TypeDef *Exti;


	public:

	/* GPIO peripheral clock control enable the clock for particular peripherals */
	void GPIO_PeripheralClockControle(GPIO_TypeDef *pGPIOx,uint8_t EnorDi);

	/*GPIO intilization */
	void GPIO_Init(gpio_handl_t& gpio_handle);

	/* GPIO de-intilization for paritcular port  */
	void GPIO_DeInit(GPIO_TypeDef *pGPIOx);

	/*GPIO Read from INput for particular pin number */
	uint8_t GPIO_ReadFromInputPin(GPIO_TypeDef *pGPIOx,uint8_t PinNumber);

	/*GPIO Read from INput port */
	uint16_t GPIO_ReadFromInputPort(GPIO_TypeDef *pGPIOx);

	/* GPIO write on particular pin */
	void GPIO_WriteToOutputPin(GPIO_TypeDef *pGPIOx,uint8_t PinNumber,uint8_t Value);

	/*GPIO write from output Port */
	void GPIO_WriteToOutputPort(GPIO_TypeDef *pGPIOx,uint16_t Value);

	/*GPIO toggle from output pin */
	void GPIO_ToggleOutPutPin(GPIO_TypeDef *pGPIOx,uint8_t PinNumber);

	/* GPIO IRQ configuration */
	void GPIO_IRQConfig(uint8_t IRQNUmber,uint8_t IRQPriority,uint8_t EnorDi);

	/*GPIO IRQ handler */
	void GPIO_IRQHandling(uint8_t PinNumber);


	void my_delay();

};


//#include "STM32F407xx_gpio.cpp"


#endif


