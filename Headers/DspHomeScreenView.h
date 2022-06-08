#ifndef DSPHOMESCREENVIEW_HPP
#define DSPHOMESCREENVIEW_HPP

#include <gui_generated/dsphomescreen_screen/DspHomeScreenViewBase.hpp>
#include <gui/dsphomescreen_screen/DspHomeScreenPresenter.hpp>

class DspHomeScreenView : public DspHomeScreenViewBase
{
public:
    DspHomeScreenView();
    virtual ~DspHomeScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void EnterReverb();
    virtual void EnterFilter();
    virtual void EnterVolume();
    virtual void SendData(uint8_t data[]);
protected:
};

#endif // DSPHOMESCREENVIEW_HPP
