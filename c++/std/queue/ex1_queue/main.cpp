#include <iostream>
#include <queue>

int main()
{
    using std::queue;
    using std::priority_queue;
    
    queue<int> q;

    const int N = 5;

	for(int i =0; i<N; i++)
    {
        q.push(i);
    }


	while(q.size() > 0)
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;

    queue<int> q2;

    q2.push(50);
    q2.push(40);
    q2.push(45);
    q2.push(37);
    q2.push(78);

	while(q2.size() > 0)
    {
        std::cout << q2.front() << " ";
        q2.pop();
    }
    std::cout << std::endl;


    priority_queue<int> q3;

    q3.push(50);
    q3.push(40);
    q3.push(45);
    q3.push(37);
    q3.push(78);

	while(q3.size() > 0)
    {
        std::cout << q3.top() << " ";
        q3.pop();
    }
    std::cout << std::endl;


    return 0;
}
