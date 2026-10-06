#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

void saveContacts(struct Contact *head)
{
    FILE *fp;
    struct Contact *temp;

    fp = fopen("phonebook.dat", "wb");

    if(fp == NULL)
    {
        printf("File cannot be opened\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        fwrite(temp, sizeof(struct Contact), 1, fp);
        temp = temp->next;
    }

    fclose(fp);

    printf("Contacts saved successfully\n");
}

void loadContacts(struct Contact **head)
{
    FILE *fp;
    struct Contact *new;
    struct Contact *temp;

    fp = fopen("phonebook.dat", "rb");

    if(fp == NULL)
    {
        return;
    }

    while(1)
    {
        new = malloc(sizeof(struct Contact));

        if(new == NULL)
        {
            fclose(fp);
            return;
        }

        if(fread(new, sizeof(struct Contact), 1, fp) != 1)
        {
            free(new);
            break;
        }

        new->next = NULL;

        if(*head == NULL)
        {
            *head = new;
        }
        else
        {
            temp = *head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = new;
        }
    }

    fclose(fp);
}
