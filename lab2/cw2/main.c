#include <stdio.h>

#define WER_IF 1 

int main() {

#if WER_IF
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
    
#else
    switch (__STDC_VERSION__) {
        case 199409L:
            printf("C95\n");
            break;
        case 199901L:
            printf("C99\n");
            break;
        case 201112L:
            printf("C11\n");
            break;
        case 201710L:
            printf("C17\n");
            break;
        case 202000L:
            printf("C2x\n");
            break;
        case 202311L:
            printf("C23\n");
            break;
    }
#endif
    return 0;
}

