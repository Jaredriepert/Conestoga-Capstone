#include <gui/homescreen_screen/HomeScreenView.hpp>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"

extern UART_HandleTypeDef huart5;

HomeScreenView::HomeScreenView()
{

}

void HomeScreenView::setupScreen()
{
    HomeScreenViewBase::setupScreen();
}

void HomeScreenView::tearDownScreen()
{
    HomeScreenViewBase::tearDownScreen();
}

void HomeScreenView::SendData()
{
	//data to be sent
	//uint8_t data[] = "You pressed a button! \r\n";
	uint8_t data[] = {1,2,3,4,5};
	//send data through UART5, be sure to have the right #include's
	HAL_UART_Transmit(&huart5,data,sizeof(data),200);
	HAL_Delay(500);
}
