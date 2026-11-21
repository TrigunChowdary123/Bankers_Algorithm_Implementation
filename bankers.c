#include<stdio.h>
int safetyalgorithm(int processes,int resources,
                    int available[],
                    int allocation[processes][resources],
                    int need[processes][resources],
                    int safesequence[]){
// Implementing safety algorithm
int work[resources]; //A temporary copy of available resources
int finish[processes]; //Tracks whether each process has completed

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
    if(count==processes){
        return 1;
    }
    return 0;
}
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
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
int safesequence[processes];
int safe=safetyalgorithm(processes,resources,
    available,
    allocation,
    need,
    safesequence
    );

if(!safe){
    printf("Initial system is unsafe!\n");
    return 1;
}
printf("Initial system is safe\n");

// Resource request algorithm
 int process_number;
 int request[resources];

printf("\nEnter the process making reuqest (0 to %d):",processes-1);
scanf("%d",&process_number);
if(process_number<0 || process_number>=processes){
    printf("Invalid processnumber!\n");
    return 1;
}
printf("Enter the requested resources:\n");
for (int j=0;j<resources;j++){
    scanf("%d",&request[j]);

    if(request[j]<0){
        printf("Invalid resource request!\n");
        return 1;
    }
}
int valid=1;

// Check whether request exceeds need
for(int j=0;j<resources;j++){
    if(request[j]>need[process_number][j]){
        printf("Request exceeds maximum need\n");
        valid=0;
        break;
    }
}

// Check whether the resources are vailable


if(valid){
    for (int j=0;j<resources;j++){
        if(request[j]>available[j]){
            printf("Resources are not available. Process must wait");
            valid=0;
            break;
        }
    }
}

//Temporarily allocate resources
if(valid){
    for (int j=0;j<resources;j++){
        available[j]-=request[j];
        allocation[process_number][j]+=request[j];
        need[process_number][j]-=request[j];
    }
    printf("Resources are temporarily allocated\n");
//Checking safety again after allocation
int newsafesequence[processes];

int newsafe=safetyalgorithm(processes,resources,available,
allocation,need,newsafesequence);

if(!newsafe){
    for(int j=0;j<resources;j++){
        available[j]+=request[j];
        allocation[process_number][j]-=request[j];
        need[process_number][j]+=request[j];
    }
printf("Request denied! system would become unsafe\n");
printf("Previous allocation restored");
}


if(newsafe){
    printf("Request granted!\n");
    printf("System is in safe state.\n");
    printf("New safe seqeunce: ");
    for (int i=0;i<processes;i++){
        printf("P%d",newsafesequence[i]);
        if(i!=processes-1){
            printf("->");
        }
    }
    printf("\n");
}
}

return 0;
}
