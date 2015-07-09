// LAB 6b: Using A Data Structure As A Data Member
// Programmer: Ibrahim Altaweel
// Editor(s) used: Code::Blocks
// Compiler(s) used: GNU GCC Compiler

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <iomanip>
#include <map>
using namespace std;
#include <cstring>
#include <cstdlib>
#include <ctime>

int main()
{
  // print my name and this assignment's title
  cout << "LAB 6b: Using A Data Structure As A Data Member\n";
  cout << "Programmer: Ibrahim Altaweel\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  map<string, map<string, int> > outer_map;
  set<string> term_sections;


  //declare the variables
  int num_of_lines = 0;
  int num_of_duplicates=0;



  // for parsing the input file
  char* token;
  char buf[1000];
  const char* const tab = "\t";

  clock_t startTime;
  startTime = clock();

  // open the input file
  ifstream fin;

  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  // read the input file
  while (fin.good())
  {
    // read the line
    string line;
    getline(fin, line);
    num_of_lines++;
    if (num_of_lines==1000)
    {
      cout<<".";
      cout.flush();
      num_of_lines=0;
    }

    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;

    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));




    //cout<<term+section<<endl;

    //if subjectcode in outer map
    if (outer_map.find(subjectCode)==outer_map.end())
    {

      map<string,int> inner_map;
      inner_map[course]=1;
      outer_map[subjectCode]=inner_map;
      term_sections.insert(term+section);
    }
    else
    {
      if (outer_map[subjectCode].find(course)==outer_map[subjectCode].end())
      {

        outer_map[subjectCode][course]=1;
        term_sections.insert(term+section);
      }

      else
      {
           if (term_sections.count(term+section)==1)
           {
             num_of_duplicates++;
             continue;

           }
           else
           {
             outer_map[subjectCode][course]++;
             term_sections.insert(term+section);
           }
      }
    }

    }

  typedef map<string, map<string, int> >::iterator it_type;

  for(it_type iterator = outer_map.begin(); iterator != outer_map.end(); iterator++)
  {
    cout<<iterator->first<<" "<<(iterator->second).size()<<" course(s)"<<endl;
    map<string,int> inner_map = iterator->second;
    typedef map<string,int>::iterator it_type_1;

    for (it_type_1 iterator1=inner_map.begin();iterator1!=inner_map.end();iterator1++)
    {
    cout << iterator1->first <<" | " ;
    cout << iterator1->second <<" class(es)"<<endl;
    }

  }
  cout<<"Number of duplicates: "<< num_of_duplicates<<endl;
  }
