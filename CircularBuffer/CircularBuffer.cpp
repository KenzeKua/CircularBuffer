#include <iostream>
#include <Windows.h>

#include "CircularBuffer.h"

void CircularBuffer::pushValue(int value)
{
	if (start == -1)
	{
		start = 0;
	}
	end = (end + 1) % maxSize;
	circularBuffer[end] = value;

	// Move the start
	if (end == start)
	{
		start = (start + 1) % maxSize;
	}

	// Size checker
	if (currentSize < maxSize)
	{
		currentSize++;
	}
}
void CircularBuffer::popValue()
{
	if (start == -1 && end == -1)
	{
		std::cout << "Array is empty" << std::endl;
	}
	else
	{
		if (start == end)
		{
			start = end = -1;
			currentSize = 0;
		}
		else
		{
			start = (start + 1) % maxSize;
			currentSize--;
		}
		std::cout << "Popped!" << std::endl;
	}
}

void CircularBuffer::getValue(int location)
{
	if (start <= end)
	{
		std::cout << "Location " << location << " value is " << circularBuffer[end - location] << std::endl;
	}
	else
	{
		if (location <= end)
		{
			std::cout << "Location " << location << " value is " << circularBuffer[end - location] << std::endl;
		}
		else
		{
			location -= end;
			std::cout << "Location " << location << " value is " << circularBuffer[maxSize - location] << std::endl;
		}
	}
}
void CircularBuffer::getSize()
{
	std::cout << "Current size: " << currentSize << "\n";
}
void CircularBuffer::getFront()
{
	if (start == -1 && end == -1)
	{
		std::cout << "Nothing to show\n";
	}
	else
	{
		std::cout << "Front: " << circularBuffer[start] << "\n";
	}
}
void CircularBuffer::getBack()
{
	if (start == -1 && end == -1)
	{
		std::cout << "Nothing at the back\n";
	}
	else
	{
		std::cout << "Back: " << circularBuffer[end] << "\n";
	}
}

void CircularBuffer::display()
{
	if (start == -1 && end == -1)
	{
		std::cout << "[ E M P T Y ]";
	}
	else
	{
		if (start <= end)
		{
			for (int i = start; i <= end; i++)
			{
				std::cout << "(" << circularBuffer[i] << ") ";
			}
		}
		else if (start > end)
		{
			int i = start;
			while (i < maxSize)
			{
				std::cout << "(" << circularBuffer[i] << ") ";
				i++;
			}

			i = 0;
			while (i <= end)
			{
				std::cout << "(" << circularBuffer[i] << ") ";
				i++;
			}
		}
	}
	std::cout << "\n\n";
}
