#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();


    void savepro1_ButtonValues(bool b1_1, bool b1_2, bool b1_3, bool b2_1, bool b2_2, bool b2_3, bool b3_1, bool b3_2, bool b3_3)
    {
    	pro1_b1_1 = b1_1;
    	pro1_b1_2 = b1_2;
    	pro1_b1_3 = b1_3;
    	pro1_b2_1 = b2_1;
    	pro1_b2_2 = b2_2;
    	pro1_b2_3 = b2_3;
    	pro1_b3_1 = b3_1;
    	pro1_b3_2 = b3_2;
    	pro1_b3_3 = b3_3;
    }
    void savepro2_ButtonValues(bool b1_1, bool b1_2, bool b1_3, bool b2_1, bool b2_2, bool b2_3, bool b3_1, bool b3_2, bool b3_3)
    {
    	pro2_b1_1 = b1_1;
    	pro2_b1_2 = b1_2;
    	pro2_b1_3 = b1_3;
    	pro2_b2_1 = b2_1;
    	pro2_b2_2 = b2_2;
    	pro2_b2_3 = b2_3;
    	pro2_b3_1 = b3_1;
    	pro2_b3_2 = b3_2;
    	pro2_b3_3 = b3_3;
    }
    void savepro3_ButtonValues(bool b1_1, bool b1_2, bool b1_3, bool b2_1, bool b2_2, bool b2_3, bool b3_1, bool b3_2, bool b3_3)
    {
    	pro3_b1_1 = b1_1;
    	pro3_b1_2 = b1_2;
    	pro3_b1_3 = b1_3;
    	pro3_b2_1 = b2_1;
    	pro3_b2_2 = b2_2;
    	pro3_b2_3 = b2_3;
    	pro3_b3_1 = b3_1;
    	pro3_b3_2 = b3_2;
    	pro3_b3_3 = b3_3;
    }

    void setProfNum(int num)
    {
    	profNum = num;
    }

    int getProfNum()
    {
    	return profNum;
    }

    //set and gets for effects
    void setPro1Effect1(int num)
    {
    	pro1effect1 = num;
    }

    void setPro1Effect2(int num)
    {
    	pro1effect2 = num;
    }

    void setPro1Effect3(int num)
    {
    	pro1effect3 = num;
    }

    int getPro1Effect1()
    {
    	return pro1effect1;
    }

    int getPro1Effect2()
    {
    	return pro1effect2;
    }

    int getPro1Effect3()
    {
    	return pro1effect3;
    }

    void setPro2Effect1(int num)
    {
    	pro2effect1 = num;
    }

    void setPro2Effect2(int num)
    {
    	pro2effect2 = num;
    }

    void setPro2Effect3(int num)
    {
    	pro2effect3 = num;
    }

    int getPro2Effect1()
    {
    	return pro2effect1;
    }

    int getPro2Effect2()
    {
    	return pro2effect2;
    }

    int getPro2Effect3()
    {
    	return pro2effect3;
    }

    void setPro3Effect1(int num)
    {
    	pro3effect1 = num;
    }

    void setPro3Effect2(int num)
    {
    	pro3effect2 = num;
    }

    void setPro3Effect3(int num)
    {
    	pro3effect3 = num;
    }

    int getPro3Effect1()
    {
    	return pro3effect1;
    }

    int getPro3Effect2()
    {
    	return pro3effect2;
    }

    int getPro3Effect3()
    {
    	return pro3effect3;
    }

    //profile 1 gets
    bool getpro1_B1_1()
    {
    	return pro1_b1_1;
    }
    bool getpro1_B1_2()
    {
    	return pro1_b1_2;
    }
    bool getpro1_B1_3()
    {
    	return pro1_b1_3;
    }
    bool getpro1_B2_1()
    {
    	return pro1_b2_1;
    }
    bool getpro1_B2_2()
    {
    	return pro1_b2_2;
    }
    bool getpro1_B2_3()
    {
    	return pro1_b2_3;
    }
    bool getpro1_B3_1()
    {
    	return pro1_b3_1;
    }
    bool getpro1_B3_2()
    {
    	return pro1_b3_2;
    }
    bool getpro1_B3_3()
    {
    	return pro1_b3_3;
    }
    bool getpro1_pedal1_on()
    {
    	return pro1_pedal1_on;
    }
    bool getpro1_pedal2_on()
	{
		return pro1_pedal2_on;
	}
    bool getpro1_pedal3_on()
	{
		return pro1_pedal3_on;
	}
    void setpro1_pedal1_on(bool state)
    {
 	   pro1_pedal1_on = state;
    }
    void setpro1_pedal2_on(bool state)
    {
 	   pro1_pedal2_on = state;
    }
    void setpro1_pedal3_on(bool state)
    {
 	   pro1_pedal3_on = state;
    }
    //profile 2 gets
   bool getpro2_B1_1()
   {
	   return pro2_b1_1;
   }
   bool getpro2_B1_2()
   {
	   return pro2_b1_2;
   }
   bool getpro2_B1_3()
   {
	   return pro2_b1_3;
   }
   bool getpro2_B2_1()
   {
	   return pro2_b2_1;
   }
   bool getpro2_B2_2()
   {
	   return pro2_b2_2;
   }
   bool getpro2_B2_3()
   {
	   return pro2_b2_3;
   }
   bool getpro2_B3_1()
   {
	   return pro2_b3_1;
   }
   bool getpro2_B3_2()
   {
	   return pro2_b3_2;
   }
   bool getpro2_B3_3()
   {
	   return pro2_b3_3;
   }
   bool getpro2_pedal1_on()
   {
	   return pro2_pedal1_on;
   }
   bool getpro2_pedal2_on()
	{
		return pro2_pedal2_on;
	}
   bool getpro2_pedal3_on()
	{
		return pro2_pedal3_on;
	}
   void setpro2_pedal1_on(bool state)
   {
	   pro2_pedal1_on = state;
   }
   void setpro2_pedal2_on(bool state)
   {
	   pro2_pedal2_on = state;
   }
   void setpro2_pedal3_on(bool state)
   {
	   pro2_pedal3_on = state;
   }
   //profile 3 gets
   bool getpro3_B1_1()
   {
	   return pro3_b1_1;
   }
   bool getpro3_B1_2()
   {
	   return pro3_b1_2;
   }
   bool getpro3_B1_3()
   {
	   return pro3_b1_3;
   }
   bool getpro3_B2_1()
   {
	   return pro3_b2_1;
   }
   bool getpro3_B2_2()
   {
	   return pro3_b2_2;
   }
   bool getpro3_B2_3()
   {
	   return pro3_b2_3;
   }
   bool getpro3_B3_1()
   {
	   return pro3_b3_1;
   }
   bool getpro3_B3_2()
   {
	   return pro3_b3_2;
   }
   bool getpro3_B3_3()
   {
	   return pro3_b3_3;
   }
   bool getpro3_pedal1_on()
   {
	   return pro3_pedal1_on;
   }
   bool getpro3_pedal2_on()
	{
		return pro3_pedal2_on;
	}
   bool getpro3_pedal3_on()
	{
		return pro3_pedal3_on;
	}
   void setpro3_pedal1_on(bool state)
   {
	   pro3_pedal1_on = state;
   }
   void setpro3_pedal2_on(bool state)
   {
	   pro3_pedal2_on = state;
   }
   void setpro3_pedal3_on(bool state)
   {
	   pro3_pedal3_on = state;
   }
   bool getSoundOn()
   {
	   return soundOn;
   }
   void setSoundOn(bool state)
   {
	   soundOn = state;
   }

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    //DSP VALUE FUNCTIONS
    //reverb
    bool getReverbOn()
    {
    	return reverb_on;
    }
    int getReverbRoom()
    {
    	return reverb_room;
    }
    int getReverbVolume()
    {
    	return reverb_volume;
    }
    void setReverbOn(bool state)
    {
    	reverb_on = state;
    }
    void setReverbRoom(int value)
    {
    	reverb_room = value;
    }
    void setReverbVolume(int value)
    {
    	reverb_volume = value;
    }
    //filter
    int getFilterBp()
    {
    	return filter_bp;
    }
    int getFilterQ()
    {
    	return filter_q;
    }
    int getFilterBase()
    {
    	return filter_base;
    }
    int getFilterMid()
    {
    	return filter_mid;
    }
    int getFilterHigh()
    {
    	return filter_high;
    }
    void setFilterBp(int value)
    {
    	filter_bp = value;
    }
    void setFilterQ(int value)
	{
    	filter_q = value;
	}
    void setFilterBase(int value)
	{
    	filter_base = value;
	}
    void setFilterMid(int value)
	{
    	filter_mid = value;
	}
    void setFilterHigh(int value)
	{
    	filter_high = value;
	}

    //volume
    int getVolumeIn()
    {
    	return volume_in;
    }
    int getVolumeOut()
    {
    	return volume_out;
    }
    void setVolumeIn(int value)
    {
    	volume_in = value;
    }
    void setVolumeOut(int value)
    {
    	volume_out = value;
    }

    void tick();
protected:
    ModelListener* modelListener;
	int profNum;
	int pro1effect1;
	int pro1effect2;
	int pro1effect3;
	int pro2effect1;
	int pro2effect2;
	int pro2effect3;
	int pro3effect1;
	int pro3effect2;
	int pro3effect3;

	bool filter1 = true;
	bool filter2 = true;
	bool filter3 = true;
	bool filter4 = true;

	bool soundOn;

    bool pro1_b1_1;
	bool pro1_b1_2;
	bool pro1_b1_3;
	bool pro1_b2_1;
	bool pro1_b2_2;
	bool pro1_b2_3;
	bool pro1_b3_1;
	bool pro1_b3_2;
	bool pro1_b3_3;
	bool pro1_pedal1_on;
	bool pro1_pedal2_on;
	bool pro1_pedal3_on;

	bool pro2_b1_1;
	bool pro2_b1_2;
	bool pro2_b1_3;
	bool pro2_b2_1;
	bool pro2_b2_2;
	bool pro2_b2_3;
	bool pro2_b3_1;
	bool pro2_b3_2;
	bool pro2_b3_3;
	bool pro2_pedal1_on;
	bool pro2_pedal2_on;
	bool pro2_pedal3_on;

	bool pro3_b1_1;
	bool pro3_b1_2;
	bool pro3_b1_3;
	bool pro3_b2_1;
	bool pro3_b2_2;
	bool pro3_b2_3;
	bool pro3_b3_1;
	bool pro3_b3_2;
	bool pro3_b3_3;
	bool pro3_pedal1_on;
	bool pro3_pedal2_on;
	bool pro3_pedal3_on;

	//DSP variables
	bool reverb_on;
	int reverb_room;
	int reverb_volume;

	int filter_bp;
	int filter_q;
	int filter_base;
	int filter_mid;
	int filter_high;

	int volume_in;
	int volume_out;
};

#endif // MODEL_HPP
