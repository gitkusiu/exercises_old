#include <iostream>
#include <map>
struct A
{
    A(const int & i) : a(i) {}
    bool operator<(const A & l) const {return this->a < l.a;}
    int a;
};


struct comparator
{
    bool operator()(const char & l, const char & r) { return l > r; }
};


int main()
{
    using std::map;
    
    map<char,int> m;
    
    m['a'] = 1;
    m['b'] = 2;
    m['c'] = 3;
    m['d'] = 4;
    m['e'] = 5;
    
    
    for (auto i : m)
        std::cout << i.first << " " << i.second << std::endl;



    map<char,int,comparator> m2;
    
    m2['a'] = 1;
    m2['b'] = 2;
    m2['c'] = 3;
    m2['d'] = 4;
    m2['e'] = 5;
    
    
    for (auto i : m2)
        std::cout << i.first << " " << i.second << std::endl;


    A a=6;
    std::cout << a.a << std::endl;
    
    
    map<A, int> m3;
    
    
    m3[0] = 10;
    m3[1] = 11;
    m3[2] = 12;
    m3[3] = 13;


    for (auto i : m3)
        std::cout << i.first.a << " " << i.second << std::endl;
        
    auto i2 = m3.find(2);
    auto i6 = m3.find(6);

   std::cout << (i2 == m3.end()) << std::endl;
   std::cout << (i6 == m3.end()) << std::endl;

    std::map<char,int> xxx;

    xxx.insert(std::pair<char,int>('r',2));

    std::cout << "KK " << (*xxx.begin()).first << " " << (*xxx.begin()).second << std::endl;

    return 0;
}
