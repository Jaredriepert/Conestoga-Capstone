#ifndef HOMESCREENVIEW_HPP
#define HOMESCREENVIEW_HPP

#include <gui_generated/homescreen_screen/HomeScreenViewBase.hpp>
#include <gui/homescreen_screen/HomeScreenPresenter.hpp>
#include "stm32f4xx_hal.h"


class HomeScreenView : public HomeScreenViewBase
{
public:
    HomeScreenView();
    virtual ~HomeScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void SendData();

protected:
};

#endif // HOMESCREENVIEW_HPP
