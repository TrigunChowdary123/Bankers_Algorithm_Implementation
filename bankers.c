#include<stdio.h>
int main(){
    int processes,resources;

    printf("Enter number of processes:");
    scanf("%d",&processes);

    printf("Enter number of resource types:");
    scanf("%d",&resources);

    if(processes<=0 || resources<=0){
        printf("Invalid number of processes or resources!\n");
        return 1;
    }

    int available[resources];
    int allocation[processes][resources];
    int maximum[processes][resources];
    int need[processes][resources];

    printf("\nEnter the number of available resources:\n");
    for (int j=0;j<resources;j++){
        scanf("%d",&available[j]);
    }

    printf("\nEnter allocation matrix:\n");
    for (int i=0;i<processes;i++){
        for (int j=0;j<resources;j++){
            scanf("%d",&allocation[i][j]);
        }
    }

    printf("\nEnter maximum matrix:\n");
    for (int i=0;i<processes;i++){
        for (int j=0;j<resources;j++){
            scanf("%d",&maximum[i][j]);
        }
    }

    printf("\nNeed Matrix:\n");
    for (int i=0;i<processes;i++){
        for (int j=0;j<resources;j++){
            if (maximum[i][j]<allocation[i][j]){
                printf("Invalid input!\n");
                return 1;
            }
            need[i][j]=maximum[i][j]-allocation[i][j];
            printf("%d",need[i][j]);
        }
        printf("\n");
    }
// Implementing safety algorithm
int work[resources]; //A temporary copy of available resources
int finish[processes]; //Tracks whether each process has completed
int safesequence[processes];

for (int j=0;j<resources;j++){
    work[j]=available[j];
}

for (int i=0;i<processes;i++){
    finish[i]=0;
}

int count=0;

while(count<processes){
    int found=0;
    for (int i=0;i<processes;i++){
        if(finish[i]==0){
            int canExecute=1;
            for (int j=0;j<resources;j++){
                if (need[i][j]>work[j]){
                    canExecute=0;
                    break;
                }
            }
            if (canExecute)
            {
                for (int j=0;j<resources;j++){
                    work[j]+=allocation[i][j];
                }
                safesequence[count]=i;
                count++;
                finish[i]=1;
                found=1;
            }
        }
    }
    if (found==0){
        break;
    }
}
// Displays Result
    if (count==processes){
        printf("System is in safe state\n");
        printf("Safe sequence:");
        for (int i=0;i<processes;i++){
            printf("%d ", safesequence[i]);
            if (i!=processes-1){
                printf("->");
            }
        }
    }
    else{
        printf("System is in UNSAFE state\n");
    }

return 0;
}