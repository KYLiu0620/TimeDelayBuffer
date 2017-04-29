
#include <iostream>
#include <time.h>
#include <Windows.h>
#include "../TimeDelayBuffer/TimeDelayBuffer.h"



int main()
{
	int testData[]	= { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int delay[] = { 0, 50, 150, 50, 150, 150, 300, 50, 300, 100 };
	DelayedBuffer testBuf = DelayedBuffer();
	
	for (int i = 0; i < 10; i++)
	{
		DelayedData input = DelayedData(testData[i], i+1, clock() + delay[i]);
		testBuf.addData(input);
		std::cout << i << " : " << testBuf.getData(clock()) << std::endl;
		Sleep(100);		
	}

	system("PAUSE");
	return 0;
}