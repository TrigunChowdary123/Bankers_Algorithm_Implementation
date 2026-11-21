#include<stdio.h>
int main(){
    int processes,resources;

    printf("Enter number of processes:");
    scanf("%d",&processes);

    printf("Enter number of resource types:");
    scanf("%d",&resources);

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


return 0;
}