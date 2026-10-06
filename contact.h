#ifndef CONTACT_H
#define CONTACT_H

#define MAX_PHONE 5
#define MAX_EMAIL 3

struct Contact
{
    char name[50];

    char phone[MAX_PHONE][15];
    int phoneCount;

    char email[MAX_EMAIL][50];
    int emailCount;

    char address[100];

    struct Contact *next;
};

void createContact(struct Contact **head);
void printContacts(struct Contact *head);
void findContact(struct Contact *head);
void deleteContact(struct Contact **head);
void editContact(struct Contact *head);
void saveContacts(struct Contact *head);
void loadContacts(struct Contact **head);

#endif
