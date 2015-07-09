#include <iostream>
#include <fstream>
#include <queue>
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
  customer():serviceTime(0), completionTime(0), ID(' '){}
};

struct serviceEvent
{
  int clockTime;   //(whole number) for the event
  int serverNumber;  //
  //serviceEvent(int ct2) : clockTime(ct2) {}
  bool operator < (const serviceEvent& a) const
  {return (clockTime > a.clockTime);}
};

int getRandomNumberOfServiceRequests(double averageRequestsPerTimeStep);

int main()
{
  srand((float)time(0)); rand();
  ifstream fin;
  fin.open("simulation.txt");
  if (!fin.good()) throw "I/O error";
  
  // read the input values from a text file, one per line, in the order specified above.
  int server, maxWait, minST, maxST, clockTime;
  float avgAR;
  fin >> server; fin.ignore(1000,10);
  fin >> avgAR; fin.ignore(1000,10);
  fin >> maxWait; fin.ignore(1000,10);
  fin >> minST; fin.ignore(1000,10);
  fin >> maxST; fin.ignore(1000,10);
  fin >> clockTime; fin.ignore(1000,10);
  
  cout << "Number of servers     : " << server << endl;
  cout << "Customer arrival rate : " << avgAR << " per minute, for 50 minute\n";
  cout << "Maximum queue length  : " << maxWait << endl;
  cout << "Minimum service time  : " << minST << endl;
  cout << "Maximum service time  : " << maxST << endl;
  fin.close();
  
  // declare and create and assign arrays and queues to be used in the solution
  queue<customer> qCustomers;  //customer queue
  queue<customer> afterService; //finished customer
  priority_queue<serviceEvent> event; //event timing
  customer* servers2 = new customer[server];
  bool* status = new bool[server];
  
  string buf;
  int turnAwayCustomers;
  int n = 0;
  
  for (int i = 0; i < server; i++)
    status[i] = false;
  
  // the clock time loop
  for (int time = 0;; time++) // the clock time
  {
    // handle all service events scheduled to complete at this clock time
    while (!event.empty() && event.top().clockTime == time)
    {
      // remove the top service event from the queue
      serviceEvent a = event.top(); event.pop();
      int serverNumber = a.serverNumber;
      servers2[serverNumber].completionTime = time;
      afterService.push(servers2[serverNumber]);
      servers2[serverNumber].ID = ' ';
      status[serverNumber] = false;
    }
    
    // handle new arrivals -- can be turned away if wait queue is at maximum length!
    //if time is less than the time at which new arrivals stop
    if (time < maxWait)
    {
      //get the #of of arrivals from the Poisson process (a whole number >= 0) -- see the lecture topic notes!
      int randomNumber = getRandomNumberOfServiceRequests(avgAR);
      
      //for each new arrival
      for (int i = 0; i < randomNumber; i ++)
      {
        if (qCustomers.size() >= maxWait)
          turnAwayCustomers++;
        else
        {
          customer a;
          a.arrivalTime = time;
          a.ID = (char) ('A' + (n++ % 26));
          qCustomers.push(a);
        }
      }
    }
    
    //for each server
    for (int i = 0; i < server; i++)
    {
      // if (server is idle AND the wait queue is not empty)
      if(!status[i] && !qCustomers.empty())
      {
        customer topCustomer = qCustomers.front();
        qCustomers.pop();
        servers2[i] = topCustomer;
        topCustomer.serviceTime = time;
        status[i] = false;
        
        int random = rand() % 6;
        serviceEvent e;
        e.clockTime = time + random;
        e.serverNumber = i;
        event.push(e);
      }
    }
    
    
    // print the summary
    //print the current time
    cout << "Time: " << time << endl;
    //print a heading for the visual prepresentation of the servers and the wait queue
    cout << "-------------------------------------\n";
    cout << "Line    Now Serving     Waiting Queue\n";
    cout << "-----   -----------     -------------\n";
    for (int i = 0; i < server; i ++)
    {
      cout << setw(3) << i;
      cout << setw(10) << servers2[i].ID;
      if (i == 0)
        cout << setw(15) << servers2[i].ID;
      cout << endl;
    }
    cout << "-------------------------------------\n";
    
    
    
    // summarize performance
    // iterate over the served customers to get the average time between arrival and completion
    // and if any, print the average of their "completion time" minus their "arrival time"
    //print the rate of customers turned away
    float sum = 0;
    float sumTime = 0;
    float sumCount = 0;
    if (time != 0)
    {
      queue<customer> average = afterService;
      sumCount = average.size();
      while (!average.empty())
      {
        sumTime += (average.front().completionTime - average.front().arrivalTime);
        average.pop();
      }
      sum = sumTime / sumCount;
    }
    
    if(sumCount != 0)
      cout << "Average Time: " << sum;
    else
      cout << "Average Time: 0 ";
    if(turnAwayCustomers != 0)
      cout << "\nTurned away per minute: " << (float)turnAwayCustomers / time;
    else
      cout << "Turned away per minute: 0";
    cout << "\nPress ENTER to continue or X-Enter to exit\n";
    getline(cin, buf);
    if (buf == "X" || buf == "x")
      break;
    else
      continue;
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