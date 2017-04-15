#include <thread>
#include <iostream>
#include <vector>


using namespace std;
void my_thread_func()
{
    std::cout << "My first thread ... " << std::endl;
}


class A
{
    public:
        void operator()()
        {
            std::cout << "A::operator();" << std::endl;
        }
};

std::vector<int> v={1,2,3,4,5,6};

int main()
{
//    std::thread t(my_thread_func);
//    std::cout << "t id " << t.get_id() << std::endl;
//    t.join();


    std::thread th([](int i){
                        std::cout << "Jestem th 1" <<" called with int i=" << i << std::endl;
                      }, 8);
    std::cout << "th id " << th.get_id() << std::endl;
    th.join();

    std::thread t2([]{
                      for(int i : v)
                            std::cout << "t2 "<< i << std::endl;
                      });
    cout  << "t2 id " << t2.get_id()  << ": is joinable? " << t2.joinable() << "  KK" << endl;
//    t2.join();
//    cout  << "t2 id " << t2.get_id()  << ": is joinable? " << t2.joinable() << endl;
//    t2.join();

    return 0;
}
