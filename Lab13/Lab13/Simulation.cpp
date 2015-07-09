//Aysin ORuz
//Lab 13 Simulation.cpp
//Terminal, Xcode, Jnote

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <cmath>
#include <ctime>
#include <cstdlib>

//struct definition
struct customer
{
  int arrivalTime;
  int serviceTime;
  int completionTime;
  char ID;
};

struct serviceEvent
{
  int clockTime;   //(whole number) for the event
  int serverNumber;
  bool operator < (const serviceEvent& a) const
  {return (clockTime > a.clockTime);}
};

int getRandomNumberOfServiceRequests(double );

int main()
{
  cout << "\n\nLab 13, Simulation.cpp\n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: In this lab I will apply parts of the STL to the solution of a computer simulation problem..";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  srand(time(0)); rand();
  ifstream fin;
  fin.open("simulation.txt");
  if (!fin.good()) throw "I/O error";
  
  // read the input values from a text file, one per line, in the order specified above.
  int server, maxWait, minST, maxST, clockTime2;
  float avgAR;
  fin >> server; fin.ignore(1000,10);
  fin >> avgAR; fin.ignore(1000,10);
  fin >> maxWait; fin.ignore(1000,10);
  fin >> minST; fin.ignore(1000,10);
  fin >> maxST; fin.ignore(1000,10);
  fin >> clockTime2; fin.ignore(1000,10);
  fin.close();
  
  cout << "\n\nNumber of servers     : " << server << endl;
  cout << "Customer arrival rate : " << avgAR << " per minute, for 50 minute\n";
  cout << "Maximum queue length  : " << maxWait << endl;
  cout << "Minimum service time  : " << minST << endl;
  cout << "Maximum service time  : " << maxST << endl;
  
  // declare and create and assign arrays and queues to be used in the solution
  queue<customer> qCustomers;  //customer queue
  vector<customer> afterService; //finished customer
  priority_queue<serviceEvent> event; //event timing
  customer* servers2 = new customer[server];
  bool* status = new bool[server];
  
  string buf;
  int turnAwayCustomers;
  int n = 0;
  
  for (int i = 0; i < server; i++)
    status[i] = true;
  
  // the clock time loop
  for (int time = 0;; time++) // the clock time
  {
    // handle all service events scheduled to complete at this clock time
    while (!event.empty() && event.top().clockTime == time)
    {
      // remove the top service event from the queue
      serviceEvent a = event.top();
      event.pop();
      servers2[a.serverNumber].completionTime = time;
      afterService.push_back(servers2[a.serverNumber]);
      status[a.serverNumber] = true;
    }
    
    // handle new arrivals -- can be turned away if wait queue is at maximum length!
    if (time < clockTime2)
    {
      int randomNumber = getRandomNumberOfServiceRequests(avgAR);
      for (int i = 0; i < randomNumber; i++)
      {
        if (qCustomers.size() >= maxWait)
          turnAwayCustomers++;
        else
        {
          customer a;
          a.arrivalTime = time;
          a.ID = (char) ('A' + (n++ % 26));
          qCustomers.push(a);
        } } }
    
    //for each server
    for (int i = 0; i < server; i++)
    {
      if(status[i] && !qCustomers.empty())
      {
        customer topCustomer = qCustomers.front();
        qCustomers.pop();
        servers2[i] = topCustomer;
        servers2[i].serviceTime = time;
        status[i] = false;
        
        int random = minST + rand() % (maxST - minST + 1);
        serviceEvent e;
        e.clockTime = time + random;
        e.serverNumber = i;
        event.push(e);
      }
    }
    
    // print the summary
    cout << "\nTime: " << time << endl;
    cout << "-------------------------------------\n";
    cout << "Line    Now Serving     Waiting Queue\n";
    cout << "-----   -----------     -------------\n";
    for(int i = 0; i < server; i++)
    {
      cout << "  " << i << "     ";
      
      if(status[i] == false)
        cout << "      " << servers2[i].ID << "           ";
      else
        cout << "            ";
      
      if(i == 0)
        for (queue<customer> qC = qCustomers; !qC.empty(); qC.pop())
          cout << qC.front().ID;
      
      cout << endl;
    }
    cout << "-------------------------------------\n";
    
    
    
    // summarize performance
    float average = 0;
    float gonePerMin = 0;
    
    for(int i = 0; i < afterService.size(); i++)
      average += afterService[i].completionTime - afterService[i].serviceTime;
    
    if(average != 0)
    {
      cout.setf(ios::fixed|ios::showpoint);
      average = average / afterService.size();
      cout << "Average Time to Serve Customer: "<< setprecision(2) << average << endl;
    }
    if (average == 0)
      cout << "Average Time to Serve Customer: "<<  average << endl;
    
    if(time != 0)
    {
      if(time >= clockTime2)
        cout<< "Customers Turned Away Per Minute: " << gonePerMin << endl;
      else
      {
        gonePerMin = ((double)turnAwayCustomers) / time;
        cout << "Customers Turned Away Per Minute: " << gonePerMin << endl;
      }
    }
    
    // if the user wants to quit, break out of this loop
    cout << "\nPress ENTER to continue or X-ENTER to quit." << endl;
    getline(cin, buf);
    if (buf == "X" || buf == "x")
      break;
  }
  delete [] servers2;
  delete [] status;
}


int getRandomNumberOfServiceRequests(double averageRequestsPerTimeStep)
{
  int requests = 0;
  double probOfnRequests = exp(-averageRequestsPerTimeStep);
  for (double randomValue = (double)rand() / RAND_MAX;
       (randomValue -= probOfnRequests) > 0.0;
       probOfnRequests *= averageRequestsPerTimeStep / (double)++requests);
  return requests;
}