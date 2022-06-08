#ifndef DSP2SCREENVIEW_HPP
#define DSP2SCREENVIEW_HPP

#include <gui_generated/dsp2screen_screen/Dsp2ScreenViewBase.hpp>
#include <gui/dsp2screen_screen/Dsp2ScreenPresenter.hpp>

class Dsp2ScreenView : public Dsp2ScreenViewBase
{
public:
    Dsp2ScreenView();
    virtual ~Dsp2ScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void SendData(uint8_t data[]);
    virtual void LeaveFilter();
protected:
    touchgfx::Callback<Dsp2ScreenView, const touchgfx::Slider&, int> sliderValueConfirmedCallback;
    void sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value);
};

#endif // DSP2SCREENVIEW_HPP
