#include<algorithm>
#include<vector>
#include<iostream>
#include<numeric>

int main()
{
  {
    std::cout << std::endl << "--------- for_each  --------- "<< std::endl;
	std::vector<int> v = {1,2,3,4,5};
    std::cout << "before increment v = " ; for(auto i : v) std::cout << i ; std::cout << std::endl;
    auto increment = [&](int& i){ i++;};
    std::for_each(v.begin(), v.end(), increment);
	std::cout << "after increment v = " ; for(auto i : v) std::cout << i ; std::cout << std::endl;

    std::cout << "accumulate(v) = " <<  std::accumulate(v.begin(), v.end(),0) << std::endl;
  }
  {
    std::cout << std::endl << "--------- sort  --------- "<< std::endl;
    std::vector<int> v = {4,6,8,2,0};
    std::cout << "before sort v = " ; for(auto i : v) std::cout << i ; std::cout << std::endl;
    std::sort(v.begin(),v.end());
    std::cout << "after sort v = " ; for(auto i : v) std::cout << i ; std::cout << std::endl;
  }

  {
    std::cout << std::endl << "--------- std::transform --------- "<< std::endl;
    std::cout << "with function which make a sum on two elements "<< std::endl;
    
    std::vector<int> v1 = {11,12,13,14,15};
    std::vector<int> v2 = {21,22,23,24,25,4};
    std::vector<int> vSum;
    std::cout << "before sum : v1  = " ; for(auto i : v1) std::cout << i ; std::cout << std::endl;
    std::cout << "before sum : v2  = " ; for(auto i : v2) std::cout << i ; std::cout << std::endl;
    std::cout << "before sun : sum = " ; for(auto i : vSum) std::cout << i ; std::cout << std::endl;

    auto sum = [](int x, int y){return x+y;};
    std::transform(v1.begin(), v1.end(), v2.begin() , std::back_inserter(vSum), sum);

    std::cout << "after sum : v1  = " ; for(auto i : v1) std::cout << i ; std::cout << std::endl;
    std::cout << "after sum : v2  = " ; for(auto i : v2) std::cout << i ; std::cout << std::endl;
    std::cout << "after sun : sum = " ; for(auto i : vSum) std::cout << i ; std::cout << std::endl;
  }
  {
    std::cout << std::endl << "--------- std::nth_element --------- "<< std::endl;
    std::vector<int> v1 = {2,0,4,3,6};
    
    std::cout << "before nth_element : v1  = " ; for(auto i : v1) std::cout << i ; std::cout << std::endl;

    std::nth_element(v1.begin(), std::next(v1.begin(),2), v1.end());

    std::cout << "before nth_element : v1  = " ; for(auto i : v1) std::cout << i ; std::cout << std::endl;;
  }
  {
    std::cout << std::endl << "--------- equal_range  --------- "<< std::endl;
    std::vector<int> v1 = {2,4,5,6,7,3,2,3,6,7,8,9,4,3,6};
    
    std::cout << "before sort : v1  = " ; for(auto i : v1) std::cout << i ; std::cout << std::endl;
    std::sort(v1.begin(), v1.end());
    std::cout << "after sort : v1  = " ; for(auto i : v1) std::cout << i ; std::cout << std::endl;

    auto range5 = std::equal_range(v1.begin(), v1.end(),6);
    std::cout << "5 is in rage v1[" << std::distance(v1.begin(), range5.first) << "] and v1["<< std::distance(v1.begin(), range5.second) << "]." << std::endl;
  }

{
    std::cout << std::endl << "--------- equal_range  --------- "<< std::endl;
    std::vector<int> v1 = {2,4,5,6,7,3,2,3,6,7,8,9,4,3,6};
    
    std::cout << "before sort : v1  = " ; for(auto i : v1) std::cout << i ; std::cout << std::endl;
    std::sort(v1.begin(), v1.end());
    std::cout << "after sort : v1  = " ; for(auto i : v1) std::cout << i ; std::cout << std::endl;

    auto range5 = std::equal_range(v1.begin(), v1.end(),6);
    std::cout << "5 is in rage v1[" << std::distance(v1.begin(), range5.first) << "] and v1["<< std::distance(v1.begin(), range5.second) << "]." << std::endl;
  }  

    int s[3] = {1,4,5};
    std::cout << "std::next(s) " << *std::next(s) << std::endl; 
	return 0;
}

