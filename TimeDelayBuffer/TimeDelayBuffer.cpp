#include "TimeDelayBuffer.h"

DelayedData::DelayedData()
{
	data = 0;
	number = 0;
	delay = 0;
}

DelayedData::DelayedData(int input_data, int data_no, int time)
{
	data = input_data;
	number = data_no;
	delay = time;
}

DelayedData::~DelayedData()
{
	//do nothing
}

DelayedBuffer::DelayedBuffer()
{
	lastOutput = DelayedData(0 ,0 ,0);
	latestDataNum = 0;
}

DelayedBuffer::~DelayedBuffer()
{
	//do nothing
}

void DelayedBuffer::addData(DelayedData newData)
{
	bool addSuccess = false;

	if (buf.empty())
	{
		buf.push_back(newData);
	}
	else
	{
		for (std::list<DelayedData>::iterator itr = buf.begin(); itr != buf.end(); ++itr)
		{
			if (newData.delay < itr->delay)
			{
				buf.insert(itr, newData);
				addSuccess = true;
				break;
			}			
		}

		if (!addSuccess)
			buf.push_back(newData);

	}
	
}

int DelayedBuffer::getData(int currentTime)
{
	DelayedData temp = lastOutput;
	bool noDataArrived = true;
	std::list<DelayedData>::iterator itr = buf.begin();


	if (!buf.empty())
	{
		while ( itr != buf.end())
		{
			if (currentTime < itr->delay)
			{
				if (noDataArrived)
					return lastOutput.data; 
				break;
			}
			
			else
			{
				noDataArrived = false;
				if (itr->number > latestDataNum/*this condition might be unnecessary*/ && itr->number > temp.number)	//multiple data arrived. choose latest one
				{
					temp = *itr;
					latestDataNum = temp.number;
				}

				itr = buf.erase(itr);	//erase and shift itr to next one
			}
		}
	}
	else
	{
		return lastOutput.data;
	}

	lastOutput = temp;
	latestDataNum = temp.number;
	return temp.data;
}	//getData
