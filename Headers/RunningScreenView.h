#ifndef RUNNINGSCREENVIEW_HPP
#define RUNNINGSCREENVIEW_HPP

#include <gui_generated/runningscreen_screen/RunningScreenViewBase.hpp>
#include <gui/runningscreen_screen/RunningScreenPresenter.hpp>

class RunningScreenView : public RunningScreenViewBase
{
public:
    RunningScreenView();
    virtual ~RunningScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void UpdateButtons();
    virtual void UpdateOrder();
    virtual void FootB1();
    virtual void FootB2();
    virtual void FootB3();
    virtual void FootB4();
	virtual void SetMux1(int index);
	virtual void SetMux2(int index);
	virtual void SetMux3(int index);
	virtual void SetMux4(int index);

protected:
	int pos1;
	int pos2;
	int pos3;

    bool effect1ON = true;
    bool effect2ON = true;
    bool effect3ON = true;

	bool b1_1;
	bool b1_2;
	bool b1_3;
	bool b2_1;
	bool b2_2;
	bool b2_3;
	bool b3_1;
	bool b3_2;
	bool b3_3;
};

#endif // RUNNINGSCREENVIEW_HPP
