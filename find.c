#include <stdio.h>
#include <string.h>
#include "contact.h"

void findContact(struct Contact *head)
{
    struct Contact *temp;
    char name[50];
    int i;

    printf("Enter name to find: ");

    getchar();

    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    temp = head;

    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
        {
            printf("\nContact found\n");

            printf("Name: %s\n", temp->name);

            for(i = 0; i < temp->phoneCount; i++)
            {
                printf("Phone %d: %s\n", i + 1, temp->phone[i]);
            }

            for(i = 0; i < temp->emailCount; i++)
            {
                printf("Email %d: %s\n", i + 1, temp->email[i]);
            }

            printf("Address: %s\n", temp->address);

            return;
        }

        temp = temp->next;
    }

    printf("Contact not found\n");
}
