#ifndef DSP3SCREENVIEW_HPP
#define DSP3SCREENVIEW_HPP

#include <gui_generated/dsp3screen_screen/Dsp3ScreenViewBase.hpp>
#include <gui/dsp3screen_screen/Dsp3ScreenPresenter.hpp>

class Dsp3ScreenView : public Dsp3ScreenViewBase
{
public:
    Dsp3ScreenView();
    virtual ~Dsp3ScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void SendData(uint8_t data[]);
    virtual void LeaveVolume();
protected:
    touchgfx::Callback<Dsp3ScreenView, const touchgfx::Slider&, int> sliderValueConfirmedCallback;
    void sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value);
};

#endif // DSP3SCREENVIEW_HPP
