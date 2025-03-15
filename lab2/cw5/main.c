#include <stdio.h>

int main(void) { 
    const int wys = 6; 
    const int wide = (2 * wys) - 1;
    char a[wide];

    for (int i = 0; i < wys; i++) { 
    int empty = wide - (2 * i + 1);

        for (int j = 0; j < wide; j++) { 
            if (j < (empty / 2) || j >= (wide - (empty / 2))) { 
                printf(" ");
            } else { 
                printf("*"); 
            }
        }
        printf("\n");
    }

    for (int i = 0; i < wide; i++ ) { 
        if (i != (wide - 1) / 2) { 
	printf(" "); 
        } else { 
	printf("*");
	}
    }

    printf("\n");
	
    for  (int i = 0; i < wide; i++) { 
        if ((i < (wide - 1) / 2 - 1) || (i > ((wide - 1) / 2) + 1)) { 
        printf(" ");
	} else { 
	printf("*");
        }
    }
    return 0;
}










































