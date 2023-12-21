# Job-Scheduler
README FILE

JOB SCHEDULER

AUTHOR:
Yaniel Gonzalez

OVERVIEW 

This C project implements a Job Scheduler using a singly linked list to manage and organize jobs. 
The program stores job information in a formatted table using a FIFO system with dynamically 
allocated linked lists. The functionality includes adding new jobs based on priority, removing the 
top job, searching for a job based on user or capacity, listing all jobs, and clearing the entire 
list.

FEATURES 

-Job Scheduler: Utilizes a singly linked list to manage jobs with a FIFO system.

-Dynamic Allocation: Dynamically allocates memory for jobs to allow flexibility in the number of entries.

-Priority-Based Addition: Adds new jobs to the list based on the priority provided.

-Job Removal: Removes the top job from the list.

-Search Functionality: Provides the ability to search for a job based on user or capacity.

-Listing Jobs: Lists all jobs currently in the scheduler.

-Clearing the List: Clears all jobs from the scheduler.

DEPENDENCIES

This project relies on a C compiler that supports C99.

USAGE

Compilation:

To compile the program, use the following command:

    gcc -Wall -std=c99  job.c main.c

Input:

The program includes a user interface to execute its functions.

-Enter 'h' to read the list of commands to that the program includes

-Enter 'a' for adding a job to the scheduler

-Enter 'p' for removing a job from the scheduler

-Enter 'u' for searching jobs per user

-Enter 'j' for searching jobs per capacity

-Enter 'l' for listing all jobs

-Enter 'q' to quit the program
    

CODE STRUCTURE

-'main.cpp': Contains the user inteface for navigating the program.

-'job.c' and 'job.h': Contains the singly linked list structure and the main 
 functions for the program. 


ACKNOLEDGEMENTS

The project was inspired by the need for an efficient and organized way to schedule 
and manage jobs using a FIFO system.

