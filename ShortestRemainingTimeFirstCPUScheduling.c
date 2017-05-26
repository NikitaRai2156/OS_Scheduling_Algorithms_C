#include<stdio.h>
int main(){
    int at[10], bt[10], x[10], i, j, smallest, count=0, time, n;
    double avgwt=0, avgtat=0, end;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        printf("\nEnter arrival time and burst time of Process %d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        x[i] = bt[i];
    }

    bt[9] = 9999;

    for(time=0;count!=n;time++){
        smallest = 9;
        for(i=0;i<n;i++){
            if(at[i]<time && bt[i]<bt[smallest] && bt[i]>0){
                smallest = i;
            }
        }
            bt[smallest]--;
            if(bt[smallest]==0){
                count++;
                end=time + 1;
                avgwt = avgwt + end - at[smallest] - x[smallest];
                avgtat = avgtat + end - at[smallest];
            }
    }

    printf("\nAverage waiting time: %lf", avgwt/n);
    printf("\nAverage turnaround time: %lf", avgtat/n);
}
