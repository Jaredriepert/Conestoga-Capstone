#ifndef PROFILESCREENPRESENTER_HPP
#define PROFILESCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ProfileScreenView;

class ProfileScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:

    void setProfNum(int num)
    {
    	model->setProfNum(num);
    }

    ProfileScreenPresenter(ProfileScreenView& v);

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

    virtual ~ProfileScreenPresenter() {};

private:
    ProfileScreenPresenter();

    ProfileScreenView& view;
};

#endif // PROFILESCREENPRESENTER_HPP
