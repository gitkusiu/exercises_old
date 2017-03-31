#include <iostream>
#include <list>
#include <string>
#include <algorithm>

class A {};
int main()
{

    using namespace std;
    list<int> l({1,2,3,4,5,6,7});

    for(int i : l)
        cout << i << endl;
    cout << endl;

    l.remove_if( [](const int & i){return i>6;} );

    for(int i : l)
        cout << i << endl;
    cout << endl;

    auto lt5 = [](int i) {return i>5;};
    l.remove_if(lt5);

    for(int i : l)
        cout << i << endl;
    cout << endl;


    auto lt3 = [](int i) {return i>3;};

    std::cout << std::count_if(l.begin(), l.end(), lt3);
    cout << endl;
    return 0;
}
