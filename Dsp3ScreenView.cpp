#include <gui/dsp3screen_screen/Dsp3ScreenView.hpp>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"

extern UART_HandleTypeDef huart5;

Dsp3ScreenView::Dsp3ScreenView():sliderValueConfirmedCallback(this, &Dsp3ScreenView::sliderValueConfirmedCallbackHandler)
{

}

void Dsp3ScreenView::setupScreen()
{
    Dsp3ScreenViewBase::setupScreen();
    slider1.setStopValueCallback(sliderValueConfirmedCallback);
    slider2.setStopValueCallback(sliderValueConfirmedCallback);

    //set the slides to the correct values
    slider1.setValue(presenter->getVolumeIn());
    slider1.invalidate();
    slider2.setValue(presenter->getVolumeOut());
    slider2.invalidate();

    //set Texts
    Unicode::snprintf(txt_slider1Buffer, TXT_SLIDER1_SIZE, "%u",slider1.getValue());
	txt_slider1.invalidate();
	Unicode::snprintf(txt_slider2Buffer, TXT_SLIDER2_SIZE, "%u",slider2.getValue());
	txt_slider2.invalidate();
}

void Dsp3ScreenView::tearDownScreen()
{
	presenter->setVolumeIn(slider1.getValue());
	presenter->setVolumeOut(slider2.getValue());
	LeaveVolume();
    Dsp3ScreenViewBase::tearDownScreen();
}

void Dsp3ScreenView::SendData(uint8_t data[])
{
	//send data through UART5, be sure to have the right #include's
	HAL_UART_Transmit(&huart5,data,sizeof(data),200);
	//HAL_Delay(500);
}

void Dsp3ScreenView::LeaveVolume()
{
	uint8_t data[] = {'<','w','>'};
	SendData(data);
}

void Dsp3ScreenView::sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &slider1)
    {
        //Interaction1
        //When slider1 value changed set Delay Text
		Unicode::snprintf(txt_slider1Buffer, TXT_SLIDER1_SIZE, "%u",value);
		txt_slider1.invalidate();
		uint8_t data[] = {'<','b',value,'>'};
		SendData(data);
    }
    if (&src == &slider2)
    {
        //Interaction2
        //When slider1 value changed set Volume Text
		Unicode::snprintf(txt_slider2Buffer, TXT_SLIDER2_SIZE, "%u",value);
		txt_slider2.invalidate();
		uint8_t data[] = {'<','c',value,'>'};
		SendData(data);
    }
}
