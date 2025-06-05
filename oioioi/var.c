#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

double sum_var (int number, ...) {
	va_list args;
 	va_start(args, number);
	double sum=0;
	for (int i=0; i<number ; i++){
		double a = va_arg(args, double);
		sum=sum+a;
	}
	va_end(args);
	return sum;
}

double average_var (int number, ...) {
	va_list args;
 	va_start(args, number);
	double sum=0;
	for (int i=0; i<number ; i++){
		double a = va_arg(args, double);
		sum=sum+a;
	}
	va_end(args);
	sum=sum/number;
	return sum;
}

int compare_doubles(const void *a, const void *b) {
    double arg1 = *(const double*)a;
    double arg2 = *(const double*)b;
    
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

double median_var (int number, ...) {
	va_list args;
 	va_start(args, number);
	double *arr=malloc(number*sizeof(double));
	for (int i=0; i<number; i++){
		arr[i]=va_arg(args,double);
	}
	va_end(args);
	qsort(arr, number, sizeof(double), compare_doubles);
    double median;
    if (number % 2 != 0) {
        median = arr[number / 2];
    } else {
        median = (arr[number / 2] + arr[(number / 2) - 1]) / 2.0;
    }
    free(arr);
    return median;
}

double min_var (int number, ...) {
	va_list args;
 	va_start(args, number);
	double mini=va_arg(args, double);
	for (int i=1; i<number ; i++){
		double a = va_arg(args, double);
		if (a<mini){
			mini=a;
		}
	}
	va_end(args);
	return mini;
}	

double max_var (int number, ...) {
	va_list args;
 	va_start(args, number);
	double maksi=va_arg(args, double);
	for (int i=1; i<number ; i++){
		double a = va_arg(args, double);
		if (a>maksi){
			maksi=a;
		}
	}
	va_end(args);
	return maksi;
}

#define MAX_LINE 256
#define MAX_NUMBER 64
#define MAX_TEXTS 64

double sum (const int number, const double* values) {
	if (number==0){
		return 0;
	}
	double suma=0;
	for (int i=0; i<number; i++){
		suma=suma+values[i];
	}
	return suma;
}

double average (const int number, const double* values) {
	if (number==0){
		return 0;
	}
	double suma=0;
	for (int i=0; i<number; i++){
		suma=suma+values[i];
	}
	suma=suma/number;
	return suma;

}

double median (const int number, double* values) {
	if (number==0){
		return 0;
	}
	double *arr=malloc(number*sizeof(double));
	for (int i=0; i<number; i++){
		arr[i]=values[i];
	}
	qsort(arr, number, sizeof(double), compare_doubles);
    double median;
    if (number % 2 != 0) {
        median = arr[number / 2];
    } else {
        median = (arr[number / 2] + arr[(number / 2) - 1]) / 2.0;
    }
    free(arr);
    return median;
}

double min (const int number, const double* values) {
	if (number==0){
		return 0;
	}
	double mini=values[0];
	for (int i=1; i<number ; i++){
		double a = values[i];
		if (a<mini){
			mini=a;
		}
	}
	return mini;
}

double max (const int number, const double* values) {
	if (number==0){
		return 0;
	}
	double maksi=values[0];
	for (int i=1; i<number ; i++){
		double a = values[i];
		if (a>maksi){
			maksi=a;
		}
	}
	return maksi;
}

int read_from_line(char* c_buf, double *values, char** texts, int* text_counter) {
    int value_counter = 0;
    *text_counter = 0;

    char *token = strtok(c_buf, " \t\n");

    while (token != NULL) {
        char *p = token;
        char *endptr;
        double val = strtod(p, &endptr);

        if (endptr != p) {
            values[value_counter++] = val;

            if (*endptr != '\0') {

                strncpy(texts[(*text_counter)++], endptr, 99);
                texts[*text_counter - 1][99] = '\0'; 
            }
        } else {

            strncpy(texts[(*text_counter)++], token, 99);
            texts[*text_counter - 1][99] = '\0'; 
        }

        token = strtok(NULL, " \t\n");
    }

    return value_counter;
}

int read_int(void) {
	char c_buf[MAX_LINE];
	fgets(c_buf, MAX_LINE, stdin);
	return (int)strtol(c_buf, NULL, 10);
}

int main(void) {
	int number;
	double v1, v2, v3, v4, v5;

	char c_buf[MAX_LINE];
	double values[MAX_NUMBER];
	char* texts[MAX_TEXTS];
	int text_counter;

    for (int i = 0; i < MAX_TEXTS; i++) {
        texts[i] = malloc(100 * sizeof(char));
        if (texts[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
    
    
	const int to_do = read_int();

	switch (to_do) {
		case 1:
			number = 3;
			scanf("%lf%lf%lf", &v1, &v2, &v3);
			printf("%.2f %.2f %.2f %.2f %.2f\n",
					sum_var(number, v1, v2, v3),
					average_var(number, v1, v2, v3),
					median_var(number, v1, v2, v3),
					min_var(number, v1, v2, v3),
					max_var(number, v1, v2, v3));

			number = 5;
			scanf("%lf%lf%lf%lf%lf", &v1, &v2, &v3, &v4, &v5);
			printf("%.2f %.2f %.2f %.2f %.2f\n",
					sum_var(number, v1, v2, v3, v4, v5),
					average_var(number, v1, v2, v3, v4, v5),
					median_var(number, v1, v2, v3, v4, v5),
					min_var(number, v1, v2, v3, v4, v5),
					max_var(number, v1, v2, v3, v4, v5));
			break;
		case 2:
			fgets(c_buf, MAX_LINE, stdin);
			number = read_from_line(c_buf, values, texts, &text_counter);
			printf("%.2f %.2f %.2f %.2f %.2f\n",
					sum(number, values),
					average(number, values),
					median(number, values),
					min(number, values),
					max(number, values));

			for (int k = 0; k < text_counter; k++) {
				printf("%s\n", texts[k]);
			}
			break;
		default:
			printf("Nothing to do for n = %d\n", to_do);
			break;
	}

	return EXIT_SUCCESS;
}