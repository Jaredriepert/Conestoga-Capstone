#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <gui/common/FrontendApplication.hpp>
#include "stm32f4xx_hal.h"

Model::Model() : modelListener(0) ,profNum(1), pro1effect1(0), pro1effect2(0), pro1effect3(0), pro2effect1(0), pro2effect2(0), pro2effect3(0),
				pro3effect1(0), pro3effect2(0), pro3effect3(0), soundOn(true),
				pro1_b1_1(false) , pro1_b1_2(false) , pro1_b1_3(false) , pro1_b2_1(false) , pro1_b2_2(false) , pro1_b2_3(false) , pro1_b3_1(false) , pro1_b3_2(false) , pro1_b3_3(false),
				pro1_pedal1_on(true),pro1_pedal2_on(true), pro1_pedal3_on(true),
				pro2_b1_1(false) , pro2_b1_2(false) , pro2_b1_3(false) , pro2_b2_1(false) , pro2_b2_2(false) , pro2_b2_3(false) , pro2_b3_1(false) , pro2_b3_2(false) , pro2_b3_3(false),
				pro2_pedal1_on(true),pro2_pedal2_on(true), pro2_pedal3_on(true),
				pro3_b1_1(false) , pro3_b1_2(false) , pro3_b1_3(false) , pro3_b2_1(false) , pro3_b2_2(false) , pro3_b2_3(false) , pro3_b3_1(false) , pro3_b3_2(false) , pro3_b3_3(false),
				pro3_pedal1_on(true),pro3_pedal2_on(true), pro3_pedal3_on(true),
				reverb_on(false), reverb_room(50), reverb_volume(100), filter_bp(7), filter_q(10), filter_base(50), filter_mid(30), filter_high(50), volume_in(100), volume_out(100)
{

}

void Model::tick()
{
	/*
	 * This code will read the value of a GPIO pin and send a key event code to the front end application t handle it
	 * Meaning, if the current screen has an event for a specific key press, then this is where that key press can be recorded and sent
	 */
//	if ((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET && filter == false) ) // GPIOA_0 is user button 1
//	 {
//		filter = true;
//		static_cast<FrontendApplication*>(Application::getInstance())->handleKeyEvent(88); // send code 88 to screen to handle
//	 }

	if ((HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8) == GPIO_PIN_SET && filter1 == false) ) // GPIOC_8 is Foot Switch 1
	 {
		filter1 = true;
		static_cast<FrontendApplication*>(Application::getInstance())->handleKeyEvent(11); // send code 11 to screen to handle
	 }

	if ((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9) == GPIO_PIN_SET && filter2 == false) ) // GPIOA_9 is OLD Foot Switch 2, GPIOD_4 is new
	 {
		filter2 = true;
		static_cast<FrontendApplication*>(Application::getInstance())->handleKeyEvent(12); // send code 12 to screen to handle
	 }

	if ((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) == GPIO_PIN_SET && filter3 == false) ) // GPIOA_10 is OLD Foot Switch 3, GPIOD_5 is new
	 {
		filter3 = true;
		static_cast<FrontendApplication*>(Application::getInstance())->handleKeyEvent(13); // send code 13 to screen to handle
	 }

	if ((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == GPIO_PIN_SET && filter4 == false) ) // GPIOA_13 is Foot Switch 4
	 {
		filter4 = true;
		static_cast<FrontendApplication*>(Application::getInstance())->handleKeyEvent(14); // send code 14 to screen to handle
	 }

	//Turn off the filter variable when no button is pressed
	if((HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8) == GPIO_PIN_RESET && filter1 == true))
	 {
		//delay to stop button bouncing effect
		HAL_Delay(500);
		filter1 = false;
	 }

	//Turn off the filter variable when no button is pressed
	if((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9) == GPIO_PIN_RESET && filter2 == true))
	 {
		//delay to stop button bouncing effect
		HAL_Delay(500);
		filter2 = false;
	 }

	//Turn off the filter variable when no button is pressed
	if((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) == GPIO_PIN_RESET && filter3 == true))
	 {
		//delay to stop button bouncing effect
		HAL_Delay(500);
		filter3 = false;
	 }

	//Turn off the filter variable when no button is pressed
	if((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == GPIO_PIN_RESET && filter4 == true))
	 {
		//delay to stop button bouncing effect
		HAL_Delay(500);
		filter4 = false;
	 }


}

