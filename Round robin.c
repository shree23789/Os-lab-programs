#include <stdio.h>

int main()
{
    int n, tq, i;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n], p[n];
    int completed=0, currentTime=0;

    for(i=0;i<n;i++)
    {
        p[i]=i+1;

        printf("\nProcess P%d\n",p[i]);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        rt[i]=bt[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d",&tq);

    while(completed<n)
    {
        int done=1;

        for(i=0;i<n;i++)
        {
            if(rt[i]>0 && at[i]<=currentTime)
            {
                done=0;

                if(rt[i]>tq)
                {
                    currentTime+=tq;
                    rt[i]-=tq;
                }
                else
                {
                    currentTime+=rt[i];
                    rt[i]=0;

                    ct[i]=currentTime;
                    tat[i]=ct[i]-at[i];
                    wt[i]=tat[i]-bt[i];

                    completed++;
                }
            }
        }

        if(done)
            currentTime++;
    }

    float avgWT=0,avgTAT=0;

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i],at[i],bt[i],ct[i],tat[i],wt[i]);

        avgWT+=wt[i];
        avgTAT+=tat[i];
    }

    printf("\nAverage Waiting Time=%.2f",avgWT/n);
    printf("\nAverage Turnaround Time=%.2f",avgTAT/n);

    return 0;
}
