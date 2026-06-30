#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f, i, j, k;
    int pageFaults = 0;
    int found, lruIndex;
    int time[10], counter = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        // Check if page is already present
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        // If page not found
        if(found == 0)
        {
            pageFaults++;

            // Find empty frame
            int empty = -1;
            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    empty = j;
                    break;
                }
            }

            if(empty != -1)
            {
                frames[empty] = pages[i];
                counter++;
                time[empty] = counter;
            }
            else
            {
                // Find Least Recently Used page
                lruIndex = 0;
                for(j = 1; j < f; j++)
                {
                    if(time[j] < time[lruIndex])
                        lruIndex = j;
                }

                frames[lruIndex] = pages[i];
                counter++;
                time[lruIndex] = counter;
            }
        }

        // Display frames
        printf("%d\t", pages[i]);
        for(k = 0; k < f; k++)
        {
            if(frames[k] != -1)
                printf("%d ", frames[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
