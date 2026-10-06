#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

void deleteContact(struct Contact **head)
{
    struct Contact *temp;
    struct Contact *prev;
    char name[50];

    if(*head == NULL)
    {
        printf("No contacts found\n");
        return;
    }

    printf("Enter name to delete: ");

    getchar();

    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    temp = *head;
    prev = NULL;

    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
        {
            if(prev == NULL)
            {
                *head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);

            printf("Contact deleted successfully\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Contact not found\n");
}
