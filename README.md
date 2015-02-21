# Project 1
[Due: Tuesday, March 24, 2015]

Your task is to develop a simulation of a scheduler that assigns processes (or jobs) to a set of available processors or processing nodes. 

Assume that your computing infrastructure has 5 processors available. Processors are identified as P<sub>A</sub>, P<sub>B</sub>, ... Now consider n = 100 processes with different runtime requirements. Specifically, each process has associated with it a burst time (processing time) and a memory requirement. Burst-times are assigned at random (10 * 10<sup>6</sup> cycles — 50 *10<sup>12</sup> cycles). Memory requirements are assigned at random (.25 MB — 8GB). For questions 1 — 3, you may assume that the set of 100 processes is known a-priori; hence, you will have to develop a function that can generate this set with random burst-times and memory requirements (you already did this in HW#2). For this project we will only explore the use of non-preemptive scheduling methods. 

1. Suppose that all 5 processors are identical (i.e., same speed and memory), develop and implement a scheduling algorithm that assigns the set 100 processes to the 5 processors such that the total turnaround time to complete all 100 processes is minimized. Can you find the best assignment? How close does your scheduler approximate the best assignment? 
2. In order to execute a process on a specific processor, sufficient memory has to be available. Assume that the processing nodes are identical in speed but have the following memory availability: P<sub>A</sub>= P<sub>B</sub> = 2 GB, P<sub>C</sub>= P<sub>D</sub>, = 4 GB and P<sub>E</sub>= 8GB. Show how your scheduler will assign the processes to the corresponding processors. 
3. Show how your scheduling algorithm would find the best assignment of processes if the processors are identical, i.e., 4GB memory available but differ in speed. Specifically: P<sub>A</sub>= P<sub>B</sub> = 2 GHz, P<sub>C</sub>= P<sub>D</sub> = 3 GHz. and P<sub>E</sub>= 4 GHz 
4. Last, but not least, develop a scheduling methodology that can deal with the sequential arrival of the 100 processes. That is, the scheduler cannot inspect the entire set of processes but must schedule them one by one in the order that they arrive. You may assume that all processors are identical in speed and memory availability. What is the best turnaround time that you can achieve? 

### Deliverables: 
Write a 5-page report that highlights the problem and describes your scheduling algorithm. You must discuss all the limitations and assumptions. In detail, show how you analyzed the performance (i.e., turnaround time and/or average waiting time) and present your results. 

### Rubrics for this project are: 
1. Problem Analysis — 25pts 
2. Program to test different scheduling strategies — 25pts
3. Design and Analysis of different scheduling algorithms — 25pts 
4. Presentation and discussion of experimental results in the report — 25pts 
