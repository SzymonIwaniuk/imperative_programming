#include <stdio.h>
#include <assert.h>
#include "../src/math_utils.h"
#include "../src/is_greater.h"
#include "../src/is_devide.h"

void test_add()
{
	assert(add(2,3) == 5);
	assert(add(-1,1) == 0);
	printf("Test add() passed!\n");
}

void test_substract()
{
	assert(substract(2,3) == -1);
        assert(substract(-1,1) == -2);
        printf("Test substract() passed!\n");
}

void test_multiply()
{
	assert(multiply(2,3) == 6);
        assert(multiply(-1,1) == -1);
        printf("Test multiply() passed!\n");
}

void test_devide()
{
	assert(devide(4,2) == 2);
        assert(devide(-1,1) == -1);
        printf("Test devide() passed!\n");
}

void test_is_greater()
{
	assert(is_greater(4,2) == 1);
}

void test_is_devide()
{ 
	assert(is_devide_bool(4,2) == 1); 
}

int main()
{
	test_add();
	test_substract();
	test_multiply();
	test_devide();
	test_is_greater();
	test_is_devide();

	printf("All test passed!\n");
	return 0;
}
