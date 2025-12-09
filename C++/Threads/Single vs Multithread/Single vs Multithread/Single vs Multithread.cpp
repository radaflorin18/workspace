#include <thread>
#include <stdint.h>
#include <iostream>

using namespace std;

void SumOfEvenNumbers(int max_nb, int &sum)
{
	int i = 0;
	for (i = 0; i <= max_nb; i++)
	{
		if (0 == (i % 2))
		{
			sum += i;
		}
		//Protection in case of overflow
		if ((INT64_MAX-sum) <= sum)
		{
			sum = -1;
			break;
		}
	}
}

void SumOfOddNumbers(int max_nb, int &sum)
{
	int i = 0;
	for (i = 0; i <= max_nb; i++)
	{
		if (i % 2)
		{
			sum += i;
		}
		//Protection in case of overflow
		if ((INT64_MAX - sum) <= sum)
		{
			sum = -1;
			break;
		}
	}
}


int main()
{
	int res_even = 0;
	int res_odd = 0;

	SumOfEvenNumbers(92681, res_even);
	SumOfOddNumbers(92680, res_odd);


	// Create a new thread that calls myFunction
	//thread newThread(SumOfEvenNumbers, 8, res_even);

	// Wait for the new thread to finish execution
	//newThread.join();

	cout << "Result of even operation is: "<< res_even << endl;
	cout << "Result of odd operation is: " << res_odd << endl;

	return 0;


	return 0;
}