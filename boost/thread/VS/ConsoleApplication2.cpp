#include <boost/thread/thread.hpp>
#include <iostream>

////using namespace boost;
////using namespace boost::this_thread;
using namespace std;

void GlobalFunction()
{
	for (int i = 0; i<10; ++i)
	{
		cout << i << "Do something in parallel with main method." << endl;
		//        boost::this_thread::yield(); // 'yield' discussed in section 18.6
		//        boost::this_thread::yield();
	}
}

int main()
{
	boost::thread t(&GlobalFunction);
	//    boost::thread t2(&GlobalFunction);
	for (int i = 0; i<10; i++)
	{
		cout << i << "Do something in main method." << endl;
		boost::this_thread::yield();
	}
	t.join();
	//    t2.join();
	int g;
	std::cin >> g;
	return 0;
}


//int main()
//{
//  boost::thread t;
//  t.join();
//}
