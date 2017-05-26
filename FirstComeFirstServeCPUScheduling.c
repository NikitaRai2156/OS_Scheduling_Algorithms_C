#include<stdio.h>
int main(){
    int n, bt[20], wt[20], tat[20], i, j;
    float  avgtat=0, avgwt=0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for:\n");
    for(i=0;i<n;i++){
        printf("Process %d: ", i+1);
        scanf("%d", &bt[i]);
        printf("\n");
    }

    wt[0] = 0; //first process wt = 0

    for(i=1;i<n;i++){
        wt[i] = 0;
        for(j=0;j<i;j++){
            wt[i]+=bt[j];
        }
    }

    printf("\nPROCESS\t\tBURST TIME\t\tWAIT TIME\t\tTURNAROUND TIME");

    for(i=0;i<n;i++){
        tat[i] = bt[i] + wt[i];
        avgtat+=tat[i];
        avgwt+=wt[i];
        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t%d", i+1, bt[i], wt[i], tat[i]);
    }

    avgwt = avgwt/n;
    avgtat = avgtat/n;

    printf("\nAverage Waiting Time: %f ms", avgwt);
    printf("\nAverage Turnaround Time: %f ms", avgtat);
}
