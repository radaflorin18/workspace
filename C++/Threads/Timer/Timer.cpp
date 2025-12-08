#include <iostream>
#include <functional> //for lambda expression
#include <chrono> //for chrono literals

#include <future> //includes also thread
using namespace std::chrono_literals;

//use a template for chrono literals (s, ms, etc...)
template<class _Rep, class _Period>
std::future<void> TimerAsync(std::chrono::duration<_Rep, _Period>duration, std::function<void()> callback)
{
	return std::async(std::launch::async, [duration, callback]()
		{
			std::cout << "Timer started on thread ID: " << std::this_thread::get_id() << std::endl;
			std::this_thread::sleep_for(duration);
			callback();
		});
}

int main()
{
	auto my_callback = []() {std::cout << "Timer expired on thread ID: " << std::this_thread::get_id() << std::endl; };
	auto future = TimerAsync(10s, my_callback);

	//Process the main thread here
	while (true)
	{
		std::cout << "Processing thread ID:"<< std::this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(1s);

		//Optionally terminate program when the timer expires
		auto status = future.wait_for(1ms);
		if (std::future_status::ready == status)
			break;
	}

	std::cout << "Program finished!" << std::endl;

	return 0;
}