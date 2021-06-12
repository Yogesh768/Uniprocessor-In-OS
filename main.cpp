#include<stdio.h>
int n;
struct process
{

int p_no;

int artime,butime,compt,waittime,taroundtime,p;

int flag;
 }
 p_list[100];
 void Sorting()
 {
struct process p;

int i, j;

for(i=0;i<n-1;i++)

{

for(j=i+1;j<n;j++)

{

if(p_list[i].artime > p_list[j].artime)

{

p = p_list[i];

p_list[i] = p_list[j];

p_list[j] = p;

}

}

}
 }
 int main()
 {

int i,t=0,b_t=0,peak;

int a[10];

float waittime = 0, taroundtime = 0, avgwt=0, avgtaroundtime=0;

printf("enter the no. of processes: ");

scanf("%d",&n);

for(i = 0; i < n; i++)

{

p_list[i].p_no = i+1;

printf("\nEnter Details For P%d process:-\n", p_list[i].p_no);
printf("Enter Arrival Time: ");
scanf("%d", &p_list[i].artime );
printf("Enter Burst Time: ");
scanf("%d", &p_list[i].butime);
p_list[i].flag = 0;
b_t = b_t + p_list[i].butime;
}
Sorting();
for(int i=0;i<n;i++)
{
a[i]=p_list[i].butime;
}
p_list[9].butime = 9999;
for(t = p_list[0].artime; t <= b_t+1;)
{
peak = 9;
for(i=0;i<n;i++)
{
if(p_list[i].artime <= t && p_list[i].butime < p_list[peak].butime && p_list[i].flag != 1)
{
peak = i;
}
if(p_list[peak].butime==0 && p_list[i].flag != 1)
{
p_list[i].flag = 1;

p_list[peak].compt=t;p_list[peak].butime=9999;
printf("P%d completes in %d\n",p_list[i].p_no,p_list[peak].compt);
}
}
t++;
(p_list[peak].butime)--;
}
for(i=0;i<n;i++)
{
p_list[i].taroundtime=(p_list[i].compt)-(p_list[i].artime);
avgtaroundtime=avgtaroundtime+p_list[i].taroundtime;
p_list[i].waittime=((p_list[i].taroundtime)-a[i]);
avgwt=avgwt+p_list[i].waittime;
}
printf("PNO\tAT\tCT\tTA\tWTt\n");
for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\n",p_list[i].p_no,p_list[i].artime,p_list[i].compt,p_list[i].taroundtime
,p_list[i].waittime);
 }
printf("Average Turn around Time: %f\t\n\n",avgtaroundtime);
printf("Average Waiting Time :\t %f\t\n",avgwt);
}