#ifndef DSP1SCREENPRESENTER_HPP
#define DSP1SCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Dsp1ScreenView;

class Dsp1ScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:

    bool getReverbOn()
    {
    	return model->getReverbOn();
    }
    int getReverbRoom()
    {
    	return model->getReverbRoom();
    }
    int getReverbVolume()
    {
    	return model->getReverbVolume();
    }
    void setReverbOn(bool state)
    {
    	model->setReverbOn(state);
    }
    void setReverbRoom(int value)
    {
    	model->setReverbRoom(value);
    }
    void setReverbVolume(int value)
    {
    	model->setReverbVolume(value);
    }

    Dsp1ScreenPresenter(Dsp1ScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Dsp1ScreenPresenter() {};

private:
    Dsp1ScreenPresenter();

    Dsp1ScreenView& view;
};

#endif // DSP1SCREENPRESENTER_HPP
