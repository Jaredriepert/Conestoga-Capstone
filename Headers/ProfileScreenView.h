#ifndef PROFILESCREENVIEW_HPP
#define PROFILESCREENVIEW_HPP

#include <gui_generated/profilescreen_screen/ProfileScreenViewBase.hpp>
#include <gui/profilescreen_screen/ProfileScreenPresenter.hpp>

class ProfileScreenView : public ProfileScreenViewBase
{
public:
    ProfileScreenView();
    virtual ~ProfileScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void Select_Prof1();
    virtual void Select_Prof2();
    virtual void Select_Prof3();
protected:
};

#endif // PROFILESCREENVIEW_HPP
