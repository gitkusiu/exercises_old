#include <thread>
#include <iostream>
#include <vector>

void my_thread_func()
{
    std::cout << "My first thread..." << std::endl;
}


std::vector<int> v={1,2,3,4,5,6};

int main()
{
    std::thread t(my_thread_func);
    
    
//    std::thread t2([]{
//                      for(int i : v)
//                            std::cout << "t2 "<< i << std::endl;
//                      });
//                      
//                      
//    std::cout << "t id " << t.get_id() << std::endl;
//    std::cout << "t2 id " << t2.get_id() << std::endl;
    t.join();
//    t2.join();
    
    
    
//    std::end << "Jestem th 1" << std::endl;
    
//    std::thread th([]{
//                        std::cout << "Jestem th 1" << std::endl;
//                      });
//    th.join();
    
    return 0;
}
