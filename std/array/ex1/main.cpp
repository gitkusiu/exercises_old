#include <iostream>
#include <array>

int main()
{
    using std::array;

    const int N = 2;
    typedef array<int,     N> array1D;
    typedef array<array1D, N> attay2D;

    array<int,4> a  = {4, 6, 78};
    array<int,2> a2 = {4, 6};
    array<array<int,2>, 2> aa = { {4,5}, {4,5}  };

    attay2D aa2 = { array1D{1,4}, array1D{1,4} };
}
