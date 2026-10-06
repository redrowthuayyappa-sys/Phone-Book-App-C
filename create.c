#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

void createContact(struct Contact **head)
{
    struct Contact *new;
    struct Contact *temp;
    char ch;

    new = malloc(sizeof(struct Contact));

    if(new == NULL)
    {
        printf("Memory not allocated\n");
        return;
    }

    printf("\nEnter name: ");

    /* Clear previous newline */
    getchar();

    fgets(new->name, sizeof(new->name), stdin);

    /* Remove newline */
    new->name[strcspn(new->name, "\n")] = '\0';

    /* Check duplicate contact */

    temp = *head;

    while(temp != NULL)
    {
        if(strcmp(temp->name, new->name) == 0)
        {
            printf("Contact already exists\n");
            free(new);
            return;
        }

        temp = temp->next;
    }

    /* Phone number */

    new->phoneCount = 0;

    printf("Enter phone number: ");
    scanf("%s", new->phone[0]);

    new->phoneCount = 1;

    while(new->phoneCount < MAX_PHONE)
    {
        printf("Do you want to add another number (Y/N): ");
        scanf(" %c", &ch);

        if(ch == 'Y' || ch == 'y')
        {
            printf("Enter phone number: ");
            scanf("%s", new->phone[new->phoneCount]);

            new->phoneCount++;
        }
        else
        {
            break;
        }
    }

    /* Email */

    new->emailCount = 0;

    while(new->emailCount < MAX_EMAIL)
    {
        printf("Do you want to add email (Y/N): ");
        scanf(" %c", &ch);

        if(ch == 'Y' || ch == 'y')
        {
            printf("Enter email: ");
            scanf("%s", new->email[new->emailCount]);

            new->emailCount++;
        }
        else
        {
            break;
        }
    }

    /* Address */

    printf("Enter address: ");

    getchar();

    fgets(new->address, sizeof(new->address), stdin);

    new->address[strcspn(new->address, "\n")] = '\0';

    new->next = NULL;

    /* Insert node */

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

    printf("Contact added successfully\n");
}
