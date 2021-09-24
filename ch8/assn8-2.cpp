#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void makeArray(int[], int);
void printArray(int[],int);
int linearSearch (int[],int,int);
void bubbleSort(int[], int);
int binarySearch (int[], int, int);

int main()
{
  const int N = 64;
  int array[N];
  int target;
  int total_linear, total_binary;

  srand(time(0));
  makeArray(array, N);
  printArray(array, N);

  for (int i=0; i<100; i++)
  {
      target = array[rand()% N];
      total_linear+=linearSearch(array, N, target);
  }
  cout << "My target value is "<<target << endl;
  cout<<"It took " << total_linear <<" times for linear search to find it \n";

  bubbleSort(array, N);
  printArray(array,N);
  for(int i=0; i<100; i++)
  {
      target = array[rand()% N];
      total_binary+=binarySearch(array, N, target);
  }
  cout << "My target value is "<<target << endl;
  cout<<"It took " << total_binary <<" times for binary search to find it \n";
}
void makeArray(int array[], int N)
{
    for (int i=0; i < N; i++)
        array[i]=rand()%100+1;
}

void printArray(int array[], int N)
{
    for (int i=0; i<N; i++)
        {
            cout << array[i]<< "\t";
            if (i % 8 ==7)
                cout << endl;
        }
}
int linearSearch (int array[], int N, int target)
{
    int index = 0;
    int position =-1;
    bool found = false;

    while (index < N && !found)
    {
        if(array[index] == target)
        {
            found = true;
            position = index;
        }
        index++;
    }
        return position;
}
void bubbleSort(int array[], int N)
{
    int min, index;
    for (int i=0; i < N-1; i++)
    {
        for(int j=0; j<N-i-1; j++)
        {
            if(array[j]>array[j+1])
                swap (array[j], array[j+1]);
        }
    }
}
int binarySearch(int array[], int N, int target)
{
    int first =0,
        last = N-1,
        middle,
        position = -1;
    bool found = false;

    while(!found && first <= last)
    {
        middle = (first + last)/2;
        if (array[middle]== target)
        {
            found = true;
            position = middle;
        }
        else if ( array[middle]> target)
            last = middle-1;
        else
            first = middle +1;
    }
    return position;
}
