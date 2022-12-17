/******************************************************************************************************************************************************************* */
/*
 * Author Name   : akshay singh
 * Date          : 03/06/2022
 * File Name     : STM32f407_gpio.h
 *
 *
 * This file related to the all address intilization of the all periphearals code intillization and there address
 *
 *
 */
#ifndef _STM32F407XX_GPIO_CPP
#define  _STM32F407XX_GPIO_CPP


#include "STM32F407xx_gpio.h"



/*  peripheral gpio declration */

#define  GPIO_PIN_0         0
#define  GPIO_PIN_1         1
#define  GPIO_PIN_2         2
#define  GPIO_PIN_3         3
#define  GPIO_PIN_4         4
#define  GPIO_PIN_5         5
#define  GPIO_PIN_6         6
#define  GPIO_PIN_7         7
#define  GPIO_PIN_8         8
#define  GPIO_PIN_9         9
#define  GPIO_PIN_10        10
#define  GPIO_PIN_11        11
#define  GPIO_PIN_12        12
#define  GPIO_PIN_13        13
#define  GPIO_PIN_14        14
#define  GPIO_PIN_15        15

/* end of the GPIO declration */




/* diffrrent mode of the GPIO pin  *
 * @ these all macro related to the -->>>*GPIO port mode register (GPIOx_MODER) (x = A..I/J/K)*
 * These bits are written by software to configure the I/O direction mode.
   @ 00: Input (reset state)
   @ 01: General purpose output mode
   @ 10: Alternate function mode
   @ 11: Analog mode*/


#define GPIO_MODE_INP   0x00
#define GPIO_MODE_OUT   0x01
#define GPIO_MODE_ALT   0x10
#define GPIO_MODE_ANL   0x11

/************************ end of the GPIO mode registor ****************************************************/














/* ******************start all function defination ******************************************************/

/**********************************************************************************************************
 * @function name           :  GPIO_PeripheralClockControle
 *
 * @description             :
 *
 * @param[in]               :
 *
 *
 *
 * @return                  :
 *
 * @Note                    :
 *********************************************************************************************************/


void gpio_handl_t::GPIO_PeripheralClockControle(GPIO_TypeDef *pGPIOx,uint8_t EnOrDi){

	if(EnOrDi==ENABLE){

		if(pGPIOx==GPIOA){
			GPIOA_CLOCK_ENABLE();

		}else if(pGPIOx==GPIOB){
			GPIOB_CLOCK_ENABLE();

		}else if(pGPIOx==GPIOC){
			GPIOC_CLOCK_ENABLE();

		}else if(pGPIOx==GPIOD){
			GPIOD_CLOCK_ENABLE();

		}else if(pGPIOx==GPIOE){
			GPIOE_CLOCK_ENABLE();

		}else if(pGPIOx==GPIOF){
			GPIOF_CLOCK_ENABLE();

		}else if(pGPIOx==GPIOG){
			GPIOG_CLOCK_ENABLE();

		}else if(pGPIOx==GPIOH){
			GPIOH_CLOCK_ENABLE();

		}else if(pGPIOx==GPIOI){
			GPIOI_CLOCK_ENABLE();

		}else if(pGPIOx==GPIOJ){
			GPIOJ_CLOCK_ENABLE();

		}else if(pGPIOx==GPIOK){
			GPIOK_CLOCK_ENABLE();

		}else {

			//No extera port is avaialable
		}
	}else if(EnOrDi==DISABLE){

		if(pGPIOx==GPIOA){
			GPIOA_CLOCK_DISABLE();

		}else if(pGPIOx==GPIOB){
			GPIOB_CLOCK_DISABLE();

		}else if(pGPIOx==GPIOC){
			GPIOC_CLOCK_DISABLE();

		}else if(pGPIOx==GPIOD){
			GPIOD_CLOCK_DISABLE();

		}else if(pGPIOx==GPIOE){
			GPIOE_CLOCK_DISABLE();

		}else if(pGPIOx==GPIOF){
			GPIOF_CLOCK_DISABLE();

		}else if(pGPIOx==GPIOG){
			GPIOG_CLOCK_DISABLE();

		}else if(pGPIOx==GPIOH){
			GPIOH_CLOCK_DISABLE();

		}else if(pGPIOx==GPIOI){
			GPIOI_CLOCK_DISABLE();

		}else if(pGPIOx==GPIOJ){
			GPIOJ_CLOCK_DISABLE();

		}else if(pGPIOx==GPIOK){
			GPIOK_CLOCK_DISABLE();

		}else {

			//No extera port is avaialable
		}
	}else{
		//NO extra operation
	}

}

/**********************************************************************************************************
 * @function name           :
 *
 * @description             :
 *
 * @param[in]               :
 *
 *
 *
 * @return                  :
 *
 * @Note                    :
 *********************************************************************************************************/

void gpio_handl_t::GPIO_Init(gpio_handl_t &gpio_handle){

	uint32_t regTemp=0;

	if(gpio_handle.pGPIOx_Config.GPIO_PinMode <=GPIO_MODE_ANALOG){

		regTemp=gpio_handle.pGPIOx_Config.GPIO_PinMode << (2 *gpio_handle.pGPIOx_Config.GPIO_PinNumber);

		gpio_handle.pGPIOx->MODER &= ~(0x3 << gpio_handle.pGPIOx_Config.GPIO_PinNumber);
		gpio_handle.pGPIOx->MODER |= regTemp;
	}else{

		/* here we did the interrupt configuration */
		if(gpio_handle.pGPIOx_Config.GPIO_PinMode==GPIO_MODE_IT_FT){

			Exti->FTSR |= (1<<gpio_handle.pGPIOx_Config.GPIO_PinNumber);

			Exti->RTSR &= ~(1<<gpio_handle.pGPIOx_Config.GPIO_PinNumber);
			/* here we configure the falling edge trigger registor */

		}else if(gpio_handle.pGPIOx_Config.GPIO_PinMode==GPIO_MODE_IT_RT){

			/* here we configure the rising edge trigger */
			Exti->RTSR |= (1<<gpio_handle.pGPIOx_Config.GPIO_PinNumber);

			Exti->FTSR &= ~(1<<gpio_handle.pGPIOx_Config.GPIO_PinNumber);

		}else if(gpio_handle.pGPIOx_Config.GPIO_PinMode==GPIO_MODE_IT_RFT){

			/* here we configure the rising and falling edge trigger */
			Exti->RTSR |= (1<<gpio_handle.pGPIOx_Config.GPIO_PinNumber);

			Exti->FTSR |= (1<<gpio_handle.pGPIOx_Config.GPIO_PinNumber);
		}


		Exti->IMR |= (1<<gpio_handle.pGPIOx_Config.GPIO_PinNumber);
	}


	regTemp=0;
	regTemp=gpio_handle.pGPIOx_Config.GPIO_PinSpeed << (2 *gpio_handle.pGPIOx_Config.GPIO_PinNumber);
	gpio_handle.pGPIOx->OSPEEDR &=~(0x3 << gpio_handle.pGPIOx_Config.GPIO_PinNumber);
	gpio_handle.pGPIOx->OSPEEDR |= regTemp;


	regTemp=0;
	regTemp=gpio_handle.pGPIOx_Config.GPIO_PinOutput << gpio_handle.pGPIOx_Config.GPIO_PinNumber;
	gpio_handle.pGPIOx->PUPDR &=~(0x1 << gpio_handle.pGPIOx_Config.GPIO_PinNumber);
	gpio_handle.pGPIOx->OTYPER |= regTemp;

	regTemp=0;
	regTemp=gpio_handle.pGPIOx_Config.GPIO_PinpullUpPd << (2 *gpio_handle.pGPIOx_Config.GPIO_PinNumber);
	gpio_handle.pGPIOx->PUPDR &=~(0x3 << gpio_handle.pGPIOx_Config.GPIO_PinNumber);
	gpio_handle.pGPIOx->PUPDR |= regTemp;

	if(gpio_handle.pGPIOx_Config.GPIO_PinMode <=GPIO_MODE_ALTERNATE){

		uint8_t altRegtemp1=0,altRegTemp2=0;
		altRegtemp1=gpio_handle.pGPIOx_Config.GPIO_PinNumber/8;
		altRegTemp2=gpio_handle.pGPIOx_Config.GPIO_PinNumber % 8;
		gpio_handle.pGPIOx->AFR[altRegtemp1]&= ~(0xF <<(4 * altRegTemp2));

		gpio_handle.pGPIOx->AFR[altRegtemp1]|= gpio_handle.pGPIOx_Config.GPIO_PinaltMethod <<(4 * altRegTemp2);


	}


}


	/**********************************************************************************************************
	 * @function name           :
	 *
	 * @description             :
	 *
	 * @param[in]               :
	 *
	 *
	 *
	 * @return                  :
	 *
	 * @Note                    :
	 *********************************************************************************************************/

void gpio_handl_t::GPIO_DeInit(GPIO_TypeDef *pGPIOx){



	if(pGPIOx==GPIOA){
		GPIOA_CLOCK_DISABLE();

	}else if(pGPIOx==GPIOB){
		GPIOB_CLOCK_DISABLE();

	}else if(pGPIOx==GPIOC){
		GPIOC_CLOCK_DISABLE();

	}else if(pGPIOx==GPIOD){
		GPIOD_CLOCK_DISABLE();

	}else if(pGPIOx==GPIOE){
		GPIOE_CLOCK_DISABLE();

	}else if(pGPIOx==GPIOF){
		GPIOF_CLOCK_DISABLE();

	}else if(pGPIOx==GPIOG){
		GPIOG_CLOCK_DISABLE();

	}else if(pGPIOx==GPIOH){
		GPIOH_CLOCK_DISABLE();

	}else if(pGPIOx==GPIOI){
		GPIOI_CLOCK_DISABLE();

	}else if(pGPIOx==GPIOJ){
		GPIOJ_CLOCK_DISABLE();

	}else if(pGPIOx==GPIOK){
		GPIOK_CLOCK_DISABLE();
	}
}


	/**********************************************************************************************************
	 * @function name           :
	 *
	 * @description             :
	 *
	 * @param[in]               :
	 *
	 *
	 *
	 * @return                  :
	 *
	 * @Note                    :
	 *********************************************************************************************************/

uint8_t gpio_handl_t::GPIO_ReadFromInputPin(GPIO_TypeDef *pGPIOx,uint8_t PinNumber){

	uint8_t readRegValue=0;

	readRegValue=((pGPIOx->IDR >> PinNumber) & 0x00000001);

	return readRegValue;
}


	/**********************************************************************************************************
	 * @function name           :
	 *
	 * @description             :
	 *
	 * @param[in]               :
	 *
	 *
	 *
	 * @return                  :
	 *
	 * @Note                    :
	 *********************************************************************************************************/

	uint16_t gpio_handl_t::GPIO_ReadFromInputPort(GPIO_TypeDef *pGPIOx){



		uint8_t readRegValue=0;

		readRegValue=pGPIOx->IDR ;

		return readRegValue;
	}



	/**********************************************************************************************************
	 * @function name           :
	 *
	 * @description             :
	 *
	 * @param[in]               :
	 *
	 *
	 *
	 * @return                  :
	 *
	 * @Note                    :
	 *********************************************************************************************************/

	void gpio_handl_t::GPIO_WriteToOutputPin(GPIO_TypeDef *pGPIOx,uint8_t PinNumber,uint8_t Value){

		if(Value==GPIO_PIN_SET){
			pGPIOx->ODR |= (Value<<PinNumber);
		}else{
			pGPIOx->ODR &=(Value<<PinNumber);
		}

	}



	/**********************************************************************************************************
	 * @function name           :
	 *
	 * @description             :
	 *
	 * @param[in]               :
	 *
	 *
	 *
	 * @return                  :
	 *
	 * @Note                    :
	 *********************************************************************************************************/

	void gpio_handl_t::GPIO_WriteToOutputPort(GPIO_TypeDef *pGPIOx,uint16_t Value){

		pGPIOx->ODR =Value;
	}


	/**********************************************************************************************************
	 * @function name           :
	 *
	 * @description             :
	 *
	 * @param[in]               :
	 *
	 *
	 *
	 * @return                  :
	 *
	 * @Note                    :
	 *********************************************************************************************************/

	void gpio_handl_t::GPIO_ToggleOutPutPin(GPIO_TypeDef *pGPIOx,uint8_t PinNumber){

		pGPIOx->ODR ^= (1<<PinNumber);


	}



	/**********************************************************************************************************
	 * @function name           :
	 *
	 * @description             :
	 *
	 * @param[in]               :
	 *
	 *
	 *
	 * @return                  :
	 *
	 * @Note                    :
	 *********************************************************************************************************/

	void gpio_handl_t::GPIO_IRQConfig(uint8_t IRQNUmber,uint8_t IRQPriority,uint8_t EnorDi){


	}



	/**********************************************************************************************************
	 * @function name           :
	 *
	 * @description             :
	 *
	 * @param[in]               :
	 *
	 *
	 *
	 * @return                  :
	 *
	 * @Note                    :
	 *********************************************************************************************************/

void gpio_handl_t::GPIO_IRQHandling(uint8_t PinNumber){

}

void gpio_handl_t::my_delay(){

	uint32_t i=0;
    for(i=0;i<500000;i++);

}
#endif
