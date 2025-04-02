#include <stdio.h>
#include <stdlib.h>
#define N 20

typedef struct Ant {
	int pi, pj;
	int direction;
} Ant;

int rnd(const int min, const int max) {
	return (rand() % (max - min)) + min;
}

void print_board(int** board, const int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", board[i][j]);
        }
        printf("\n");

    }
}

void print_ant(const Ant ant) {
	char directions[] = {'N', 'E', 'S', 'W'};
	printf("Position: (%d, %d), Direction: %c\n", ant.pi, ant.pj, directions[ant.direction]);
}

void init_board(int*** board, const int n) {
	*board = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++) {
		(*board)[i] = (int*)malloc(n * sizeof(int*));

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			(*board)[i][j] = rnd(1,8);
		}
	}	
}

void free_board(int** board, const int n) {
	for (int i = 0; i < n; i++) {
		free((board)[i]);		
		}

	free(board);
}

void ant_move(int** board, const int n, Ant* ant) {
	int state = board[ant->pi][ant->pj];
	
	int new_states[] = {7, 4, 2, 6, 3, 5, 8, 1};
	board[ant->pi][ant->pj] = new_states[state - 1];
	
	int d_pi[] = {-1, 0, 1, 0}; 
	int d_pj[] = {0, 1, 0, -1};

	switch (state) {
        case 1:
            ant->pi += d_pi[ant->direction];
            ant->pj += d_pj[ant->direction];
            break;
        case 2:
            ant->direction = (ant->direction + 1) % 4;
            break;
        case 3:
            ant->direction = (ant->direction + 3) % 4;
            break;
        case 4:
            ant->pi += d_pi[(ant->direction + 1) % 4];
            ant->pj += d_pj[(ant->direction + 1) % 4];
            break;
        case 5:
            ant->pi += d_pi[(ant->direction + 3) % 4];
            ant->pj += d_pj[(ant->direction + 3) % 4];
            break;
        case 6:
            ant->pi -= d_pi[ant->direction];
            ant->pj -= d_pj[ant->direction];
            break;
        case 7:
            ant->direction = (ant->direction + 2) % 4;
            break;
        case 8:
            break;
	}

	if (ant->pi < 0) ant->pi = 0;
	if (ant->pi >= n) ant->pi = n - 1;
	if (ant->pj < 0) ant->pj = 0;
	if (ant->pj >= n) ant->pj = n - 1;

}

void ant_simulation(int** board, const int n, Ant* ant, const int steps) {
	for (int i = 0; i < steps; i++){
		ant_move(board, n, ant);
		print_board(board, n);
		print_ant(*ant);
		printf("\n");
	}

}	


int main(void) {
	int** board;
	int n, steps;
	unsigned seed;
	Ant ant;

	scanf("%d %d %d", &n, &seed, &steps);
	srand(seed);
	init_board(&board, n);
	ant_simulation(board, n, &ant, steps);
	print_board(board, n);
	print_ant(ant);

	free_board(board, n);

	return 0;
}

