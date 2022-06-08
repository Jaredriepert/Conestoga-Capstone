#ifndef DSP2SCREENPRESENTER_HPP
#define DSP2SCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Dsp2ScreenView;

class Dsp2ScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:

	int getFilterBp()
	{
		return model->getFilterBp();
	}
	int getFilterQ()
	{
		return model->getFilterQ();
	}
	int getFilterBase()
	{
		return model->getFilterBase();
	}
	int getFilterMid()
	{
		return model->getFilterMid();
	}
	int getFilterHigh()
	{
		return model->getFilterHigh();
	}
	void setFilterBp(int value)
	{
		model->setFilterBp(value);
	}
	void setFilterQ(int value)
	{
		model->setFilterQ(value);
	}
	void setFilterBase(int value)
	{
		model->setFilterBase(value);
	}
	void setFilterMid(int value)
	{
		model->setFilterMid(value);
	}
	void setFilterHigh(int value)
	{
		model->setFilterHigh(value);
	}

    Dsp2ScreenPresenter(Dsp2ScreenView& v);

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

    virtual ~Dsp2ScreenPresenter() {};

private:
    Dsp2ScreenPresenter();

    Dsp2ScreenView& view;
};

#endif // DSP2SCREENPRESENTER_HPP
