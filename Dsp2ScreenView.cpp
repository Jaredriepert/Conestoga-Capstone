#include <gui/dsp2screen_screen/Dsp2ScreenView.hpp>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"

extern UART_HandleTypeDef huart5;


Dsp2ScreenView::Dsp2ScreenView():sliderValueConfirmedCallback(this, &Dsp2ScreenView::sliderValueConfirmedCallbackHandler)
{

}

void Dsp2ScreenView::setupScreen()
{
    Dsp2ScreenViewBase::setupScreen();
    slider1.setStopValueCallback(sliderValueConfirmedCallback);
    slider2.setStopValueCallback(sliderValueConfirmedCallback);
    slidervl.setStopValueCallback(sliderValueConfirmedCallback);
    slidervbp.setStopValueCallback(sliderValueConfirmedCallback);
    slidervh.setStopValueCallback(sliderValueConfirmedCallback);

    //set the slides to the correct values
    slider1.setValue(presenter->getFilterBp());
    slider1.invalidate();
    slider2.setValue(presenter->getFilterQ());
    slider2.invalidate();
    slidervl.setValue(presenter->getFilterBase());
    slidervl.invalidate();
    slidervbp.setValue(presenter->getFilterMid());
    slidervbp.invalidate();
    slidervh.setValue(presenter->getFilterHigh());
    slidervh.invalidate();

    //set Texts
    Unicode::snprintf(txt_slider1Buffer, TXT_SLIDER1_SIZE, "%u",slider1.getValue());
	txt_slider1.invalidate();
	Unicode::snprintf(txt_slider2Buffer, TXT_SLIDER2_SIZE, "%u",slider2.getValue());
	txt_slider2.invalidate();
	Unicode::snprintf(txt_vlBuffer, TXT_VL_SIZE, "%u",slidervl.getValue());
	txt_vl.invalidate();
	Unicode::snprintf(txt_vbpBuffer, TXT_VBP_SIZE, "%u",slidervbp.getValue());
	txt_vbp.invalidate();
	Unicode::snprintf(txt_vhBuffer, TXT_VH_SIZE, "%u",slidervh.getValue());
	txt_vh.invalidate();

}

void Dsp2ScreenView::tearDownScreen()
{
	presenter->setFilterBp(slider1.getValue());
	presenter->setFilterQ(slider2.getValue());
	presenter->setFilterBase(slidervl.getValue());
	presenter->setFilterMid(slidervbp.getValue());
	presenter->setFilterHigh(slidervh.getValue());

    Dsp2ScreenViewBase::tearDownScreen();
}

void Dsp2ScreenView::SendData(uint8_t data[])
{
	//send data through UART5, be sure to have the right #include's
	HAL_UART_Transmit(&huart5,data,sizeof(data),200);
	//HAL_Delay(500);
}

void Dsp2ScreenView::LeaveFilter()
{
	uint8_t data[] = {'<','y','>'};
	SendData(data);
}

//void Dsp2ScreenView::EnableReverb()
//{
//	if(enableButton.getSelected() == true)
//	{
//		uint8_t data[] = {'<','d',1,'>'};
//		SendData(data);
//	}else{
//		uint8_t data[]= {'<','d',0,'>'};
//		SendData(data);
//	}
//}

void Dsp2ScreenView::sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &slider1)
    {
        //Interaction1
    	//When slider1 value move update slider1 text
		Unicode::snprintf(txt_slider1Buffer, TXT_SLIDER1_SIZE, "%u",value);
		txt_slider1.invalidate();
		uint8_t data[] = {'<','b',value,'>'};
		SendData(data);
    }
    if (&src == &slider2)
    {
        //Interaction2
        //When slider2 value move update slider2 text
		Unicode::snprintf(txt_slider2Buffer, TXT_SLIDER2_SIZE, "%u",value);
		txt_slider2.invalidate();
		uint8_t data[] = {'<','c',value,'>'};
		SendData(data);
    }
    if (&src == &slidervl)
    {
        //Interaction3
    	//When slider3
		Unicode::snprintf(txt_vlBuffer, TXT_VL_SIZE, "%u",value);
		txt_vl.invalidate();
		uint8_t data[] = {'<','d',value,'>'};
		SendData(data);
    }
    if (&src == &slidervbp)
    {
        //Interaction2
    	//When slider4
		Unicode::snprintf(txt_vbpBuffer, TXT_VBP_SIZE, "%u",value);
		txt_vbp.invalidate();
		uint8_t data[] = {'<','e',value,'>'};
		SendData(data);
    }
    if (&src == &slidervh)
    {
        //Interaction2
    	//When slider5
		Unicode::snprintf(txt_vhBuffer, TXT_VH_SIZE, "%u",value);
		txt_vh.invalidate();
		uint8_t data[] = {'<','f',value,'>'};
		SendData(data);
    }
}

