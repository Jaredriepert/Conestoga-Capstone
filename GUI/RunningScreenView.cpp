#include <gui/runningscreen_screen/RunningScreenView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <BitmapDatabase.hpp>
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_uart.h"

extern UART_HandleTypeDef huart5;

RunningScreenView::RunningScreenView()
{

}

void RunningScreenView::setupScreen()
{
	//set the title
	Unicode::snprintf(txt_TitleBuffer, TXT_TITLE_SIZE, "%u",presenter->getProfNum());
	txt_Title.invalidate();

	//set Sound ON icon
	if(presenter->getSoundOn())
	{
		soundXIcon.setAlpha(0);
		soundXIcon.invalidate();
	}else
	{
		soundXIcon.setAlpha(255);
		soundXIcon.invalidate();
	}

	//set the pedal icons
	switch(presenter->getProfNum())
	{
	case 1:
		//get the first profile effects to load the correct images
		switch(presenter->getPro1Effect1())
		{
		case 0:
			//pedal1.setBitmaps(touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID), touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID));
			pedal1.setAlpha(0);
			pedal1.invalidate();
			break;
		case 1:
			pedal1.setAlpha(255);
			pedal1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_GRAYED_ID));
			pedal1.invalidate();
			break;
		case 2:
			pedal1.setBitmaps(touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_GRAYED_ID));
			break;
		case 3:
			pedal1.setAlpha(255);
			pedal1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_GRAYED_ID));
			pedal1.invalidate();
			break;
		}
		switch(presenter->getPro1Effect2())
		{
		case 0:
			//pedal2.setBitmaps(touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID), touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID));
			pedal2.setAlpha(0);
			pedal2.invalidate();
			break;
		case 1:
			pedal2.setAlpha(255);
			pedal2.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_GRAYED_ID));
			pedal2.invalidate();
			break;
		case 2:
			pedal2.setAlpha(255);
			pedal2.setBitmaps(touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_GRAYED_ID));
			pedal2.invalidate();
			break;
		case 3:
			pedal2.setAlpha(255);
			pedal2.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_GRAYED_ID));
			pedal2.invalidate();
			break;
		}
		switch(presenter->getPro1Effect3())
		{
		case 0:
			//pedal3.setBitmaps(touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID), touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID));
			pedal3.setAlpha(0);
			pedal3.invalidate();
			break;
		case 1:
			pedal3.setAlpha(255);
			pedal3.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_GRAYED_ID));
			pedal3.invalidate();
			break;
		case 2:
			pedal3.setAlpha(255);
			pedal3.setBitmaps(touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_GRAYED_ID));
			pedal3.invalidate();
			break;
		case 3:
			pedal3.setAlpha(255);
			pedal3.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_GRAYED_ID));
			pedal3.invalidate();
			break;
		}
		break;
	case 2:
		//get the second profile effects to load the correct images
		switch(presenter->getPro2Effect1())
		{
		case 0:
			//pedal1.setBitmaps(touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID), touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID));
			pedal1.setAlpha(0);
			pedal1.invalidate();
			break;
		case 1:
			pedal1.setAlpha(255);
			pedal1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_GRAYED_ID));
			pedal1.invalidate();
			break;
		case 2:
			pedal1.setBitmaps(touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_GRAYED_ID));
			break;
		case 3:
			pedal1.setAlpha(255);
			pedal1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_GRAYED_ID));
			pedal1.invalidate();
			break;
		}
		switch(presenter->getPro2Effect2())
		{
		case 0:
			//pedal2.setBitmaps(touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID), touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID));
			pedal2.setAlpha(0);
			pedal2.invalidate();
			break;
		case 1:
			pedal2.setAlpha(255);
			pedal2.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_GRAYED_ID));
			pedal2.invalidate();
			break;
		case 2:
			pedal2.setAlpha(255);
			pedal2.setBitmaps(touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_GRAYED_ID));
			pedal2.invalidate();
			break;
		case 3:
			pedal2.setAlpha(255);
			pedal2.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_GRAYED_ID));
			pedal2.invalidate();
			break;
		}
		switch(presenter->getPro2Effect3())
		{
		case 0:
			//pedal3.setBitmaps(touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID), touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID));
			pedal3.setAlpha(0);
			pedal3.invalidate();
			break;
		case 1:
			pedal3.setAlpha(255);
			pedal3.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_GRAYED_ID));
			pedal3.invalidate();
			break;
		case 2:
			pedal3.setAlpha(255);
			pedal3.setBitmaps(touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_GRAYED_ID));
			pedal3.invalidate();
			break;
		case 3:
			pedal3.setAlpha(255);
			pedal3.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_GRAYED_ID));
			pedal3.invalidate();
			break;
		}
		break;
	case 3:
		//get the third profile effects to load the correct images
		switch(presenter->getPro3Effect1())
		{
		case 0:
			//pedal1.setBitmaps(touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID), touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID));
			pedal1.setAlpha(0);
			pedal1.invalidate();
			break;
		case 1:
			pedal1.setAlpha(255);
			pedal1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_GRAYED_ID));
			pedal1.invalidate();
			break;
		case 2:
			pedal1.setBitmaps(touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_GRAYED_ID));
			break;
		case 3:
			pedal1.setAlpha(255);
			pedal1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_GRAYED_ID));
			pedal1.invalidate();
			break;
		}
		switch(presenter->getPro3Effect2())
		{
		case 0:
			//pedal2.setBitmaps(touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID), touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID));
			pedal2.setAlpha(0);
			pedal2.invalidate();
			break;
		case 1:
			pedal2.setAlpha(255);
			pedal2.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_GRAYED_ID));
			pedal2.invalidate();
			break;
		case 2:
			pedal2.setAlpha(255);
			pedal2.setBitmaps(touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_GRAYED_ID));
			pedal2.invalidate();
			break;
		case 3:
			pedal2.setAlpha(255);
			pedal2.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_GRAYED_ID));
			pedal2.invalidate();
			break;
		}
		switch(presenter->getPro3Effect3())
		{
		case 0:
			//pedal3.setBitmaps(touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID), touchgfx::Bitmap(BITMAP_AUXILIARY_CABLE_ID));
			pedal3.setAlpha(0);
			pedal3.invalidate();
			break;
		case 1:
			pedal3.setAlpha(255);
			pedal3.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_BLUE_GUITAR_PEDAL_GRAYED_ID));
			pedal3.invalidate();
			break;
		case 2:
			pedal3.setAlpha(255);
			pedal3.setBitmaps(touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_GREY_GUITAR_PEDAL_GRAYED_ID));
			pedal3.invalidate();
			break;
		case 3:
			pedal3.setAlpha(255);
			pedal3.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_ID), touchgfx::Bitmap(BITMAP_ORANGE_GUITAR_PEDAL_GRAYED_ID));
			pedal3.invalidate();
			break;
		}
		break;
	}

	switch(presenter->getProfNum())
			{
			case 1:
			{
				b1_1 = presenter->getpro1_B1_1();
				b1_2 = presenter->getpro1_B1_2();
				b1_3 = presenter->getpro1_B1_3();
				b2_1 = presenter->getpro1_B2_1();
				b2_2 = presenter->getpro1_B2_2();
				b2_3 = presenter->getpro1_B2_3();
				b3_1 = presenter->getpro1_B3_1();
				b3_2 = presenter->getpro1_B3_2();
				b3_3 = presenter->getpro1_B3_3();
				//set the pedal icons
				if(presenter->getpro1_pedal1_on() == true){pedal1.forceState(false);}
				else{pedal1.forceState(true);}
				pedal1.invalidate();
				if(presenter->getpro1_pedal2_on() == true){pedal2.forceState(false);}
				else{pedal2.forceState(true);}
				pedal2.invalidate();
				if(presenter->getpro1_pedal3_on() == true){pedal3.forceState(false);}
				else{pedal3.forceState(true);}
				pedal3.invalidate();
				break;
			}
			case 2:
			{
				b1_1 = presenter->getpro2_B1_1();
				b1_2 = presenter->getpro2_B1_2();
				b1_3 = presenter->getpro2_B1_3();
				b2_1 = presenter->getpro2_B2_1();
				b2_2 = presenter->getpro2_B2_2();
				b2_3 = presenter->getpro2_B2_3();
				b3_1 = presenter->getpro2_B3_1();
				b3_2 = presenter->getpro2_B3_2();
				b3_3 = presenter->getpro2_B3_3();
				//set the pedal icons
				if(presenter->getpro2_pedal1_on() == true){pedal1.forceState(false);}
				else{pedal1.forceState(true);}
				pedal1.invalidate();
				if(presenter->getpro2_pedal2_on() == true){pedal2.forceState(false);}
				else{pedal2.forceState(true);}
				pedal2.invalidate();
				if(presenter->getpro2_pedal3_on() == true){pedal3.forceState(false);}
				else{pedal3.forceState(true);}
				pedal3.invalidate();
				break;
			}
			case 3:
			{
				b1_1 = presenter->getpro3_B1_1();
				b1_2 = presenter->getpro3_B1_2();
				b1_3 = presenter->getpro3_B1_3();
				b2_1 = presenter->getpro3_B2_1();
				b2_2 = presenter->getpro3_B2_2();
				b2_3 = presenter->getpro3_B2_3();
				b3_1 = presenter->getpro3_B3_1();
				b3_2 = presenter->getpro3_B3_2();
				b3_3 = presenter->getpro3_B3_3();
				//set the pedal icons
				if(presenter->getpro3_pedal1_on() == true){pedal1.forceState(false);}
				else{pedal1.forceState(true);}
				pedal1.invalidate();
				if(presenter->getpro3_pedal2_on() == true){pedal2.forceState(false);}
				else{pedal2.forceState(true);}
				pedal2.invalidate();
				if(presenter->getpro3_pedal3_on() == true){pedal3.forceState(false);}
				else{pedal3.forceState(true);}
				pedal3.invalidate();
				break;
			}
			}
	UpdateOrder();
    RunningScreenViewBase::setupScreen();
}

void RunningScreenView::tearDownScreen()
{
    RunningScreenViewBase::tearDownScreen();
}

void RunningScreenView::FootB1()
{
	if(pedal1.getState() == true){pedal1.forceState(false);}
	else{pedal1.forceState(true);}
	switch(presenter->getProfNum())
	{
		case 1:
		{
			presenter->setpro1_pedal1_on(!pedal1.getState());
			break;
		}
		case 2:
		{
			presenter->setpro2_pedal1_on(!pedal1.getState());
			break;
		}
		case 3:
		{
			presenter->setpro3_pedal1_on(!pedal1.getState());
			break;
		}
	}
	pedal1.invalidate();
	UpdateButtons();
}

void RunningScreenView::FootB2()
{
	if(pedal2.getState() == true){pedal2.forceState(false);}
	else{pedal2.forceState(true);}
	switch(presenter->getProfNum())
	{
		case 1:
		{
			presenter->setpro1_pedal2_on(!pedal2.getState());
			break;
		}
		case 2:
		{
			presenter->setpro2_pedal2_on(!pedal2.getState());
			break;
		}
		case 3:
		{
			presenter->setpro3_pedal2_on(!pedal2.getState());
			break;
		}
	}
	pedal2.invalidate();
	UpdateButtons();
}

void RunningScreenView::FootB3()
{
	if(pedal3.getState() == true){pedal3.forceState(false);}
	else{pedal3.forceState(true);}
	switch(presenter->getProfNum())
	{
		case 1:
		{
			presenter->setpro1_pedal3_on(!pedal3.getState());
			break;
		}
		case 2:
		{
			presenter->setpro2_pedal3_on(!pedal3.getState());
			break;
		}
		case 3:
		{
			presenter->setpro3_pedal3_on(!pedal3.getState());
			break;
		}
	}
	pedal3.invalidate();
	UpdateButtons();
}

void RunningScreenView::FootB4()
{
	if(soundXIcon.getAlpha() > 0)
	{
		soundXIcon.setAlpha(0);
		soundXIcon.invalidate();
		presenter->setSoundOn(true);
		uint8_t data1[] = {'<','w','>'};
		HAL_UART_Transmit(&huart5,data1,sizeof(data1),200);
		HAL_Delay(50);
		uint8_t data2[] = {'<','c',100,'>'};
		HAL_UART_Transmit(&huart5,data2,sizeof(data2),200);
		HAL_Delay(50);
		uint8_t data3[] = {'<','w','>'};
		HAL_UART_Transmit(&huart5,data3,sizeof(data3),200);

	}else
	{
		soundXIcon.setAlpha(255);
		soundXIcon.invalidate();
		presenter->setSoundOn(false);
		uint8_t data1[] = {'<','w','>'};
		HAL_UART_Transmit(&huart5,data1,sizeof(data1),200);
		HAL_Delay(50);
		uint8_t data2[] = {'<','c',0,'>'};
		HAL_UART_Transmit(&huart5,data2,sizeof(data2),200);
		HAL_Delay(50);
		uint8_t data3[] = {'<','w','>'};
		HAL_UART_Transmit(&huart5,data3,sizeof(data3),200);
	}
}

void RunningScreenView::UpdateButtons()
{
	effect1ON = pedal1.getState();
	effect2ON = pedal2.getState();
	effect3ON = pedal3.getState();

	switch(presenter->getProfNum())
	{
	case 1:
		//Pedal 1
		switch(presenter->getPro1Effect1())
		{
		case 0:
			//nothing because not connected
			b1_1 = false;
			b2_1 = false;
			b3_1 = false;
			break;
		case 1:
			//effect 1 is first and on
			if(!effect1ON){b1_1 = true;}
			//effect 1 is off
			else{b1_1 = false;}
			break;
		case 2:
			//effect 2 is first and on
			if(!effect1ON){b2_1 = true;}
			//effect 2 is off
			else{b2_1 = false;}
			break;
		case 3:
			//effect 3 is first and on
			if(!effect1ON){b3_1 = true;}
			//effect 3 is off
			else{b3_1 = false;}
			break;
		}
		//Pedal 2
		switch(presenter->getPro1Effect2())
		{
		case 0:
			//nothing because not connected
			b1_2 = false;
			b2_2 = false;
			b3_2 = false;
			break;
		case 1:
			//effect 1 is second and on
			if(!effect2ON){b1_2 = true;}
			//effect 1 is off
			else{b1_2 = false;}
			break;
		case 2:
			//effect 2 is second and on
			if(!effect2ON){b2_2 = true;}
			//effect 2 is off
			else{b2_2 = false;}
			break;
		case 3:
			//effect 3 is  second and on
			if(!effect2ON){b3_2 = true;}
			//effect 3 is off
			else{b3_2 = false;}
			break;
		}
		//Pedal 3
		switch(presenter->getPro1Effect3())
		{
		case 0:
			//nothing because not connected
			b1_3 = false;
			b2_3 = false;
			b3_3 = false;
			break;
		case 1:
			//effect 1 is third and on
			if(!effect3ON){b1_3 = true;}
			//effect 1 is off
			else{b1_3 = false;}
			break;
		case 2:
			//effect 2 is third and on
			if(!effect3ON){b2_3 = true;}
			//effect 2 is off
			else{b2_3 = false;}
			break;
		case 3:
			//effect 3 is third and on
			if(!effect3ON){b3_3 = true;}
			//effect 3 is off
			else{b3_3 = false;}
			break;
		}
		break;
	case 2:
		//Pedal 1
		switch(presenter->getPro2Effect1())
		{
		case 0:
			//nothing because not connected
			b1_1 = false;
			b2_1 = false;
			b3_1 = false;
			break;
		case 1:
			//effect 1 is first and on
			if(!effect1ON){b1_1 = true;}
			//effect 1 is off
			else{b1_1 = false;}
			break;
		case 2:
			//effect 2 is first and on
			if(!effect1ON){b2_1 = true;}
			//effect 2 is off
			else{b2_1 = false;}
			break;
		case 3:
			//effect 3 is first and on
			if(!effect1ON){b3_1 = true;}
			//effect 3 is off
			else{b3_1 = false;}
			break;
		}
		//Pedal 2
		switch(presenter->getPro2Effect2())
		{
		case 0:
			//nothing because not connected
			b1_2 = false;
			b2_2 = false;
			b3_2 = false;
			break;
		case 1:
			//effect 1 is second and on
			if(!effect2ON){b1_2 = true;}
			//effect 1 is off
			else{b1_2 = false;}
			break;
		case 2:
			//effect 2 is second and on
			if(!effect2ON){b2_2 = true;}
			//effect 2 is off
			else{b2_2 = false;}
			break;
		case 3:
			//effect 3 is  second and on
			if(!effect2ON){b3_2 = true;}
			//effect 3 is off
			else{b3_2 = false;}
			break;
		}
		//Pedal 3
		switch(presenter->getPro2Effect3())
		{
		case 0:
			//nothing because not connected
			b1_3 = false;
			b2_3 = false;
			b3_3 = false;
			break;
		case 1:
			//effect 1 is third and on
			if(!effect3ON){b1_3 = true;}
			//effect 1 is off
			else{b1_3 = false;}
			break;
		case 2:
			//effect 2 is third and on
			if(!effect3ON){b2_3 = true;}
			//effect 2 is off
			else{b2_3 = false;}
			break;
		case 3:
			//effect 3 is third and on
			if(!effect3ON){b3_3 = true;}
			//effect 3 is off
			else{b3_3 = false;}
			break;
		}
		break;
	case 3:		//Pedal 1
		switch(presenter->getPro3Effect1())
		{
		case 0:
			//nothing because not connected
			b1_1 = false;
			b2_1 = false;
			b3_1 = false;
			break;
		case 1:
			//effect 1 is first and on
			if(!effect1ON){b1_1 = true;}
			//effect 1 is off
			else{b1_1 = false;}
			break;
		case 2:
			//effect 2 is first and on
			if(!effect1ON){b2_1 = true;}
			//effect 2 is off
			else{b2_1 = false;}
			break;
		case 3:
			//effect 3 is first and on
			if(!effect1ON){b3_1 = true;}
			//effect 3 is off
			else{b3_1 = false;}
			break;
		}
		//Pedal 2
		switch(presenter->getPro3Effect2())
		{
		case 0:
			//nothing because not connected
			b1_2 = false;
			b2_2 = false;
			b3_2 = false;
			break;
		case 1:
			//effect 1 is second and on
			if(!effect2ON){b1_2 = true;}
			//effect 1 is off
			else{b1_2 = false;}
			break;
		case 2:
			//effect 2 is second and on
			if(!effect2ON){b2_2 = true;}
			//effect 2 is off
			else{b2_2 = false;}
			break;
		case 3:
			//effect 3 is  second and on
			if(!effect2ON){b3_2 = true;}
			//effect 3 is off
			else{b3_2 = false;}
			break;
		}
		//Pedal 3
		switch(presenter->getPro3Effect3())
		{
		case 0:
			//nothing because not connected
			b1_3 = false;
			b2_3 = false;
			b3_3 = false;
			break;
		case 1:
			//effect 1 is third and on
			if(!effect3ON){b1_3 = true;}
			//effect 1 is off
			else{b1_3 = false;}
			break;
		case 2:
			//effect 2 is third and on
			if(!effect3ON){b2_3 = true;}
			//effect 2 is off
			else{b2_3 = false;}
			break;
		case 3:
			//effect 3 is third and on
			if(!effect3ON){b3_3 = true;}
			//effect 3 is off
			else{b3_3 = false;}
			break;
		}
		break;
	}
	UpdateOrder();
}

void RunningScreenView::UpdateOrder()
{
	pos1 = 0;
	pos2 = 0;
	pos3 = 0;

	//MUX1
	if (pos1 == 0 && b1_1) {
		//E1 is first
		pos1 = 1;
		//mux1 = 0
		SetMux1(0);

	}
	if (pos1 == 0 && b2_1) {
		//E2 is first
		pos1 = 2;
		//mux1 = 1
		SetMux1(1);

	}
	if (pos1 == 0 && b3_1) {
		//E3 is first
		pos1 = 3;
		//mux1 = 2
		SetMux1(2);

	}
	if (pos1 == 0 && b1_2) {
		//E1 is second but no first
		pos1 = 1;
		//mux1 = 0
		SetMux1(0);

	}
	if (pos1 == 0 && b2_2) {
		//E2 is second but no first
		pos1 = 2;
		//mux1 = 1
		SetMux1(1);

	}
	if (pos1 == 0 && b3_2) {
		//E3 is second but no first
		pos1 = 3;
		//mux1 = 2
		SetMux1(2);

	}
	if (pos1 == 0 && b1_3) {
		//E1 is third but no first or second
		pos1 = 1;
		//mux1 = 0
		SetMux1(0);

	}
	if (pos1 == 0 && b2_3) {
		//E2 is third but no first or second
		pos1 = 2;
		//mux1 = 1
		SetMux1(1);

	}
	if (pos1 == 0 && b3_3) {
		//E3 is third but no first or second
		pos1 = 3;
		//mux1 = 2
		SetMux1(2);

	}
	if (pos1 == 0) {
		//Everything is turned off
		pos1 = 0;
		//mux1 = 3
		SetMux1(3);
		//mux2 = 3
		SetMux2(3);
		//mux3 = 3
		SetMux3(3);
		//mux4 = 3
		SetMux4(3);
	}

	switch (pos1) {
	case (0): {
		//nothing because there are non selected
		break;
	}
	case (1): {
		//mux2
		if (pos2 == 0 && b2_2) {
			//E2 is second
			pos2 = 2;
			//mux2 = 0
			SetMux2(0);

		}
		if (pos2 == 0 && b3_2) {
			//E3 is second
			pos2 = 3;
			//mux2 = 1
			SetMux2(1);

		}
		if (pos2 == 0 && b2_3) {
			//E2 is third but not second
			pos2 = 2;
			//mux2 = 0
			SetMux2(0);
			//mux3 = 3
			SetMux3(3);
			//mux4 = 3
			SetMux4(3);

		}
		if (pos2 == 0 && b3_3) {
			//E3 is third but no second
			pos2 = 3;
			//mux2 = 1
			SetMux2(1);
			//mux3 = 3
			SetMux3(3);
			//mux4 = 3
			SetMux4(3);

		}
		if (pos2 == 0) {
			//there is no second or third
			pos2 = 0;
			//mux2 = 2
			SetMux2(2);
			//mux3 = 3
			SetMux3(3);
			//mux4 = 3
			SetMux4(3);

		}
		break;
	}
	case (2): {
		//mux3
		if (pos2 == 0 && b1_2) {
			//E1 is second
			pos2 = 1;
			//mux3 = 0
			SetMux3(0);

		}
		if (pos2 == 0 && b3_2) {
			//E3 is second
			pos2 = 3;
			//mux3 = 1
			SetMux3(1);

		}
		if (pos2 == 0 && b1_3) {
			//E1 is third but not second
			pos2 = 1;
			//mux3 = 0
			SetMux3(0);
			//mux2 = 3
			SetMux2(3);
			//mux4 = 3
			SetMux4(3);

		}
		if (pos2 == 0 && b3_3) {
			//E3 is third but no second
			pos2 = 3;
			//mux3 = 1
			SetMux3(1);
			//mux2 = 3
			SetMux2(3);
			//mux4 = 3
			SetMux4(3);

		}
		if (pos2 == 0) {
			//there is no second or third
			pos2 = 0;
			//mux3 = 2
			SetMux3(2);
			//mux2 = 3
			SetMux2(3);
			//mux4 = 3
			SetMux4(3);

		}
		break;
	}
	case (3): {
		//mux4
		if (pos2 == 0 && b1_2) {
			//E1 is second
			pos2 = 1;
			//mux4 = 0
			SetMux4(0);

		}
		if (pos2 == 0 && b2_2) {
			//E2 is second
			pos2 = 2;
			//mux4 = 1
			SetMux4(1);

		}
		if (pos2 == 0 && b1_3) {
			//E1 is third but not second
			pos2 = 1;
			//mux4 = 0
			SetMux4(0);
			//mux2 = 3
			SetMux2(3);
			//mux3 = 3
			SetMux3(3);

		}
		if (pos2 == 0 && b2_3) {
			//E2 is third but no second
			pos2 = 2;
			//mux4 = 1
			SetMux4(1);
			//mux2 = 3
			SetMux2(3);
			//mux3 = 3
			SetMux3(3);

		}
		if (pos2 == 0) {
			//there is no second or third
			pos2 = 0;
			//mux4 = 2
			SetMux4(2);
			//mux2 = 3
			SetMux2(3);
			//mux3 = 3
			SetMux3(3);

		}
		break;
	}
	}

	switch (pos2) {
	case (0): {
		//nothing because there are non selected
		break;
	}
	case (1): {
		//mux3 & 4
		if (pos3 == 0 && b2_3) {
			//E2 is third
			pos3 = 2;
			//mux3 = 2
			SetMux3(2);
			//mux2 = 0
			SetMux2(0);

		}
		if (pos3 == 0 && b3_3) {
			//E3 is third
			pos3 = 3;
			//mux4 = 2
			SetMux4(2);
			//mux2 = 1
			SetMux2(1);

		}
		if (pos3 == 0) {
			//there is no third
			pos3 = 0;
			//mux2 = 2
			SetMux2(2);
			if (pos1 == 3) {
				//mux3 = 3
				SetMux3(3);
			}
			if (pos1 == 2) {
				//mux4 = 3
				SetMux4(3);
			}
		}
		break;
	}
	case (2): {
		//mux2 & 4
		if (pos3 == 0 && b1_3) {
			//E1 is third
			pos3 = 1;
			//mux2 = 2
			SetMux2(2);
			//mux3 = 0
			SetMux3(0);

		}
		if (pos3 == 0 && b3_3) {
			//E3 is third
			pos3 = 3;
			//mux4 = 2
			SetMux4(2);
			//mux3 = 1
			SetMux3(1);

		}
		if (pos3 == 0) {
			//there is no third
			pos3 = 0;
			//mux3 = 2
			SetMux3(2);
			if (pos1 == 1) {
				//mux4 = 3
				SetMux4(3);
			}
			if (pos1 == 3) {
				//mux2 = 3
				SetMux2(3);
			}
		}
		break;
	}
	case (3): {
		//mux2 & 3
		if (pos3 == 0 && b1_3) {
			//E1 is third
			pos3 = 1;
			//mux2 = 2
			SetMux2(2);
			//mux4 = 0
			SetMux4(0);

		}
		if (pos3 == 0 && b2_3) {
			//E2 is third
			pos3 = 2;
			//mux3 = 2
			SetMux3(2);
			//mux4 = 1
			SetMux4(1);

		}
		if (pos3 == 0) {
			//there is no third
			pos3 = 0;
			//mux4 = 2
			SetMux4(2);
			if (pos1 == 1) {
				//mux3 = 3
				SetMux3(3);
			}
			if (pos1 == 2) {
				//mux2 = 3
				SetMux2(3);
			}

		}
		break;
	}
	}

}

void RunningScreenView::SetMux1(int index) {
	switch (index) {
	case (0): {
		//send 0
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_RESET);	//A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);	//B
		break;
	}
	case (1): {
		//send 1
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_SET);		//A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);	//B
		break;
	}
	case (2): {
		//send 2
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_RESET);	//A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);		//B
		break;
	}
	case (3): {
		//send 3
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_SET);		//A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);		//B
		break;
	}
	}
}
void RunningScreenView::SetMux2(int index) {
	switch (index) {
	case (0): {
		//send 00
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);	//A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);	//B
		break;
	}
	case (1): {
		//send 01
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);		//A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);	//B
		break;
	}
	case (2): {
		//send 10
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);	//A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);		//B
		break;
	}
	case (3): {
		//send 11
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);		//A
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);		//B
		break;
	}
	}
}
void RunningScreenView::SetMux3(int index) {
	switch (index) {
	case (0): {
		//send 00
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);	//A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);	//B
		break;
	}
	case (1): {
		//send 01
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);		//A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);	//B
		break;
	}
	case (2): {
		//send 10
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);	//A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);		//B
		break;
	}
	case (3): {
		//send 11
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);		//A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);		//B
		break;
	}
	}
}
void RunningScreenView::SetMux4(int index) {
	switch (index) {
	case (0): {
		//send 00
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);	//A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);	//B
		break;
	}
	case (1): {
		//send 01
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);		//A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);	//B
		break;
	}
	case (2): {
		//send 10
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);	//A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);		//B
		break;
	}
	case (3): {
		//send 11
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);		//A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);		//B
		break;
	}
	}
}
