#include <stdio.h>

int main()
{
    int n,m;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter number of resource types: ");
    scanf("%d",&m);

    int alloc[n][m],max[n][m],need[n][m];
    int avail[m];

    printf("\nEnter Allocation Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("\nEnter Maximum Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    printf("\nEnter Available Resources:\n");
    for(int i=0;i<m;i++)
        scanf("%d",&avail[i]);

    // Need Matrix
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            need[i][j]=max[i][j]-alloc[i][j];

    int seq[n];

    printf("\nEnter execution sequence:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&seq[i]);

    for(int k=0;k<n;k++)
    {
        int p=seq[k];

        int possible=1;

        for(int j=0;j<m;j++)
        {
            if(need[p][j]>avail[j])
            {
                possible=0;
                break;
            }
        }

        if(possible)
        {
            printf("P%d executed successfully.\n",p);

            for(int j=0;j<m;j++)
                avail[j]+=alloc[p][j];
        }
        else
        {
            printf("\nDeadlock Detected!\n");
            printf("Process P%d cannot execute.\n",p);
            return 0;
        }
    }

    printf("\nGiven sequence executed successfully.\n");
    printf("No Deadlock.\n");

    return 0;
}
