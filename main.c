#include <stdio.h>
#include "contact.h"

int main()
{
    struct Contact *head = NULL;
    char choice;

    loadContacts(&head);

    while(1)
    {
        printf("\n===== PHONE BOOK APP =====\n");
        printf("C - Create Contact\n");
        printf("P - Print Contacts\n");
        printf("D - Delete Contact\n");
        printf("F - Find Contact\n");
        printf("E - Edit Contact\n");
        printf("S - Save Contacts\n");
        printf("Q - Quit\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if(choice == 'C' || choice == 'c')
        {
            createContact(&head);
        }
        else if(choice == 'P' || choice == 'p')
        {
            printContacts(head);
        }
        else if(choice == 'D' || choice == 'd')
        {
            deleteContact(&head);
        }
        else if(choice == 'F' || choice == 'f')
        {
            findContact(head);
        }
        else if(choice == 'E' || choice == 'e')
        {
            editContact(head);
        }
        else if(choice == 'S' || choice == 's')
        {
            saveContacts(head);
        }
        else if(choice == 'Q' || choice == 'q')
        {
            saveContacts(head);
            printf("Thank you for using Phone Book App.\n");
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
