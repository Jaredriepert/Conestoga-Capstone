#ifndef DSPHOMESCREENPRESENTER_HPP
#define DSPHOMESCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DspHomeScreenView;

class DspHomeScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DspHomeScreenPresenter(DspHomeScreenView& v);

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

    virtual ~DspHomeScreenPresenter() {};

private:
    DspHomeScreenPresenter();

    DspHomeScreenView& view;
};

#endif // DSPHOMESCREENPRESENTER_HPP
