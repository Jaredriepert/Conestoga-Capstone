#include <gui/dsphomescreen_screen/DspHomeScreenView.hpp>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"

extern UART_HandleTypeDef huart5;

DspHomeScreenView::DspHomeScreenView()
{

}

void DspHomeScreenView::setupScreen()
{
    DspHomeScreenViewBase::setupScreen();
}

void DspHomeScreenView::tearDownScreen()
{
    DspHomeScreenViewBase::tearDownScreen();
}

void DspHomeScreenView::SendData(uint8_t data[])
{
	//send data through UART5, be sure to have the right #include's
	HAL_UART_Transmit(&huart5,data,sizeof(data),200);
	//HAL_Delay(500);
}

void DspHomeScreenView::EnterReverb()
{
	uint8_t data[] = {'<','x','>'};
	SendData(data);
}

void DspHomeScreenView::EnterFilter()
{
	uint8_t data[] = {'<','y','>'};
	SendData(data);
}

void DspHomeScreenView::EnterVolume()
{
	uint8_t data[] = {'<','w','>'};
	SendData(data);
}
