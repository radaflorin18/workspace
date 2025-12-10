#include <thread>
#include <iostream>
#include <stdint.h> //for macro UINT64_MAX

using namespace std;

void SumOfEvenNumbers(int max_nb, int &sum)
{
	sum = 0;
	for (int i = 0; i <= max_nb; i++)
	{
		if (0 == (i % 2))
		{
			sum += i;
		}
		//Protection in case of overflow
		if ((UINT64_MAX - sum) <= sum)
		{
			sum = -1;
			break;
		}
	}
}

void SumOfOddNumbers(int max_nb, int &sum)
{
	sum = 0;
	for (int i = 0; i <= max_nb; i++)
	{
		if (i % 2)
		{
			sum += i;
		}
		//Protection in case of overflow
		if ((UINT64_MAX - sum) <= sum)
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

	//SumOfEvenNumbers(92681, res_even);
	//SumOfOddNumbers(92680, res_odd);


	// Create a new thread that calls myFunction
	thread Even(SumOfEvenNumbers, 92681, ref(res_even));
	thread Odd(SumOfOddNumbers, 92680, ref(res_odd));

	// Wait for the new thread to finish execution
	Even.join();
	Odd.join();

	cout << "Result of even operation is: "<< res_even << endl;
	cout << "Result of odd operation is: " << res_odd << endl;

	return 0;
}