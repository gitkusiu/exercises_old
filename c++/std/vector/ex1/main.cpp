#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
class A
{
public:
	A(){ std::cout << "A::A()" << std::endl; }
	A(const A & a){ std::cout << "A::A(const A &)" << std::endl; }

	A & operator=(const A & a)
	{
		std::cout << "A::operator=(const A & a)" << std::endl;
	}


std::vector<int> v;
int* a;
};



template class std::vector<long>;

int main()
{

    
//    A a;

//    vector<A> v2;
//    v2.push_back(a);

//	for(int i=0; i<100; i++)
//	{
//		v2.push_back(a);
//	}


    std::vector<std::string> v(10,"Yes");

    for(std::string s : v)
        std::cout << s + "\n"<< std::endl;
    
    std::vector<std::string>::iterator b = v.begin();
    std::vector<std::string>::iterator e = v.end();

    std::vector<int> v2;
    for(int i=1; i<10; i++)
        v2.push_back(i);


   for(int i : v2)
        std::cout << i << std::endl;
        
   std::vector<int>::iterator it = std::find(v2.begin(), v2.end(), 5);
   
   std::cout << std::endl << *it << std::endl;
    return 0;
}
