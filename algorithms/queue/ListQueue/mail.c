#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#define MIN_PER_HR 60.0

bool newcustomer(double x);   // if new comstom come ?
Item customertime(long when); // set agurement about customer.

int main (void) {
	Queue line;
	Item temp;
	int hours;
	int perhour;
	long cycle, cyclelimit;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	double min_per_cust;  // avarage waiting time
	long line_wait = 0;   // accumulative waiting time
		
	InitializeQueue(&line);
	srand( (unsigned int) time(0)); // rand()
	puts("Case study: Sigmund ");
	puts("Enter the number of simulation hours");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter the avarge number of customer per hour:");
	scanf("%d", &perhour);
	min_per_cust =  MIN_PER_HR / perhour;

	for (cycle = 0; cycle < cyclelimit; cycle++) {
		if (newcustomer(min_per_cust)) {
			if (QueueIsFull(&line))	
				turnaways++;
			else {
				customers++;	
				temp = customertime(cycle);
				EnQueue(&line, temp);
			}
		}	
		if (wait_time <= 0 && !QueueIsEmpty(&line)) {
			DeQueue(&line);
			wait_time = temp.processtime;
			line_wait += cycle - temp.arrive;
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += QueueItemCount(&line);
	}
		if (customertime > 0)
		{
			printf("customers accepted : %ld\n", customers);	
			printf("  customers served : %ld\n", served);
			printf("         turnaways : %ld\n", turnaways);
			printf("average queue size: %.2f\n", (double)sum_line/cyclelimit);
			printf("average wait time: %.2f\n", (double)line_wait/served);
					
		}
		else
			puts("No customers!");
		EmptyTheQueue(&line);
		puts("Bye!");
	
	return 0;
}

/*           x is the average time customers come */
/* if customers comes within 1 minute return true */
bool newcustomer(double x) {
	if (rand()*x / RAND_MAX < 1)
		return true;
	else
		return false;
}

/* set a random time for each customer*/
Item customertime(long when) {
	Item cust;
	cust.processtime = rand()%3 + 1;
	cust.arrive = when;
	return cust;
}

