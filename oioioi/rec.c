#include <stdio.h>
#include <stdlib.h>
#define N 20

int count = 0;
int result[N];
int found = 0;

int is_safe(const int* queens, int ndx, int col) {
    for (int i = 0; i < ndx; ++i) {
        if (queens[i] == col || abs(queens[i] - col) == abs(i - ndx)) {
            return 0;
        }
    }
    return 1;
}

int place_queens(int* queens, const int n, const int k, const int ndx) {
    if (ndx == n) {
        count++;
        if (count == k) {
            for (int i = 0; i < n; ++i) result[i] = queens[i];
            found = 1;
            return 1;
        }
        return 0;
    }

    for (int col = 0; col < n; ++col) {
        if (is_safe(queens, ndx, col)) {
            queens[ndx] = col;
            if (place_queens(queens, n, k, ndx + 1)) {
                return 1; 
            }
        }
    }
    return 0;
}

void print_board(const int* queens, const int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", queens[i]);
    }
    printf("\n");
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int queens[N] = {0};

    if (place_queens(queens, n, k, 0)) {
        print_board(result, n);
    } else {
        printf("-1\n");
    }

    return EXIT_SUCCESS;
}


