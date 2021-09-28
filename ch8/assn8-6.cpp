#include <iostream>
#include <fstream>
using namespace std;

const int 	MAX_LEN = 20;
const int 	NUM_SCORES = 3;
struct Students {
	int 	sid;
	char 	sname[MAX_LEN];
	double 	scores[NUM_SCORES];
};

void bubbleSortbyID(Students [], int );
int binarySearch(Students [], int, int);
void makeStudents(Students [], int );
void printStudents(Students [], int );

int main()
{
	const int 	N = 10;
	Students 	s[N];
	int 	target, foundidx;

	makeStudents(s, N);
	cout << "Initial Student's Struct Array \n";
	printStudents(s, N);
	bubbleSortbyID(s, N);
	cout << "After Sorting by ID \n";
	printStudents(s, N);

	cout << "Enter the student's ID you want to retrieve : ";
	cin >> target;
	foundidx = binarySearch(s, N, target);
	if ( foundidx == -1)
		cout << " The student's ID " << target << " is not found \n";
	else
	{
		cout << " The student's name " << s[foundidx].sname << endl << " Scores ";
		for (int i=0; i< NUM_SCORES; i++)
			cout << s[foundidx].scores[i] << "\t" ;
		cout << endl;
	}

}

void bubbleSortbyID(Students s[], int N)
{
    int maxElement;
    int index;
    for(maxElement = N-1; maxElement > 0; maxElement--)
    {
        for(index = 0; index < maxElement; index++)
        {
            if (s[index].sid> s[index+1].sid)
            {
                swap (s[index].sid, s[index+1].sid);
            }
        }
    }
}
int binarySearch(Students s[], int N, int target)
{
    int first = 0,
        last = N-1,
        middle,
        position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last)/2;
        if(s[middle].sid == target)
            {
                found = true;
                position = middle;
            }
        else if (s[middle].sid > target)
            last =middle-1;
        else
            first = middle + 1;
    }
    return position;
}

void makeStudents(Students s[], int N)
{
	ifstream ifs;
	ifs.open("students.txt");
	if ( ifs.fail())
	{
		cerr << "File Open Error\n";
		exit(0);
	}

	for(int i=0;i<N;i++)
	{
		ifs >> s[i].sid >> s[i].sname;
		for(int j=0; j<NUM_SCORES; j++)
			ifs >> s[i].scores[j] ;
		if ( ifs.fail() )
		{
			cerr << "File Read Error\n";
			exit(0);
		}
	}
}

void printStudents(Students s[], int N)
{
	for(int i=0;i<N;i++)
	{
		cout << s[i].sid << "\t" << s[i].sname << "\t";
		for(int j=0; j<NUM_SCORES; j++)
			cout <<  s[i].scores[j] << "\t";
		cout << endl;
	}
	cout << "==== End of Record === \n";
}

