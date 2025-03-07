#include <stdio.h> 
#include <math.h>
#include <stdbool.h>

bool is_prime(int a)
{ 
	int n = (int) sqrt(a); 

	if (a <= 1) { 
		return false;
	}	
	else if (a == 2 || a == 3) {
		return true;
	} 
	else if (a % 2 == 0 || a % 3 == 0) {
		return false;
	}

	int i = 5;

	while (i <= n) {
		if (a % i == 0) {
			return false;
		}

		i += 2;

		if (a % i == 0) {
			return false;
		}

		i += 4;
	}

	return true; 
}

