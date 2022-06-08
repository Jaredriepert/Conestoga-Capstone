#include <gui/editscreen_screen/EditScreenView.hpp>
#include "stm32f4xx_hal.h"

EditScreenView::EditScreenView()
{

}

void EditScreenView::setupScreen()
{
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
			break;
		}
		}
		updateButtonsDisplay();
		//UpdateOrder();
    EditScreenViewBase::setupScreen();
}

void EditScreenView::tearDownScreen()
{
	setAllBools();
		switch(presenter->getProfNum())
		{
		case 1:
		{
			presenter->savepro1_ButtonValues(b1_1,b1_2,b1_3,b2_1,b2_2,b2_3,b3_1,b3_2,b3_3);

			//save which effect is in effect 1 slot
			if(b1_1){ presenter->setPro1Effect1(1);}
			else if(b2_1){ presenter->setPro1Effect1(2);}
			else if(b3_1){ presenter->setPro1Effect1(3);}
			else {presenter->setPro1Effect1(0);}

			//save which effect is in effect 2 slot
			if(b1_2){ presenter->setPro1Effect2(1);}
			else if(b2_2){ presenter->setPro1Effect2(2);}
			else if(b3_2){ presenter->setPro1Effect2(3);}
			else {presenter->setPro1Effect2(0);}

			//save which effect is in effect 3 slot
			if(b1_3){ presenter->setPro1Effect3(1);}
			else if(b2_3){ presenter->setPro1Effect3(2);}
			else if(b3_3){ presenter->setPro1Effect3(3);}
			else {presenter->setPro1Effect3(0);}

			break;
		}
		case 2:
		{
			presenter->savepro2_ButtonValues(b1_1,b1_2,b1_3,b2_1,b2_2,b2_3,b3_1,b3_2,b3_3);

			//save which effect is in effect 1 slot
			if(b1_1){ presenter->setPro2Effect1(1);}
			else if(b2_1){ presenter->setPro2Effect1(2);}
			else if(b3_1){ presenter->setPro2Effect1(3);}
			else {presenter->setPro2Effect1(0);}

			//save which effect is in effect 2 slot
			if(b1_2){ presenter->setPro2Effect2(1);}
			else if(b2_2){ presenter->setPro2Effect2(2);}
			else if(b3_2){ presenter->setPro2Effect2(3);}
			else {presenter->setPro2Effect2(0);}

			//save which effect is in effect 3 slot
			if(b1_3){ presenter->setPro2Effect3(1);}
			else if(b2_3){ presenter->setPro2Effect3(2);}
			else if(b3_3){ presenter->setPro2Effect3(3);}
			else {presenter->setPro2Effect3(0);}

			break;
		}
		case 3:
		{
			presenter->savepro3_ButtonValues(b1_1,b1_2,b1_3,b2_1,b2_2,b2_3,b3_1,b3_2,b3_3);

			//save which effect is in effect 1 slot
			if(b1_1){ presenter->setPro3Effect1(1);}
			else if(b2_1){ presenter->setPro3Effect1(2);}
			else if(b3_1){ presenter->setPro3Effect1(3);}
			else {presenter->setPro3Effect1(0);}

			//save which effect is in effect 2 slot
			if(b1_2){ presenter->setPro3Effect2(1);}
			else if(b2_2){ presenter->setPro3Effect2(2);}
			else if(b3_2){ presenter->setPro3Effect2(3);}
			else {presenter->setPro3Effect2(0);}

			//save which effect is in effect 3 slot
			if(b1_3){ presenter->setPro3Effect3(1);}
			else if(b2_3){ presenter->setPro3Effect3(2);}
			else if(b3_3){ presenter->setPro3Effect3(3);}
			else {presenter->setPro3Effect3(0);}

			break;
		}
		}

    EditScreenViewBase::tearDownScreen();
}


void EditScreenView::setAllBools()
{
	b1_1 = radio_1_1.getSelected();
	b1_2 = radio_1_2.getSelected();
	b1_3 = radio_1_3.getSelected();
	b2_1 = radio_2_1.getSelected();
	b2_2 = radio_2_2.getSelected();
	b2_3 = radio_2_3.getSelected();
	b3_1 = radio_3_1.getSelected();
	b3_2 = radio_3_2.getSelected();
	b3_3 = radio_3_3.getSelected();
}
void EditScreenView::updateButtonsDisplay()
{
	radio_1_1.setSelected(b1_1);
	radio_1_2.setSelected(b1_2);
	radio_1_3.setSelected(b1_3);
	radio_2_1.setSelected(b2_1);
	radio_2_2.setSelected(b2_2);
	radio_2_3.setSelected(b2_3);
	radio_3_1.setSelected(b3_1);
	radio_3_2.setSelected(b3_2);
	radio_3_3.setSelected(b3_3);
}

void EditScreenView::ds() {
	UpdateOrder();
}
void EditScreenView::s1_1() {
	radio_2_1.setSelected(false);
	radio_3_1.setSelected(false);
	b1_1 = true;
	b1_2 = false;
	b1_3 = false;
	b2_1 = false;
	b3_1 = false;
	UpdateOrder();
}
void EditScreenView::s1_2() {
	radio_2_2.setSelected(false);
	radio_3_2.setSelected(false);
	b1_1 = false;
	b1_2 = true;
	b1_3 = false;
	b2_2 = false;
	b3_2 = false;
	UpdateOrder();
}
void EditScreenView::s1_3() {
	radio_2_3.setSelected(false);
	radio_3_3.setSelected(false);
	b1_1 = false;
	b1_2 = false;
	b1_3 = true;
	b2_3 = false;
	b3_3 = false;
	UpdateOrder();
}
void EditScreenView::s2_1() {
	radio_1_1.setSelected(false);
	radio_3_1.setSelected(false);
	b1_1 = false;
	b2_1 = true;
	b3_1 = false;
	UpdateOrder();
}
void EditScreenView::s2_2() {
	radio_1_2.setSelected(false);
	radio_3_2.setSelected(false);
	b1_2 = false;
	b2_2 = true;
	b3_2 = false;
	UpdateOrder();
}
void EditScreenView::s2_3() {
	radio_1_3.setSelected(false);
	radio_3_3.setSelected(false);
	b1_3 = false;
	b2_3 = true;
	b3_3 = false;
	UpdateOrder();
}
void EditScreenView::s3_1() {
	radio_2_1.setSelected(false);
	radio_1_1.setSelected(false);
	b1_1 = false;
	b2_1 = false;
	b3_1 = true;
	UpdateOrder();
}
void EditScreenView::s3_2() {
	radio_2_2.setSelected(false);
	radio_1_2.setSelected(false);
	b1_2 = false;
	b2_2 = false;
	b3_2 = true;
	UpdateOrder();
}
void EditScreenView::s3_3() {
	radio_2_3.setSelected(false);
	radio_1_3.setSelected(false);
	b1_3 = false;
	b2_3 = false;
	b3_3 = true;
	UpdateOrder();
}
void EditScreenView::UpdateOrder() {
	pos1 = 0;
	pos2 = 0;
	pos3 = 0;

	//MUX1
	if (pos1 == 0 && radio_1_1.getSelected()) {
		//E1 is first
		pos1 = 1;
		//mux1 = 0
		SetMux1(0);

	}
	if (pos1 == 0 && radio_2_1.getSelected()) {
		//E2 is first
		pos1 = 2;
		//mux1 = 1
		SetMux1(1);

	}
	if (pos1 == 0 && radio_3_1.getSelected()) {
		//E3 is first
		pos1 = 3;
		//mux1 = 2
		SetMux1(2);

	}
	if (pos1 == 0 && radio_1_2.getSelected()) {
		//E1 is second but no first
		pos1 = 1;
		//mux1 = 0
		SetMux1(0);

	}
	if (pos1 == 0 && radio_2_2.getSelected()) {
		//E2 is second but no first
		pos1 = 2;
		//mux1 = 1
		SetMux1(1);

	}
	if (pos1 == 0 && radio_3_2.getSelected()) {
		//E3 is second but no first
		pos1 = 3;
		//mux1 = 2
		SetMux1(2);

	}
	if (pos1 == 0 && radio_1_3.getSelected()) {
		//E1 is third but no first or second
		pos1 = 1;
		//mux1 = 0
		SetMux1(0);

	}
	if (pos1 == 0 && radio_2_3.getSelected()) {
		//E2 is third but no first or second
		pos1 = 2;
		//mux1 = 1
		SetMux1(1);

	}
	if (pos1 == 0 && radio_3_3.getSelected()) {
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
		if (pos2 == 0 && radio_2_2.getSelected()) {
			//E2 is second
			pos2 = 2;
			//mux2 = 0
			SetMux2(0);

		}
		if (pos2 == 0 && radio_3_2.getSelected()) {
			//E3 is second
			pos2 = 3;
			//mux2 = 1
			SetMux2(1);

		}
		if (pos2 == 0 && radio_2_3.getSelected()) {
			//E2 is third but not second
			pos2 = 2;
			//mux2 = 0
			SetMux2(0);
			//mux3 = 3
			SetMux3(3);
			//mux4 = 3
			SetMux4(3);

		}
		if (pos2 == 0 && radio_3_3.getSelected()) {
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
		if (pos2 == 0 && radio_1_2.getSelected()) {
			//E1 is second
			pos2 = 1;
			//mux3 = 0
			SetMux3(0);

		}
		if (pos2 == 0 && radio_3_2.getSelected()) {
			//E3 is second
			pos2 = 3;
			//mux3 = 1
			SetMux3(1);

		}
		if (pos2 == 0 && radio_1_3.getSelected()) {
			//E1 is third but not second
			pos2 = 1;
			//mux3 = 0
			SetMux3(0);
			//mux2 = 3
			SetMux2(3);
			//mux4 = 3
			SetMux4(3);

		}
		if (pos2 == 0 && radio_3_3.getSelected()) {
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
		if (pos2 == 0 && radio_1_2.getSelected()) {
			//E1 is second
			pos2 = 1;
			//mux4 = 0
			SetMux4(0);

		}
		if (pos2 == 0 && radio_2_2.getSelected()) {
			//E2 is second
			pos2 = 2;
			//mux4 = 1
			SetMux4(1);

		}
		if (pos2 == 0 && radio_1_3.getSelected()) {
			//E1 is third but not second
			pos2 = 1;
			//mux4 = 0
			SetMux4(0);
			//mux2 = 3
			SetMux2(3);
			//mux3 = 3
			SetMux3(3);

		}
		if (pos2 == 0 && radio_2_3.getSelected()) {
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
		if (pos3 == 0 && radio_2_3.getSelected()) {
			//E2 is third
			pos3 = 2;
			//mux3 = 2
			SetMux3(2);
			//mux2 = 0
			SetMux2(0);

		}
		if (pos3 == 0 && radio_3_3.getSelected()) {
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
		if (pos3 == 0 && radio_1_3.getSelected()) {
			//E1 is third
			pos3 = 1;
			//mux2 = 2
			SetMux2(2);
			//mux3 = 0
			SetMux3(0);

		}
		if (pos3 == 0 && radio_3_3.getSelected()) {
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
		if (pos3 == 0 && radio_1_3.getSelected()) {
			//E1 is third
			pos3 = 1;
			//mux2 = 2
			SetMux2(2);
			//mux4 = 0
			SetMux4(0);

		}
		if (pos3 == 0 && radio_2_3.getSelected()) {
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
	/*
	 int16_t test = 1;
	 Unicode::snprintf(text_1Buffer, sizeof(text_1Buffer), "%d",test);
	 Unicode::snprintf(text_2Buffer, 20, "1");
	 Unicode::snprintf(text_3Buffer, sizeof(text_3Buffer), "%01d",pos3);

	 text_1.resizeToCurrentText();
	 text_2.resizeToCurrentText();
	 text_3.resizeToCurrentText();

	 text_1.invalidate();
	 text_2.invalidate();
	 text_3.invalidate();
	 */
	/*
	 *
	 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	 */
}
void EditScreenView::SetMux1(int index) {
//	switch (index) {
//	case (0): {
//		//send 0
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_RESET);	//A
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);	//B
//		break;
//	}
//	case (1): {
//		//send 1
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_SET);		//A
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);	//B
//		break;
//	}
//	case (2): {
//		//send 2
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_RESET);	//A
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);		//B
//		break;
//	}
//	case (3): {
//		//send 3
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_SET);		//A
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);		//B
//		break;
//	}
//	}
}
void EditScreenView::SetMux2(int index) {
//	switch (index) {
//	case (0): {
//		//send 00
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);	//A
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);	//B
//		break;
//	}
//	case (1): {
//		//send 01
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);		//A
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);	//B
//		break;
//	}
//	case (2): {
//		//send 10
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);	//A
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);		//B
//		break;
//	}
//	case (3): {
//		//send 11
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);		//A
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);		//B
//		break;
//	}
//	}
}
void EditScreenView::SetMux3(int index) {
//	switch (index) {
//	case (0): {
//		//send 00
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);	//A
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);	//B
//		break;
//	}
//	case (1): {
//		//send 01
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);		//A
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);	//B
//		break;
//	}
//	case (2): {
//		//send 10
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);	//A
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);		//B
//		break;
//	}
//	case (3): {
//		//send 11
//		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);		//A
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);		//B
//		break;
//	}
//	}
}
void EditScreenView::SetMux4(int index) {
//	switch (index) {
//	case (0): {
//		//send 00
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);	//A
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);	//B
//		break;
//	}
//	case (1): {
//		//send 01
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);		//A
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);	//B
//		break;
//	}
//	case (2): {
//		//send 10
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);	//A
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);		//B
//		break;
//	}
//	case (3): {
//		//send 11
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);		//A
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);		//B
//		break;
//	}
//	}
}
