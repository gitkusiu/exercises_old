#include<iostream>
//#include <stdlib.h> 

#include <cstdlib>
#include <ctime>
//#include <experimental/random>

// to właśnie jest zmiana na branhcu NEW


// i jeszcze jedna zmaiana




// To jest zmiana na branchu new


// To jest druga zmiana na branchu master


// To jest trzecia zmiana na branchu master

// Tutaj nowe



// zmiany na master

// smaina na new2
// druga smaina na new2

//332343453
//uyuytyutyu

//kkkkkkk
//345345345345

//j/hjghjghkghkghk

//hjkhjkhjkhj

bool is_sorted(int * t, const int n)
{
    for(int i=0; i<n-1; i++)
    {
        if(t[i] > t[i+1]) return false;
    }
    return true;
}

void print(int * t, const int n)
{
    std::cout << "t = { ";
    for(int i=0;i<n; i++)
    {
        std::cout << t[i] << " ";
    }

    std::cout << "}" << " : " <<  ((is_sorted(t,n)) ? " YES " : " NOT ") << std::endl;
}




void flip(int i, int j, int * t)
{
    std::cout << " | "
    //"t[" << i << "] <-> t[" << j << "] : " << 
    << t[i] << " <-> " << t[j] ;
    int tmp = t[i];
    t[i] = t[j];
    t[j] = tmp;
}

void moveup(int i, int * t)
{
    int father = (i%2==0) 
               ? (i-2)/2 
               : (i-1)/2;

    if( t[i]>t[father] && i>0)
    {
        flip(i,father,t);
        moveup(father,t);
    }
}



void movedown(int i, int n, int * t)
{
    int l = 2*i+1; // left child
    int r = 2*i+2; // right child
    int child = (t[l]<t[r] && n>2)  
              ? r 
              : l;

    if( t[i]<t[child] && child<n)
    {
      //  std::cout << i << " " << child << " before " << t[i] << "  "  << t[child] << std::endl;
        flip(i,child,t);
       // std::cout << i << " " << child << " after " << t[i] << "  "  << t[child] << std::endl;
        movedown(child,n,t);
    }
}

void make_heap(int n, int * t)
{
    for(int i=1; i<n; i++)
    {
        moveup(i,t);
    }
}
//void update()





int main()
{
    //int N = 8; int t[N] = {20,89,10,202,16,2, 6, 7};
   // int N = 14; int t[N] = {20,89,10,202,16,2, 6, 7,4,8,1,0,145,897};
    //int N = 5; int t[N] = {20,89,10,202,16};
    
    std::srand(std::time(0));
    
    int N = 100; 
    int t[N];
    for(int i = 0; i<N; i++)
    {
        t[i] = std::rand()%(5*N);
    }
    
    print(t,N);

    make_heap(N,t);
    
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
    
    for(int i = N-1; i>0; i--)
    {
        print(t,N);
        std::cout << "i = " << i ;
        flip(0,i,t);
        //std::cout << "i = " << i << "; "; print(t,N);
        std::cout << " | move ";
        movedown(0,i,t);
        //std::cout << "i = " << i << "; "; print(t,N);
        std::cout << std::endl;
        std::cout << std::endl;
    }
    
    
    print(t,N);
    
    return 0;
}
