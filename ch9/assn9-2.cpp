#include <iostream>
using namespace std;

void printArray ( double *const n, int N);

int main()
{
    const int N = 10;
    double numbers[N]={10.0,15.2,21.2,10.5,11.3,12.5,13.8,14.7,19.8,20.0};

    printArray(numbers,N);
    return 0;
}

void printArray (double *const num, int size)
{
    for (int i=0; i< size; i++)
    {
        cout <<*(num + i)<< "   ";
    }
}
