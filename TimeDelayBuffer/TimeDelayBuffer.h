#ifndef _TIMEDELAYBUFFER_H_
#define _TIMEDELAYBUFFER_H_
//#include <armadillo>
#include <list>

class DelayedData
{
public:
	DelayedData();
	DelayedData(int input_data,int data_no,int time);
	~DelayedData();

	//arma::mat data;
	int data;
	int number;
	int delay;
};

class DelayedBuffer
{
public:
	DelayedBuffer();
	~DelayedBuffer();
	void addData(DelayedData newData);
	int getData(int currentTime);
	
	std::list <DelayedData> buf;
	DelayedData lastOutput;
};

#endif//_TIMEDELAYBUFFER_H_