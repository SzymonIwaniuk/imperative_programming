#include <stdio.h>
#include <assert.h>
#include "../src/is_prime.h"

void test_is_prime()
{
    assert(is_prime(2) == 1);  // 2 is prime
    assert(is_prime(3) == 1);  // 3 is prime
    assert(is_prime(5) == 1);  // 5 is prime

    assert(is_prime(1) == 0);  // 1 is not prime
    assert(is_prime(4) == 0);  // 4 is not prime
    assert(is_prime(6) == 0);  // 6 is not prime
 
}

int main(void)
{
    test_is_prime(); 

    printf("All tests passed!\n");

    return 0;
}

