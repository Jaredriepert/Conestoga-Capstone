#ifndef DSP1SCREENVIEW_HPP
#define DSP1SCREENVIEW_HPP

#include <gui_generated/dsp1screen_screen/Dsp1ScreenViewBase.hpp>
#include <gui/dsp1screen_screen/Dsp1ScreenPresenter.hpp>

class Dsp1ScreenView : public Dsp1ScreenViewBase
{
public:
    Dsp1ScreenView();
    virtual ~Dsp1ScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void SendData(uint8_t data[]);
    virtual void LeaveReverb();
    virtual void EnableReverb();

protected:
    touchgfx::Callback<Dsp1ScreenView, const touchgfx::Slider&, int> sliderValueConfirmedCallback;
    void sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value);
};

#endif // DSP1SCREENVIEW_HPP
