#include<stdio.h>
int main(){
    int i, j, n, time, remain, flag=0, tq, tat[10], at[10], bt[10], wt[10], rt[10];
    float avgwt=0, avgtat=0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    remain = n;
    for(i=0;i<n;i++){
        printf("Enter arrival time and burst time for Process %d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("\nEnter time quantum: ");
    scanf("%d", &tq);

    for(time=0,i=0;remain!=0;){
        if(rt[i]<=tq && rt[i]>0){
            time+=rt[i];
            flag = 1;
            rt[i] = 0;
        }
        else if(rt[i]>0){
            rt[i] = rt[i] - tq;
            time+=tq;
        }
        if(rt[i]==0 && flag==1){
            remain--;
            wt[i] = time - at[i] - bt[i];
            tat[i] = time - at[i];
            avgwt+=wt[i];
            avgtat+=tat[i];
            flag=0;
        }
        if(i==n-1)
            i=0;
        else if(at[i]<=time)
            i++;
        else
            i=0;
    }

    printf("\nPROCESS\tWAITING TIME\tTURNAROUND TIME\n");
    for(i=0;i<n;i++){
        printf("\n%d\t%d\t\t%d", i+1, wt[i], tat[i]);
    }

    printf("\nAverage waiting time: %f ms", avgwt/n);
    printf("\nAverage turnaround time: %f ms", avgtat/n);
}
