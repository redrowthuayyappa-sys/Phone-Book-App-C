#include <stdio.h>
#include <string.h>
#include "contact.h"

void editContact(struct Contact *head)
{
    struct Contact *temp;
    char name[50];
    char newName[50];
    char newAddress[100];
    int choice;
    int i;

    printf("Enter name to edit: ");

    getchar();

    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    temp = head;

    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
        {
            printf("\n1. Edit name\n");
            printf("2. Edit phone number\n");
            printf("3. Edit email\n");
            printf("4. Edit address\n");

            printf("Enter your choice: ");
            scanf("%d", &choice);

            if(choice == 1)
            {
                printf("Enter new name: ");

                getchar();

                fgets(newName, sizeof(newName), stdin);

                newName[strcspn(newName, "\n")] = '\0';

                strcpy(temp->name, newName);
            }
            else if(choice == 2)
            {
                printf("Enter phone number position: ");
                scanf("%d", &i);

                if(i >= 1 && i <= temp->phoneCount)
                {
                    printf("Enter new phone number: ");
                    scanf("%s", temp->phone[i - 1]);
                }
                else
                {
                    printf("Invalid phone number position\n");
                    return;
                }
            }
            else if(choice == 3)
            {
                printf("Enter email position: ");
                scanf("%d", &i);

                if(i >= 1 && i <= temp->emailCount)
                {
                    printf("Enter new email: ");
                    scanf("%s", temp->email[i - 1]);
                }
                else
                {
                    printf("Invalid email position\n");
                    return;
                }
            }
            else if(choice == 4)
            {
                printf("Enter new address: ");

                getchar();

                fgets(newAddress, sizeof(newAddress), stdin);

                newAddress[strcspn(newAddress, "\n")] = '\0';

                strcpy(temp->address, newAddress);
            }
            else
            {
                printf("Invalid choice\n");
                return;
            }

            printf("Contact updated successfully\n");
            return;
        }

        temp = temp->next;
    }

    printf("Contact not found\n");
}
