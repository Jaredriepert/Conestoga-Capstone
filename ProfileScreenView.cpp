#include <gui/profilescreen_screen/ProfileScreenView.hpp>

ProfileScreenView::ProfileScreenView()
{

}

void ProfileScreenView::setupScreen()
{
    ProfileScreenViewBase::setupScreen();
}

void ProfileScreenView::tearDownScreen()
{
    ProfileScreenViewBase::tearDownScreen();
}

void ProfileScreenView::Select_Prof1()
{
	presenter->setProfNum(1);
}
void ProfileScreenView::Select_Prof2()
{
	presenter->setProfNum(2);
}
void ProfileScreenView::Select_Prof3()
{
	presenter->setProfNum(3);
}
