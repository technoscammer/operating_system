#include <stdio.h>
#include <conio.h>
typedef struct
{
int process_id;
float arr_tim, wt_tim, brst_tim, tnarnd_tim, sch_tbl;
bool isComplete;
}process;


void project(int i, process p[])
{
printf("PROCESS ID: ");
scanf("%d", &p[i].process_id);
printf("ARRIVAL TIME: ");
scanf("%f", &p[i].arr_tim);
printf("BURST TIME: ");
scanf("%f", &p[i].brst_tim);
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
if(p[k].brst_tim < p[j].brst_tim)
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
float avgwt_tim = 0.0, avgtnarnd_tim = 0.0, tst = 0.0;
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
while (p[i].arr_tim<=tst && i<n)
i++;
sort (p,i,k);
i = k;
if(p[i].arr_tim<=tst)
p[i].sch_tbl = tst;
else
p[i].sch_tbl = p[i].arr_tim;
p[i].sch_tbl = tst;
p[i].isComplete = true;
tst += p[i].brst_tim;
p[i].wt_tim = p[i].sch_tbl - p[i].arr_tim;
p[i].tnarnd_tim = p[i].brst_tim + p[i].wt_tim;
avgwt_tim += p[i].wt_tim;
avgtnarnd_tim += p[i].tnarnd_tim;
}
}
avgwt_tim /= n;
avgtnarnd_tim /= n;
printf("PROCESS SCHEDULE TABLE: \n");
printf("\tPROCESS ID \t ARRIVAL TIME \t BURST TIME \t WAIT TIME \t TURNAROUND TIME\n");
for (i = 0; i<n; i++)
printf("\t%d\t\t%f\t%f\t%f\t%f\n", p[i].process_id,p[i].arr_tim, p[i].brst_tim, p[i].wt_tim, p[i].tnarnd_tim);
printf("\nAVERAGE WAIT TIME: %f", avgwt_tim);
printf("\nAVERAGE TURNAROUND TIME: %f\n", avgtnarnd_tim);
}
