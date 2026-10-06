#include <stdio.h>
#include <string.h>

#define MAX 10

struct Parking
{
    char vehicleNo[20];
    char type[10];
    int occupied;
};

struct Parking slot[MAX];

// Function to park a vehicle
void parkVehicle()
{
    int i;

    // Check for duplicate vehicle number
    char vno[20], vtype[10];

    printf("Enter Vehicle Number: ");
    scanf("%s", vno);

    for(i = 0; i < MAX; i++)
    {
        if(slot[i].occupied && strcmp(slot[i].vehicleNo, vno) == 0)
        {
            printf("Vehicle already parked!\n");
            return;
        }
    }

    printf("Enter Vehicle Type (Car/Bike): ");
    scanf("%s", vtype);

    for(i = 0; i < MAX; i++)
    {
        if(slot[i].occupied == 0)
        {
            strcpy(slot[i].vehicleNo, vno);
            strcpy(slot[i].type, vtype);
            slot[i].occupied = 1;

            printf("Vehicle parked at Slot %d\n", i + 1);
            return;
        }
    }

    printf("Parking Lot is Full!\n");
}

// Function to remove a vehicle
void removeVehicle()
{
    char vno[20];
    int i;

    printf("Enter Vehicle Number to Remove: ");
    scanf("%s", vno);

    for(i = 0; i < MAX; i++)
    {
        if(slot[i].occupied && strcmp(slot[i].vehicleNo, vno) == 0)
        {
            slot[i].occupied = 0;
            printf("Vehicle %s removed from Slot %d\n", vno, i + 1);
            return;
        }
    }

    printf("Vehicle Not Found!\n");
}

// Function to display status
void displayStatus()
{
    int i;

    printf("\n----- Parking Lot Status -----\n");
    printf("Slot\tVehicle No\tType\n");

    for(i = 0; i < MAX; i++)
    {
        if(slot[i].occupied)
            printf("%d\t%s\t%s\n", i + 1, slot[i].vehicleNo, slot[i].type);
        else
            printf("%d\tEMPTY\n", i + 1);
    }
}

// Function to count vehicles
void totalVehicles()
{
    int i, count = 0;

    for(i = 0; i < MAX; i++)
    {
        if(slot[i].occupied)
            count++;
    }

    printf("Total Vehicles Parked: %d\n", count);
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- Parking Lot Menu ---\n");
        printf("1. Park Vehicle\n");
        printf("2. Remove Vehicle\n");
        printf("3. Display Status\n");
        printf("4. Total Vehicles\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                parkVehicle();
                break;

            case 2:
                removeVehicle();A
                break;

            case 3:
                displayStatus();
                break;

            case 4:
                totalVehicles();
                break;

            case 5:
                printf("Thank You!\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
