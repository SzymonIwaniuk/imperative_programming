#include <stdio.h>
#include "utils.h"
#include "math_utils.h"
#include "is_greater.h"
#include "is_devide.h"

int main(void)
{
	print_message();
	printf("2 + 3 = %d\n",add(2,3));
	printf("2 - 3 = %d\n",substract(2,3));
	printf("2 * 3 = %d\n",multiply(2,3));
	printf("2 / 3 = %6f\n",devide(2,3));
	
	if (is_greater(2,3)) {
		printf("True\n");
	} else {
		printf("False\n"); 
	} 
	
	is_devide(2,3);

	return 0; 

}


