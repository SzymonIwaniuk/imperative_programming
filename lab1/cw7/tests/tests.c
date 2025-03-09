#include <stdio.h>
#include <string.h>
#include "../src/contact.h"

int main() {
    Contact contacts[100];
    int count = 0;

    addc(contacts, &count, "kamil", "431-431-331");
    if (count == 1 && strcmp(contacts[0].name, "kamil") == 0) {
        printf("addc passed\n");
    } else {
        printf("addc failed\n");
    }

    if (deletec(contacts, &count, "kamil") == 1 && count == 0) {
        printf("deletec passed\n");
    } else {
        printf("deletec failed\n");
    }

    printf("viewc output:\n");
    viewc(contacts, count);

    return 0;
}

