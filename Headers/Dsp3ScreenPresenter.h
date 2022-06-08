#ifndef DSP3SCREENPRESENTER_HPP
#define DSP3SCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Dsp3ScreenView;

class Dsp3ScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:

	int getVolumeIn()
	{
		return model->getVolumeIn();
	}
	int getVolumeOut()
	{
		return model->getVolumeOut();
	}
	void setVolumeIn(int value)
	{
		model->setVolumeIn(value);
	}
	void setVolumeOut(int value)
	{
		model->setVolumeOut(value);
	}

    Dsp3ScreenPresenter(Dsp3ScreenView& v);

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

    virtual ~Dsp3ScreenPresenter() {};

private:
    Dsp3ScreenPresenter();

    Dsp3ScreenView& view;
};

#endif // DSP3SCREENPRESENTER_HPP
