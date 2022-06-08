#ifndef EDITSCREENPRESENTER_HPP
#define EDITSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class EditScreenView;

class EditScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
	 void savepro1_ButtonValues(bool b1_1, bool b1_2, bool b1_3, bool b2_1, bool b2_2, bool b2_3, bool b3_1, bool b3_2, bool b3_3)
	{
		model->savepro1_ButtonValues(b1_1,b1_2,b1_3,b2_1,b2_2,b2_3,b3_1,b3_2,b3_3);
	}
	void savepro2_ButtonValues(bool b1_1, bool b1_2, bool b1_3, bool b2_1, bool b2_2, bool b2_3, bool b3_1, bool b3_2, bool b3_3)
	{
		model->savepro2_ButtonValues(b1_1,b1_2,b1_3,b2_1,b2_2,b2_3,b3_1,b3_2,b3_3);
	}
	void savepro3_ButtonValues(bool b1_1, bool b1_2, bool b1_3, bool b2_1, bool b2_2, bool b2_3, bool b3_1, bool b3_2, bool b3_3)
	{
		model->savepro3_ButtonValues(b1_1,b1_2,b1_3,b2_1,b2_2,b2_3,b3_1,b3_2,b3_3);
	}

	int getProfNum()
	{
		return model->getProfNum();
	}

	void setPro1Effect1(int num)
	{
		model->setPro1Effect1(num);
	}

	void setPro1Effect2(int num)
	{
		model->setPro1Effect2(num);
	}

	void setPro1Effect3(int num)
	{
		model->setPro1Effect3(num);
	}

	void setPro2Effect1(int num)
	{
		model->setPro2Effect1(num);
	}

	void setPro2Effect2(int num)
	{
		model->setPro2Effect2(num);
	}

	void setPro2Effect3(int num)
	{
		model->setPro2Effect3(num);
	}

	void setPro3Effect1(int num)
	{
		model->setPro3Effect1(num);
	}

	void setPro3Effect2(int num)
	{
		model->setPro3Effect2(num);
	}

	void setPro3Effect3(int num)
	{
		model->setPro3Effect3(num);
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
    EditScreenPresenter(EditScreenView& v);

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

    virtual ~EditScreenPresenter() {};

private:
    EditScreenPresenter();

    EditScreenView& view;
};

#endif // EDITSCREENPRESENTER_HPP
