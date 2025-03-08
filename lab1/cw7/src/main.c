#include <stdio.h>
#include "contact.h"

int main()
{

    Contact contacts[100];
    int count = 0;

    add(contacts, &count, "kamil", "531-431-331");
    add(contacts, &count, "pizza", "111-222-333");
    view(contacts, count);

    delete(contacts, &count, "kamil");
    view(contacts, count);

    return 0;
}
