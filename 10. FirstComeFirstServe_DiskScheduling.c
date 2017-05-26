#include<stdio.h>
int main(){
    int a[20], n, i, t=0;

    printf("Enter the head position: ");
    scanf("%d", &a[0]);

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the processes in request order:\n");
    for(i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }

    for(i=0;i<n;i++){
        if(a[i]<a[i+1]){
            t+=(a[i+1]-a[i]);
        }
        else{
            t+=(a[i]-a[i+1]);
        }
    }

    printf("\nProcessing Order: ");
    for(i=0;i<=n;i++){
        printf("\t%d", a[i]);
    }
    printf("\nTotal head movement: %d", t);
}
