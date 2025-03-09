#include <stdio.h>
#include "contact.h"

int main()
{

    Contact contacts[100];
    int count = 0;

    addc(contacts, &count, "kamil", "531-431-331");
    addc(contacts, &count, "pizza", "111-222-333");
    viewc(contacts, count);

    deletec(contacts, &count, "kamil");
    viewc(contacts, count);

    return 0;
}
