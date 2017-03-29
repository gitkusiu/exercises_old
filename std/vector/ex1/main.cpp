#include <iostream>
#include <vector>

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

    
    A a;

    vector<A> v2;
    v2.push_back(a);

	for(int i=0; i<100; i++)
	{
		v2.push_back(a);
	}



    return 0;
}
