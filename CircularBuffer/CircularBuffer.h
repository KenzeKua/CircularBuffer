#pragma once

class CircularBuffer
{
private:
	int maxSize;
	int currentSize;
	int start;
	int end;

	int circularBuffer[];

public:
	CircularBuffer()
	{
		maxSize = 5;
		currentSize = 0;
		start = -1;
		end = -1;

		circularBuffer[maxSize] = { 0 };
		
		for (int i = 0; i < maxSize; i++)
		{
			std::cout << "Init: Loc = " << i << " || Value = " << circularBuffer[maxSize] << std::endl;
		}
		std::cout << "==========================\n\n";
	}

	void pushValue(int value);
	void popValue();

	void getValue(int location);
	void getSize();
	void getFront();
	void getBack();

	void display();
};