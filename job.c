//Source file with definitions to the functions to be used by scheduler
//Written by Yaniel Gonzalez Velez

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "job.h"

void help() {
	printf("List of operation codes:\n");
	printf("\t'h' for help;\n");
	printf("\t'a' for adding a job to the scheduler;\n");
	printf("\t'p' for removing a job from the scheduler;\n");
	printf("\t'u' for searching jobs per user;\n");
	printf("\t'j' for searching jobs per capacity;\n");
	printf("\t'l' for listing all jobs;\n");
	printf("\t'q' for quit.\n");
}

void read(char *job_name, char *user_name, int *num_cpus, int *num_gpus, int *memory, double *time, int *priority) {
	if(job_name != NULL) {
		printf("Enter the name of the job: ");
		scanf("%s", job_name);
	}
	if(user_name != NULL) {
		printf("Enter the name of the user: ");
		scanf("%s", user_name);
	}
	if(num_cpus != NULL) {
		printf("Enter the number of CPUs: ");
		scanf("%d", num_cpus);
	}
	if(num_gpus != NULL) {
		printf("Enter the number of GPUs: ");
		scanf("%d", num_gpus);
	}
	if(memory != NULL) {
		printf("Enter the amount of memory: ");
		scanf("%d", memory);
	}
	if(time != NULL) {
		printf("Enter the amount of time: ");
		scanf("%lf", time);
	}
	if(priority != NULL) {
		printf("Enter the priority: ");
		scanf("%d", priority);
	}
}

struct job * add_job(struct job *scheduler, char *job_name, char *user_name, int num_cpus, int num_gpus, int memory, double time, int priority) {

	//pointers for new job and for the while-loop 
	struct job *new_job, *cur=scheduler, *prev;

	//allocate memory for the new job and fill information given
	new_job = malloc(sizeof(struct job));
	if (new_job == NULL) {
		printf("malloc failed in add_to_list\n");
		return scheduler;
	}
	strcpy(new_job->job_name, job_name);
	strcpy(new_job->user_name, user_name);
	new_job->num_cpus = num_cpus;
	new_job->num_gpus = num_gpus;
	new_job->memory = memory;
	new_job->time = time;
	new_job->priority = priority;
	new_job->next = NULL;

	//insert the new job based on priority 
	//(if new job's priority is already in list, add it to the end of items with same priority)
	for(cur = scheduler, prev = NULL; cur!=NULL && new_job->priority <= cur->priority; prev = cur, cur = cur->next);


	//insert new job between cur and prev
	new_job->next = cur;

	//if new_job is to be placed at the beginning
	if(prev == NULL){
		return new_job;
	}else{
		prev->next = new_job;
		return scheduler;
	}
	
	return scheduler;
}

struct job * pop_job(struct job *scheduler) {

	//declare pointer to the beginning of linked list
	struct job *cur = scheduler;

	//if no jobs in linked list, exit function
	if(cur==NULL){
		return scheduler;
	}

	//print the information of item to be removed
	printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
	printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
	printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
	printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", cur->job_name, cur->user_name, cur->num_cpus, cur->num_gpus, cur->memory, cur->time, cur->priority);
	printf("|----------------------|----------------------|------|------|------|--------|----------|\n");

	//the linked list will now begin from the next item
	scheduler = scheduler->next;

	//free the original first item
	free(cur);
	return scheduler;
}

void list_user(struct job *scheduler, char *user_name) {

	//declare pointer to use in for-loop
	struct job *p;
	//header serves as a flag to make sure header is printed only once per function call
	int header = 0;
	//for-loop that goes through all items in the linked list
	for(p=scheduler; p!=NULL; p=p->next){
		//compare job's user name to user name provided and print if equal 
		if(strcmp(p->user_name, user_name)==0){
			
			if(header==0){
				printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
				printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
				printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
				header++;
			}
			
			printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", p->job_name, p->user_name, p->num_cpus, p->num_gpus, p->memory, p->time, p->priority);
			printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
		}
	}
	
}

void list_jobs(struct job *scheduler, int num_cpus, int num_gpus, int memory, double time) {

	//declare pointer to use in for-loop
	struct job *p;
	//header serves as a flag to make sure header is printed only once per function call
	int header = 0;
	for(p=scheduler; p!=NULL; p=p->next){
		//job's data must match all criteria given
		if((p->num_cpus == num_cpus) && (p->num_gpus == num_gpus) && (p->memory == memory) && (p->time = time)){
			
			if(header==0){
				printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
				printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
				printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
				header++;
			}
			
			printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", p->job_name, p->user_name, p->num_cpus, p->num_gpus, p->memory, p->time, p->priority);
			printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
		}
	}
}

void list_all_jobs(struct job *scheduler) {

	//declare pointer to use in for-loop
	struct job *p=scheduler;
	//if no jobs in linked list, exit function
	if(p==NULL){
		return;
	}
	//print all jobs in the linked list
	printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
	printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
	printf("|----------------------|----------------------|------|------|------|--------|----------|\n");

	for(p=scheduler; p!= NULL; p = p->next){

		printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", p->job_name, p->user_name, p->num_cpus, p->num_gpus, p->memory, p->time, p->priority);	
		printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
	}
	

}

struct job * clear_jobs(struct job *scheduler) {

	//declare pointer for while-loop
	struct job *p;
	//goes through all jobs in the linked list and free their space
	while(scheduler != NULL)
	{
		p = scheduler;
		scheduler = scheduler->next;
		if( p!= NULL)
			free(p);
	}
	return scheduler;
}
