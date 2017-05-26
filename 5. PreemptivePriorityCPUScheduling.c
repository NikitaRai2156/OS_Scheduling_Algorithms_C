#include<stdio.h>
int main(){
    int at[10], bt[10], x[10], pr[10], i, j, smallest, count=0, time, n;
    double avgwt=0, avgtat=0, end;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        printf("\nEnter priority, arrival time and burst time of Process %d: ", i+1);
        scanf("%d %d %d", &pr[i], &at[i], &bt[i]);
        x[i] = bt[i];
    }
    //count = n;
    pr[9] = 11;

    for(time=0;count!=n;time++){
        smallest = 9;
        for(i=0;i<n;i++){
            if(at[i]<=time && pr[i]<pr[smallest] && bt[i]>0){
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
