#include "is_devide.h" 
#include <stdio.h>

bool is_devide_bool(int a, int b)
{ 
	return a % b == 0; 
}

void is_devide(int a, int b)
{ 
	if (is_devide_bool(a, b)) { 
		printf("%d is devided by %d\n", a, b);
	} else {
		printf("%d is not devided by %d\n", a, b);
	}
} 

		
