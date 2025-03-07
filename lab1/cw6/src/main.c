#include <stdio.h> 
#include <math.h> 
#include "is_prime.h" 
#define SCOPE 1000 

int main(void)
{
	for (int i = 1; i < SCOPE; i++) { 
		if (is_prime(i)) { 
			printf("%d\n", i); 
		}
	}
	return 0;
}


	
