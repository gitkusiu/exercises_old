#include <iostream>
#include <array>
#include <list>

int main()
{
//    using std::vector;
    
//    vector<int> v1();

    std::list<int> l({1,2,3,4,5,6,7,8,9});

    for(int i : l)
        std::cout << i << std::endl;

    std::cout << std::endl;

    l.remove_if([](const int & val) {return val == 4 ? true:false ;});

    for(int i : l)
        std::cout << i << std::endl;
    return 0;
}
