//#define _CRT_SECURE_NO_WARNINGS //for errors regarding deprecated ctime functions
#include <thread>
#include <iostream>
#include <stdint.h> //for macro UINT64_MAX
#include <ctime>

using namespace std;

//Something to process: sum of first N even numbers
void SumOfEvenNumbers(unsigned int max_nb, unsigned int &sum)
{
	sum = 0;
	for (unsigned int i = 0; i <= max_nb * 2; i++)
	{
		if (0 == (i % 2))
		{
			sum += i;
		}
		//Protection in case of overflow
		if ((UINT64_MAX - sum) <= sum)
		{
			sum = 0;
			break;
		}
	}
}

//Something to process: sum of first N odd numbers
void SumOfOddNumbers(unsigned int max_nb, unsigned int &sum)
{
	sum = 0;
	for (unsigned int i = 0; i <= max_nb * 2; i++)
	{
		if (i % 2)
		{
			sum += i;
		}
		//Protection in case of overflow
		if ((UINT64_MAX - sum) <= sum)
		{
			sum = 0;
			break;
		}
	}
}


int main()
{
	unsigned int selection, max_nb = 0;
	unsigned int res_even = 0;
	unsigned int res_odd = 0;

	cout << "Please select a running method: " << endl;
	cout << "[1] Sequential" << endl;
	cout << "[2] Multithread" << endl;
	do {
		cout << "Choose a number between 1 and 2" << endl;
		cin >> selection;
	} while (selection < 1 || selection> 2);  // Keep asking until the user enters a number between 1 and 5
	cout << "Please input the maximum number: " << endl;
	while (!(cin >> max_nb)) {  // Keep asking until the user enters a valid number
		cout << "Invalid input. Try again: ";
		cin.clear(); // Reset input errors
		cin.ignore(10000, '\n'); // Remove bad input
	}

	//Get the timestamp for the current date and time
	clock_t start = clock();

	switch (selection)
	{
		case 1:
		{
			SumOfEvenNumbers(max_nb, res_even);
			SumOfOddNumbers(max_nb, res_odd);
			break;
		}
		case 2:
		{
			// Create a new thread that calls myFunction
			thread Even(SumOfEvenNumbers, max_nb, ref(res_even));
			thread Odd(SumOfOddNumbers, max_nb, ref(res_odd));

			// Wait for the new threads to finish execution
			Even.join();
			Odd.join();
			break;
		}
		default:
		{
			cout << "Please input a valid selection!" << endl;
			break;
		}
	}
	clock_t duration = clock() - start;

	cout << "Result of even operation is: "<< res_even << endl;
	cout << "Result of odd operation is: " << res_odd << endl;
	// Display the runtime duration
	cout << "Duration: " << (float)duration / CLOCKS_PER_SEC << " seconds" << endl;
	cin.get();
		
	return 0;
}