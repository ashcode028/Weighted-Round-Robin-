# Weighted-Round-Robin-
C++ implementation of Weighted Round Robin Scheduling Algorithm
## Overview

Weighted round robin (WRR) is a network scheduler for data flows, but also used to schedule processes.

Weighted round robin is a generalisation of round-robin scheduling. It serves a set of queues or tasks. Whereas round-robin cycles over the queues or tasks and gives one service opportunity per cycle, weighted round robin offers to each a fixed number of opportunities, as specified by the configured weight which serves to influence the portion of capacity received by each queue or task. In computer networks, a service opportunity is the emission of one packet, if the selected queue is non empty.

If all packets have the same size, WRR is the simplest approximation of generalized processor sharing (GPS). Several variations of WRR exist. The main ones are the classical WRR, and the interleaved WRR.

## Principles:
WRR is presented in the following as a network scheduler. It can also be used to schedule tasks in a similar way.

A weighted round-robin network scheduler has {\displaystyle n}n input queues, {\displaystyle q_{1},...,q_{n}}{\displaystyle q_{1},...,q_{n}}. To each queue {\displaystyle q_{i}}q_{i} is associated {\displaystyle w_{i}}w_{i}, a positive integer, called the weight. The WRR scheduler has a cyclic behavior. In each cycle, each queue {\displaystyle q_{i}}q_{i} has {\displaystyle w_{i}}w_{i} emissions opportunities.

The different WRR algorithms differ on the distributions of these opportunities in the cycle.
I have implemented Classical WRR.
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
