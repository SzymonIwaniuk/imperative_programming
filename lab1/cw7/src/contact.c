#include <stdio.h>
#include <string.h>
#include "contact.h"

void add(Contact contacts[], int *count, const char *name, const char *phone) {
    if (*count >= 100) { /*assuming a maximum of 100 contact */
        return;
    }
    strncpy(contacts[*count].name, name, MAXI_NAME);
    strncpy(contacts[*count].phone, phone, MAXI_PHONE);
    (*count)++;
    printf("contact added successfully.\n");
}

void view(Contact contacts[], int count) {
    if (count == 0) {
        printf("no contacts found.\n");
        return;
    }
    printf("contacts:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

int delete(Contact contacts[], int *count, const char *name) {
    for (int i = 0; i < *count; i++) {
        
	    if (strcmp(contacts[i].name, name) == 0) {

            for (int j = i; j < *count - 1; j++) {
                strcpy(contacts[j].name, contacts[j + 1].name);
                strcpy(contacts[j].phone, contacts[j + 1].phone);
            }
            (*count)--;
            printf("contact deleted successfully\n");
            return 1;
        }
    }
    printf("contact not found.\n");
    return 0; 
}
