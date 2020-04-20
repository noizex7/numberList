#include "Number.h"

void printMenu();
void menu(int, Number&);
void fillArray(Number&);
void changeItem(Number&);
void compare(Number&);
void printArray(const Number&);
void printInfo(Number);

int main()
{
	int size, choice;

	do
	{
		cout << "Enter the amount of numbers you need:\n";
		cin >> size;
		if (size <= 0)
		{
			cout << "Invalid amout, try again\n";
		}
	} while (size <= 0);


	Number n(size);

	do
	{
		printMenu();

		cout << endl;

		cin >> choice;

		cout << endl;

		menu(choice, n);

	} while (choice != 6);
}

void printMenu()
{
	cout << "Number Menu:\n"
		<< "1- Fill Array of numbers\n"
		<< "2- Change a number in the array\n"
		<< "3- Compare Array\n"
		<< "4- Print Array\n"
		<< "5- Highest, lowest and average\n"
		<< "6- Exit";
}

void menu(int choice, Number& aN)
{
	switch (choice)
	{
	case 1:
		fillArray(aN);
		break;
	case 2:
		changeItem(aN);
		break;
	case 3:
		compare(aN);
		break;
	case 4:
		printArray(aN);
		break;
	case 5:
		printInfo(aN);
		break;
	case 6:
		cout << "Goodbye!!!\n";
		break;

	default:
		cout << "Invalid option, try again\n";
		break;
	}
}

void fillArray(Number& aN)
{
	cin >> aN;
	cout << "\n\n";
}

void changeItem(Number& aN)
{
	int item;
	do
	{
		cout << "Enter the item you want to change:\n";
		cin >> item;
		if (item <= 0 || item > aN.getIndex())
		{
			cout << "Invalid item, try again\n";
		}
	} while (item <= 0 || item > aN.getIndex());

	cout << "Enter a number for item #" << item << endl;
	cin >> aN[item - 1];

	cout << "\n\n";
}

void compare(Number& aN)
{
	int size;
	do
	{
		cout << "Enter the amount of numbers you need:\n";
		cin >> size;
		if (size <= 0)
		{
			cout << "Invalid amout, try again\n";
		}
	} while (size <= 0);

	Number b(size);

	fillArray(b);

	if (b == aN)
	{
		cout << "The arrays are the same\n";
	}
	else
	{
		cout << "The arrays are not the same\n";
	}

	cout << "Array:\n" << aN
		<< "New Array:\n" << b;

	cout << "\n\n";

}

void printArray(const Number& aN)
{
	cout << aN;

	cout << "\n\n";
}

void printInfo(Number aN)
{
	cout << "Highest number: " << aN.getHighest()
		<< "\nLowest number: " << aN.getLowest()
		<< "\nAverage: " << aN.getAverage();

	cout << "\n\n";
}

