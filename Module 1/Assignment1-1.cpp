#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
  int id;
  string sname;
  double score[2];
  double avg;
  double sum;
};

int main()
{
  ifstream ifs;
  Student s;
  ifs.open("students.txt");

  for (int i = 0; i< 10; i++)
  {
  ifs >>  s.id;
  cout << s.id << "\t";
  ifs >> s.sname;
  cout<< s.sname << "\t";
  ifs >>s.score[0];
  ifs >>s.score[1];
  cout << s.score[0]<< " " << s.score[1] << endl;
  s.sum = s.score [0] + s.score[1];
  s.avg = s.sum/2;
  cout << s.sum<< " " << s.avg << endl;
  }

}

