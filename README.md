# Weighted-Round-Robin-
C++ implementation of Weighted Round Robin Scheduling Algorithm
## Overview

Weighted round robin (WRR) is a network scheduler for data flows, but also used to schedule processes.

Weighted round robin is a generalisation of round-robin scheduling. It serves a set of queues or tasks. Whereas round-robin cycles over the queues or tasks and gives one service opportunity per cycle, weighted round robin offers to each a fixed number of opportunities, as specified by the configured weight which serves to influence the portion of capacity received by each queue or task. In computer networks, a service opportunity is the emission of one packet, if the selected queue is non empty.

If all packets have the same size, WRR is the simplest approximation of generalized processor sharing (GPS). Several variations of WRR exist. The main ones are the classical WRR, and the interleaved WRR.

## Principles:
WRR is presented in the following as a network scheduler. It can also be used to schedule tasks in a similar way.

A weighted round-robin network scheduler has n input queues,q<sub>1</sub>,...,q<sub>n</sub>. To each queue q<sub>i</sub> is associated w<sub>i</sub>, a positive integer, called the weight. The WRR scheduler has a cyclic behavior. In each cycle, each queue q<sub>i</sub>  has w<sub>i</sub> emissions opportunities.

The different WRR algorithms differ on the distributions of these opportunities in the cycle.\
I have implemented Classical WRR.
- Psuedo Code
```
Constant and variables: 
    const N             // Nb of queues 
    const weight[1..N]  // weight of each queue
    queues[1..N]        // queues
    i                   // queue index
    c                   // packet counter
    
Instructions:
while true do 
    for i in 1 .. N do
        c := 0
        while (not queue[i].empty) and (c<weight[i]) do
            send(queue[i].head())
            queue[i].dequeue()
            c:= c+1

```
![](https://github.com/ashcode028/Weighted-Round-Robin-/blob/a80b0874ad2d6f4122efbc4a2b4ecb400c19f893/wrr.png)
## Implementation 
- Used queues data structure from STL 
```
 std::deque<char> q[n];
   cout<<"Enter weight of each queue"<<endl;
```
- Used arrays to store weight of each queue
```
cout<<"Enter no of queues"<<endl;
    cin>>n;
    int w[n];
for(int i=0;i<n;i++){
        cin>>w[i];
    } 
```
- Taken input as string separated by semicolon
```
cout<<"Enter values in each queue in each line separated with ';'"<<endl;
    std::string str[n];
    cin>>ws;
    for(int i=0;i<n;i++){
        getline(cin,str[i]);
    }
```
- Parsing the input and adding to each queue
```
 for(int i=0;i<n;i++){
        std::string del=";";
        size_t pos = 0;
        char* token;
        std::string temp;
        while ((pos = str[i].find(del)) != std::string::npos) {
            temp = str[i].substr(0, pos);
            token=const_cast<char*>(temp.c_str());
            //std::cout << token[0] << std::endl;
            q[i].push_back(token[0]);
            check++;
            str[i].erase(0, pos + del.length());
        }
    }
```
#### Sample output
![](https://github.com/ashcode028/Weighted-Round-Robin-/blob/bd2970f9dff99417d0bcfa39d8413b9ea30a6e7e/output.jpg)

