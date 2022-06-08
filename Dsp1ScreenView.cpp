#include <gui/dsp1screen_screen/Dsp1ScreenView.hpp>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"

extern UART_HandleTypeDef huart5;


Dsp1ScreenView::Dsp1ScreenView():sliderValueConfirmedCallback(this, &Dsp1ScreenView::sliderValueConfirmedCallbackHandler)
{

}

void Dsp1ScreenView::setupScreen()
{
    Dsp1ScreenViewBase::setupScreen();
    slider1.setStopValueCallback(sliderValueConfirmedCallback);
    slider2.setStopValueCallback(sliderValueConfirmedCallback);

    //set the slides to the correct values
    enableButton.setSelected(presenter->getReverbOn());
    enableButton.invalidate();
    slider1.setValue(presenter->getReverbRoom());
    slider1.invalidate();
    slider2.setValue(presenter->getReverbVolume());
    slider2.invalidate();

    //setTexts
    Unicode::snprintf(txt_slider1Buffer, TXT_SLIDER1_SIZE, "%u",slider1.getValue());
	txt_slider1.invalidate();
	Unicode::snprintf(txt_volumeBuffer, TXT_VOLUME_SIZE, "%u",slider2.getValue());
	txt_volume.invalidate();
}

void Dsp1ScreenView::tearDownScreen()
{
	//save the slider values
	presenter->setReverbOn(enableButton.getSelected());
	presenter->setReverbRoom(slider1.getValue());
	presenter->setReverbVolume(slider2.getValue());

    Dsp1ScreenViewBase::tearDownScreen();
}

void Dsp1ScreenView::SendData(uint8_t data[])
{
	//send data through UART5, be sure to have the right #include's
	HAL_UART_Transmit(&huart5,data,sizeof(data),200);
	//HAL_Delay(500);
}

void Dsp1ScreenView::LeaveReverb()
{
	uint8_t data[] = {'<','x','>'};
	SendData(data);
}

void Dsp1ScreenView::EnableReverb()
{
	if(enableButton.getSelected() == true)
	{
		uint8_t data[] = {'<','d',1,'>'};
		SendData(data);
	}else{
		uint8_t data[]= {'<','d',0,'>'};
		SendData(data);
	}
}

void Dsp1ScreenView::sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value)
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
		Unicode::snprintf(txt_volumeBuffer, TXT_VOLUME_SIZE, "%u",value);
		txt_volume.invalidate();
		uint8_t data[] = {'<','c',value,'>'};
		SendData(data);
    }
}
