#include <stdio.h>

int main()
{
    int n,i;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n],bt[n],pr[n],ct[n],tat[n],wt[n],visited[n],p[n];

    for(i=0;i<n;i++)
    {
        p[i]=i+1;
        visited[i]=0;

        printf("\nProcess P%d\n",p[i]);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);
    }

    int completed=0;
    int currentTime=0;

    while(completed<n)
    {
        int idx=-1;
        int highest=9999;

        for(i=0;i<n;i++)
        {
            if(at[i]<=currentTime && visited[i]==0)
            {
                if(pr[i]<highest)
                {
                    highest=pr[i];
                    idx=i;
                }
            }
        }

        if(idx==-1)
            currentTime++;
        else
        {
            currentTime+=bt[idx];

            ct[idx]=currentTime;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];

            visited[idx]=1;
            completed++;
        }
    }

    float avgWT=0,avgTAT=0;

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i],at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);

        avgWT+=wt[i];
        avgTAT+=tat[i];
    }

    printf("\nAverage Waiting Time=%.2f",avgWT/n);
    printf("\nAverage Turnaround Time=%.2f",avgTAT/n);

    return 0;
}
