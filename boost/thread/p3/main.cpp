#include <boost/thread/thread.hpp>
#include <iostream>
#include <cstdio>
////using namespace boost;
////using namespace boost::this_thread;
using namespace std;

class PowerClass
{
private:
 
// Version II: m will be a large matrix
int m, n; // Variables for m^n
 
public:
double result; // Public data member for the result
 
// Constructor with arguments
PowerClass(int m, int n)
{
this->m=m; this->n=n;
this->result=0.0;
}
 
// Calculate m^n. Supposes n>=0
void operator () ()
{
result=m; // Start with m^1
for (int i=1; i<n; ++i)
{
result*=m; // result=result*m
boost::this_thread::yield();
}
if (n==0) result=1; // m^0 is always 1
}
};



int main()
{
int m=2;
int n=20000;
 
// Create a m^n calculation object
PowerClass pc(m, n);
 
// Create thread and start m^n calculation in parallel
// Since we read the result from pc, we must pass it as reference,
// else the result will be placed in a copy of pc
boost::thread t(boost::ref(pc));
 
// Do calculation while the PowerClass is calculating m^n
double result=m*n;
 
// Wait till the PowerClass is finished
// Leave this out and the result will be bogus
t.join();
 
// Display result.
cout << "(" << m << "^" << n << ") / (" << m << "*" << n
  << ") = "<<pc.result/result<<endl;
}


//int main()
//{
//  boost::thread t;
//  t.join();
//}
