#ifndef RUNNINGSCREENPRESENTER_HPP
#define RUNNINGSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class RunningScreenView;

class RunningScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:

    int getProfNum()
    {
    	return model->getProfNum();
    }

	int getPro1Effect1()
	{
		return model->getPro1Effect1();
	}

	int getPro1Effect2()
	{
		return model->getPro1Effect2();
	}

	int getPro1Effect3()
	{
		return model->getPro1Effect3();
	}

	int getPro2Effect1()
	{
		return model->getPro2Effect1();
	}

	int getPro2Effect2()
	{
		return model->getPro2Effect2();
	}

	int getPro2Effect3()
	{
		return model->getPro2Effect3();
	}

	int getPro3Effect1()
	{
		return model->getPro3Effect1();
	}

	int getPro3Effect2()
	{
		return model->getPro3Effect2();
	}

	int getPro3Effect3()
	{
		return model->getPro3Effect3();
	}

	//profile 1 gets
	   bool getpro1_B1_1()
	   {
		return model->getpro1_B1_1();
	   }
	   bool getpro1_B1_2()
	   {
		return model->getpro1_B1_2();
	   }
	   bool getpro1_B1_3()
	   {
		return model->getpro1_B1_3();
	   }
	   bool getpro1_B2_1()
	   {
		return model->getpro1_B2_1();
	   }
	   bool getpro1_B2_2()
	   {
		return model->getpro1_B2_2();
	   }
	   bool getpro1_B2_3()
	   {
		return model->getpro1_B2_3();
	   }
	   bool getpro1_B3_1()
	   {
		return model->getpro1_B3_1();
	   }
	   bool getpro1_B3_2()
	   {
		return model->getpro1_B3_2();
	   }
	   bool getpro1_B3_3()
	   {
		return model->getpro1_B3_3();
	   }
	   //profile 2 gets
	   bool getpro2_B1_1()
	   {
		return model->getpro2_B1_1();
	   }
	   bool getpro2_B1_2()
	   {
		return model->getpro2_B1_2();
	   }
	   bool getpro2_B1_3()
	   {
		return model->getpro2_B1_3();
	   }
	   bool getpro2_B2_1()
	   {
		return model->getpro2_B2_1();
	   }
	   bool getpro2_B2_2()
	   {
		return model->getpro2_B2_2();
	   }
	   bool getpro2_B2_3()
	   {
		return model->getpro2_B2_3();
	   }
	   bool getpro2_B3_1()
	   {
		return model->getpro2_B3_1();
	   }
	   bool getpro2_B3_2()
	   {
		return model->getpro2_B3_2();
	   }
	   bool getpro2_B3_3()
	   {
		return model->getpro2_B3_3();
	   }
	   //profile 3 gets
	   bool getpro3_B1_1()
	   {
		return model->getpro3_B1_1();
	   }
	   bool getpro3_B1_2()
	   {
		return model->getpro3_B1_2();
	   }
	   bool getpro3_B1_3()
	   {
		return model->getpro3_B1_3();
	   }
	   bool getpro3_B2_1()
	   {
		return model->getpro3_B2_1();
	   }
	   bool getpro3_B2_2()
	   {
		return model->getpro3_B2_2();
	   }
	   bool getpro3_B2_3()
	   {
		return model->getpro3_B2_3();
	   }
	   bool getpro3_B3_1()
	   {
		return model->getpro3_B3_1();
	   }
	   bool getpro3_B3_2()
	   {
		return model->getpro3_B3_2();
	   }
	   bool getpro3_B3_3()
	   {
		return model->getpro3_B3_3();
	   }

	   //pedal enable
	   //prof 1
	    bool getpro1_pedal1_on()
	    {
	    	return model->getpro1_pedal1_on();
	    }
	    bool getpro1_pedal2_on()
		{
			return model->getpro1_pedal2_on();
		}
	    bool getpro1_pedal3_on()
		{
			return model->getpro1_pedal3_on();
		}
	    void setpro1_pedal1_on(bool state)
	    {
	 	   model->setpro1_pedal1_on(state);
	    }
	    void setpro1_pedal2_on(bool state)
	    {
	 	   model->setpro1_pedal2_on(state);
	    }
	    void setpro1_pedal3_on(bool state)
	    {
	 	   model->setpro1_pedal3_on(state);
	    }
	    //prof2
	    bool getpro2_pedal1_on()
	    {
	    	return model->getpro2_pedal1_on();
	    }
	    bool getpro2_pedal2_on()
		{
			return model->getpro2_pedal2_on();
		}
	    bool getpro2_pedal3_on()
		{
			return model->getpro2_pedal3_on();
		}
	    void setpro2_pedal1_on(bool state)
	    {
	 	   model->setpro2_pedal1_on(state);
	    }
	    void setpro2_pedal2_on(bool state)
	    {
	 	   model->setpro2_pedal2_on(state);
	    }
	    void setpro2_pedal3_on(bool state)
	    {
	 	   model->setpro2_pedal3_on(state);
	    }
	    //prof3
	    bool getpro3_pedal1_on()
	    {
	    	return model->getpro3_pedal1_on();
	    }
	    bool getpro3_pedal2_on()
		{
			return model->getpro3_pedal2_on();
		}
	    bool getpro3_pedal3_on()
		{
			return model->getpro3_pedal3_on();
		}
	    void setpro3_pedal1_on(bool state)
	    {
	 	   model->setpro3_pedal1_on(state);
	    }
	    void setpro3_pedal2_on(bool state)
	    {
	 	   model->setpro3_pedal2_on(state);
	    }
	    void setpro3_pedal3_on(bool state)
	    {
	 	   model->setpro3_pedal3_on(state);
	    }

	   //soundOnIcon info
	   bool getSoundOn()
	   {
		   return model->getSoundOn();
	   }

	   void setSoundOn(bool state)
	   {
		   model->setSoundOn(state);
	   }

    RunningScreenPresenter(RunningScreenView& v);

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

    virtual ~RunningScreenPresenter() {};

private:
    RunningScreenPresenter();

    RunningScreenView& view;
};

#endif // RUNNINGSCREENPRESENTER_HPP
