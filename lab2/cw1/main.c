# include <stdio.h>

int main() {

    if (__STDC_VERSION__ == 199409L) {
        printf("C95\n");
    } else if (__STDC_VERSION__ == 199901L) {
        printf("C99\n");
    } else if (__STDC_VERSION__ == 201112L) {
        printf("C11\n");
    } else if (__STDC_VERSION__ == 201710L) {
        printf("C17\n");
    } else if (__STDC_VERSION__ == 202000L) {
        printf("C2x\n");
    } else if (__STDC_VERSION__ == 202311L) {
        printf("C23\n");
    }
    return 0;
}

