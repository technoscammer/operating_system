#include <stdio.h>
#include <conio.h>
typedef struct
{
int process_id;
float arrival_time, waiting_time, burst_time, turnaround_time, schedule_table;
bool isComplete;
}process;


void project(int i, process p[])
{
printf("Process id: ");
scanf("%d", &p[i].process_id);
printf("Arrival Time: ");
scanf("%f", &p[i].arrival_time);
printf("Burst Time: ");
scanf("%f", &p[i].burst_time);
p[i].isComplete = false;
}


void sort(process p[], int i, int start)
{
int k = 0, j;
process temp;
for (k = start; k<i; k++)
{
for (j = k+1; j<i; j++)
{
if(p[k].burst_time < p[j].burst_time)
continue;
else
{
temp = p[k];
p[k] = p[j];
p[j] = temp;
}
}
}
}
int main()
{
int n, i, k = 0, j = 0;
float avgwaiting_time = 0.0, avgturnaround_time = 0.0, tst = 0.0;
printf("Enter the number of processes: ");
scanf("%d",&n);
process p[n];
for (i = 0; i<n; i++)
{
printf("\nEnter process number %d's details: ",i);
project(i,p);
}
for (i = 0; i<n; i++)
{
if (p[i].isComplete == true)
continue;
else
{
k = i;
while (p[i].arrival_time<=tst && i<n)
i++;
sort (p,i,k);
i = k;
if(p[i].arrival_time<=tst)
p[i].schedule_table = tst;
else
p[i].schedule_table = p[i].arrival_time;
p[i].schedule_table = tst;
p[i].isComplete = true;
tst += p[i].burst_time;
p[i].waiting_time = p[i].schedule_table - p[i].arrival_time;
p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
avgwaiting_time += p[i].waiting_time;
avgturnaround_time += p[i].turnaround_time;
}
}
avgwaiting_time /= n;
avgturnaround_time /= n;
printf("Process Schedule Table: \n");
printf("\tProcess ID \t Arrival Time \t Burst Time \t Wait Time \t Turnaround Time\n");
for (i = 0; i<n; i++)
printf("\t%d\t\t%f\t%f\t%f\t%f\n", p[i].process_id,p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
printf("\nAverage wait time: %f", avgwaiting_time);
printf("\nAverage turnaround time: %f\n", avgturnaround_time);
}
