#ifndef EDITSCREENVIEW_HPP
#define EDITSCREENVIEW_HPP

#include <gui_generated/editscreen_screen/EditScreenViewBase.hpp>
#include <gui/editscreen_screen/EditScreenPresenter.hpp>

class EditScreenView : public EditScreenViewBase
{
public:
    EditScreenView();
    virtual ~EditScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void UpdateOrder();
	virtual void ds();
	virtual void SetMux1(int index);
	virtual void SetMux2(int index);
	virtual void SetMux3(int index);
	virtual void SetMux4(int index);
	virtual void s1_1();
	virtual void s1_2();
	virtual void s1_3();
	virtual void s2_1();
	virtual void s2_2();
	virtual void s2_3();
	virtual void s3_1();
	virtual void s3_2();
	virtual void s3_3();
	virtual void updateButtonsDisplay();
	virtual void setAllBools();
protected:
	int pos1;
	int pos2;
	int pos3;
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

#endif // EDITSCREENVIEW_HPP
