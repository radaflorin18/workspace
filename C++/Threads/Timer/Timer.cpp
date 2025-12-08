#include <iostream>
#include <functional> //for lambda expression
#include <chrono> //for chrono literals

#include <future> //includes also thread
using namespace std::chrono_literals;

template<class _Rep, class _Period>
std::future<void> TimerAsync(std::chrono::duration<_Rep, _Period>duration, std::function<void()> callback)
{
	return std::async(std::launch::async, [duration, callback]()
		{
			std::this_thread::sleep_for(duration);
			callback();
		});

}

int main()
{

	auto future = TimerAsync(5s, []() {std::cout << "Timer finished! \n"; });

	//Process the main thread here
	while (true)
	{
		std::cout << "Processing..." << std::endl;
		std::this_thread::sleep_for(1s);

		//Optionally terminate program when the timer expires
		auto status = future.wait_for(1ms);
		if (std::future_status::ready == status)
			break;
	}

	std::cout << "Finished!" << std::endl;

	return 0;
}