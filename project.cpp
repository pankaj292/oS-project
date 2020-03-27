#include<stdio.h>
#include<conio.h>  
int main()
{
   int n,total=0,bt[30],pid[30],wt[30],tuat[30],pos,temp;  
   float avg_wt,avg_tuat;
   printf("Enter the number of process:");
   scanf("%d",&n);  
   printf("\n estimated Time=\n ");
   for(int i=0;i<n;i++)
   {
       printf("p%d:",i+1);
       scanf("%d",&bt[i]);
       pid[i]=i+1;                            
   }  
   for(int i=0;i<n;i++)
   {
       pos=i;
       for(int j=i+1;j<n;j++)
       {
           if(bt[pos]>bt[j])
               pos=j;
       }  
       temp=bt[i];
       bt[i]=bt[pos];
       bt[pos]=temp;  
       temp=pid[i];
       pid[i]=pid[pos];
       pid[pos]=temp;
   }  
   wt[0]=0;                                   
   for(int i=1;i<n;i++)
   {
       wt[i]=0;
       for(int j=0;j<i;j++)
           wt[i]+=bt[j];  
       total+=wt[i];                         
   }  

   avg_wt=(float)total/n;                     
   total=0;  
   printf("\nProcess\t   estimated Time   \tWaiting Time       \tTurnaround Time");
   for(int i=0;i<n;i++)
   {
       tuat[i]=bt[i]+wt[i];                    // turnaround time find out
       total+=tuat[i];
       printf("\npid%d\t\t  %d\t\t    %d\t\t\t%d",pid[i],bt[i],wt[i],tuat[i]);
   }  
   avg_tuat=(float)total/n;                   // average turnaround time find out
   printf("\n\nAverage Waiting Time= %f ",avg_wt);
   printf("\nAverage Turnaround Time= %f\n ",avg_tuat);
}
