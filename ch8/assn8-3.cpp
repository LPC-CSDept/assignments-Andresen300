#include <iostream>
using namespace std;

int findMin(int [], int, int);
int printArray(int [], int);

int main()
{
	const int N = 10;
	int numbers[N] = {25, 10, 15, 30, 35, 40, 45, 55,20,50};

	printArray(numbers, N);

	for(int i=0;i<N-1;i++)
    {
        int minidx;
        minidx= findMin(numbers, N, i); // Find the i_th smallest number
		swap(numbers[i], numbers[minidx]);
	}

	printArray(numbers, N);

}

int findMin(int numbers[], int N, int ith)
{

	return ith;
}
int printArray(int [], int)
{
	
}
