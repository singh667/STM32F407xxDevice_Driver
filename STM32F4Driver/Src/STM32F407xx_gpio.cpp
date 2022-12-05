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






/* here we declare the mode registor of the GPIO pin */


#define GPIO_MODE_INP   0x00
#define GPIO_MODE_OUT   0x01
#define GPIO_MODE_ALT   0x10
#define GPIO_MODE_ANL   0x11





/* here we declare the mode type of Registor of the GPIO pin












/* start all function defination */

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


void gpio_handl_t::GPIO_PeripheralClockControle(GPIO_TypeDef *pGPIOx,uint8_t ENOrDi){

	if(ENOrDI==ENABLE){

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
	}else if(ENorDI==DISABLE){

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

void gpio_handl_t::GPIO_Init(gpio_handl_t& gpio_handle){

	uint32_t regTemp=0;

	if(gpio_handle.pGPIOx_Config.GPIO_PinMode <=GPIO_MODE_ANALOG){

		regTemp=gpio_handle.pGPIOx_Config.GPIO_PinMode << (2 *gpio_handle.pGPIOx_Config.GPIO_PinNumber);

		gpio_handle.pGPIOx->MODER &= ~(0x3 << gpio_handle.pGPIOx_Config.GPIO_PinNumber);
		gpio_handle.pGPIOx->MODER |= regTemp;
	}else{
		// will we do later for interrupt;
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

void GPIO_DeInit(GPIO_TypeDef *pGPIOx){



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


uint8_t GPIO_ReadFromInputPin(GPIO_TypeDef *pGPIOx,uint8_t PinNumber){

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

	uint16_t GPIO_ReadFromInputPort(GPIO_TypeDef *pGPIOx);



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

	void GPIO_WriteToOutputPin(GPIO_TypeDef *pGPIOx,uint8_t PinNumber,unit8_t Value);



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

	void GPIO_WriteToOutputPort(GPIO_TypeDef *pGPIOx,uint16_t Value);


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

	void GPIO_ToggleOutPutPin(GPIO_TypeDef *pGPIOx,uint8_t PinNumber);



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

	void GPIO_IRQConfig(uint8_t IRQNUmber,uint8_t IRQPriority,unit8_t EnorDi);



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

	void GPIO_IRQHandling(uint8_t PinNumber);
