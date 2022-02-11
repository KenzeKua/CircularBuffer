#include <iostream>
#include <Windows.h>

#include "CircularBuffer.h";

int userOption = 0;
int pushValue = 0;
int locNum = 0;

int main(void)
{
	CircularBuffer circularBuffer;

	while (true)
	{
		circularBuffer.display();

		std::cout << "1) Push in value" << std::endl;
		std::cout << "2) Pop value" << std::endl;
		std::cout << "3) Get value" << std::endl;
		std::cout << "4) Get size" << std::endl;
		std::cout << "5) Get front" << std::endl;
		std::cout << "6) Get back" << std::endl;
		std::cout << "7) Exit" << std::endl;
		std::cout << "\n";

		std::cout << "Option: ";
		std::cin >> userOption;
		std::cout << "\n";
		if (userOption == 1)
		{
			std::cout << "Value to add: ";
			std::cin >> pushValue;
			circularBuffer.pushValue(pushValue);
		}
		else if (userOption == 2) { circularBuffer.popValue(); }
		else if (userOption == 3)
		{
			std::cout << "Location: ";
			std::cin >> locNum;
			std::cout << "\n";
			circularBuffer.getValue(locNum);
		}
		else if (userOption == 4) { circularBuffer.getSize(); }
		else if (userOption == 5) { circularBuffer.getFront(); }
		else if (userOption == 6) { circularBuffer.getBack(); }
		else if (userOption == 7)
		{
			std::cout << "Exiting" << std::endl;

			break;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
		}
		std::cout << "\n";

		system("PAUSE");
		system("CLS");
	}

	return 0;
}