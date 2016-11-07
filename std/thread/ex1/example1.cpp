#include <thread>
#include <iostream>

void my_thread_func()
{
	std::cout << "My first thread..." << std::endl;
}

int main()
{
	std::thread t(&my_thread_func);
	t.join();
}