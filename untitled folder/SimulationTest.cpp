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
  int n = 0;
  char ID = (char) ('A' + (n++ % 26));
  customer(int at2) :arrivalTime(at2), serviceTime(0), completionTime(0), n(0){}
  customer();
};

struct serviceEvent
{
  int clockTime;   //(whole number) for the event
  int serverNumber;  //
  serviceEvent(int ct2) : clockTime(ct2) {}
  bool operator < (const serviceEvent& a) const
  {return (clockTime > a.clockTime);}
};

int getRandomNumberOfServiceRequests(double averageRequestsPerTimeStep);

int main()
{
  
  ifstream fin;
  fin.open("simulation.txt");
  if (!fin.good()) throw "I/O error";
  
  // read the input values from a text file, one per line, in the order specified above.
  int server, avgAR, maxWait, minST, maxST, clockTime;
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
  
  
  // declare and create and assign arrays and queues to be used in the solution
  queue<customer> qCustomers;  //customer queue
  queue<customer> nextCustomer; //next customer
  priority_queue<serviceEvent> event; //event timing
  customer* servers2;
  int turnAwayCustomers;
  int randomNumber = getRandomNumberOfServiceRequests(avgAR);
  bool* stat = new bool[server];
  for (int i = 0; i < server; i++)
    stat[i] = 0;
  
  // the clock time loop
  for (int time = 0;; time++) // the clock time
  {
    // handle all service events scheduled to complete at this clock time
    while (!event.empty() && event.top().clockTime == time)
    {
      // remove the top service event from the queue
      event.pop();
      
      // determine the server associated with the removed service event
      servers2[server].completionTime = time;
      
      //copy this server's current customer to the served customers queue
      nextCustomer.push(servers2[0]);
      
      //set this server to idle
      servers2[0] = 0;
    }
    
    // handle new arrivals -- can be turned away if wait queue is at maximum length!
    //if time is less than the time at which new arrivals stop
    if (time < maxWait)
    {
      event.top();
      //get the #of of arrivals from the Poisson process (a whole number >= 0) -- see the lecture topic notes!
      int randomNumber = getRandomNumberOfServiceRequests(avgAR);
      // int completionTime = randomNumber + clockTime;
      
      //for each new arrival
      for (int i = 0; i < randomNumber; i ++)
      {
        if (!maxWait)
          //  "turn away the customer" by adding one to the count of turned away customers
          turnAwayCustomers++;
        else
        {
          customer a;
          a.arrivalTime = time;
          qCustomers.push(a);
        }
        
      }
    }
    
    // for idle servers, move customer from wait queue and begin service
    // for (int i = 0; i < )
    //for each server
    // if (server is idle AND the wait queue is not empty)
    if(servers2 && !qCustomers.empty())
    {
      qCustomers.pop();
      server2[qCustomers];
      qCustomers.serviceTime = time;
      
    }
    remove top customer from wait queue
    copy it to the server array
    set the copied customer's service time to the current clock time
    use random number generation to determing the service time interval for the customer
      create a new service event for the server, for the current clock time PLUS the service time interval
        add the service event to the event queue*/
        
        
        // print the summary
        //print the current time
        cout << "Time: " << time << endl;
    //print a heading for the visual prepresentation of the servers and the wait queue
    cout << "-------------------------------------\n";
    cout << "Line    Now Serving     Waiting Queue\n";
    cout << "-----   -----------     -------------\n";
    for (int i = 0; i < 4; i ++)
    {
      
      cout << " " << [i];
      show the ID of the customer being served by that server (blank if idle)
      for server 0 only, show the IDs of customers in the wait queue
        }*/
    cout << "-------------------------------------\n";
    
    
    
    // summarize performance
    /*iterate over the served customers to get the average time between arrival and completion
     and if any, print the average of their "completion time" minus their "arrival time"
     print the rate of customers turned away
     
     // if the user wants to quit, break out of this loop*/
  }
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