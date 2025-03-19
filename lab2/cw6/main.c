#include <stdio.h>

int main(void) {
    int wys;

    printf("podaj wysokosc ");
    scanf("%d", &wys);
    printf("dziekuje. wysokosc choinki to %d\n", wys);
    

    const int wide = (2 * wys) - 1;
    int i = 0; 

    while (i < wys) { 
        int empty = wide - (2 * i + 1);
        int j = 0;

        while (j < wide) { 
            if (j < (empty / 2) || j >= (wide - (empty / 2))) { 
                printf(" ");
            } else { 
                printf("*"); 
            }
            j++;
        }
        printf("\n");
        i++;
    }
    i = 0;
    int j = 0;

    while (i < wide) { 
        if (i != (wide - 1) / 2) { 
	printf(" "); 
        } else { 
	printf("*");
	}
        i++;
    }

    printf("\n");
	
    while (j < wide) { 
        if ((i < (wide - 1) / 2 - 1) || (i > ((wide - 1) / 2) + 1)) { 
        printf(" ");
	} else { 
	printf("*");
        }
        j++;
    }
    return 0;
}










































