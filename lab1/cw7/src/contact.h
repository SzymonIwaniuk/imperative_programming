#ifndef CONTACT_H
#define CONTACT_H

#define MAXI_NAME 50
#define MAXI_PHONE 15

typedef struct {

    char name[MAXI_NAME];

    char phone[MAXI_PHONE];
} Contact;


void add_contact(Contact contacts[], int *count, const char *name, const char *phone);

void view_contacts(Contact contacts[], int count);

int delete_contact(Contact contacts[], int *count, const char *name);

#endif        

