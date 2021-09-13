#include <iostream>
using namespace std;


int main()
{
    const int SIZE =10;
    int numbers [10] ={25,10,15,30,35,40,45,55,20,50};
    int target = 20;

    bool flag = false;
    for (int i=0; i < SIZE; i++)
    {
        if(numbers[i] == target)
            cout << "Found at index : "<< i+1 << endl;
        flag = true;

    }
    if (!flag)
        cout << "Not found\n";
}
