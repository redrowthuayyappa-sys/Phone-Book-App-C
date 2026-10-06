#include <stdio.h>
#include "contact.h"

void printContacts(struct Contact *head)
{
    struct Contact *temp;
    int i;

    if(head == NULL)
    {
        printf("No contacts found\n");
        return;
    }

    temp = head;

    printf("\n----- CONTACT DETAILS -----\n");

    while(temp != NULL)
    {
        printf("\nName: %s\n", temp->name);

        for(i = 0; i < temp->phoneCount; i++)
        {
            printf("Phone %d: %s\n", i + 1, temp->phone[i]);
        }

        for(i = 0; i < temp->emailCount; i++)
        {
            printf("Email %d: %s\n", i + 1, temp->email[i]);
        }

        printf("Address: %s\n", temp->address);

        temp = temp->next;
    }
}
