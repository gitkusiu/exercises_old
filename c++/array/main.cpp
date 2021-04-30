#include<array>
#include<iostream>


int main()
{
//	std::array<int,2> r1{1,1};
	int r1[2] = {1,1};
	std::array<int,10> r{r1,r1};

	for(int i{0}; i < r.size(); i++)
	{
		std::cout << r[i] << std::endl;
	}
	return 0;
}
