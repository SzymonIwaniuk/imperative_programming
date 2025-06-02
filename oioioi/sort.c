#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAME_MAX  20
#define FOOD_MAX  30
#define RECORD_MAX 64

typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	char name[NAME_MAX];
	float price;
	int amount;
	Date exp_date;
} Food;

typedef int (*CompareFp)(const void *, const void *);


int cmp_date(const void *d1, const void *d2) {
	const Date *a = d1;
	const Date *b = d2;

	if (a->year != b->year)
		return a->year - b->year;
	if (a->month != b->month)
		return a->month - b->month;
	return a->day - b->day;
}

int cmp(const void *a, const void *b) {
	const Food *fa = a;
	const Food *fb = b;

	int name_cmp = strcmp(fa->name, fb->name);
	if (name_cmp != 0) return name_cmp;

	if (fa->price != fb->price)
		return (fa->price > fb->price) - (fa->price < fb->price);

	return cmp_date(&fa->exp_date, &fb->exp_date);
}


void* bsearch2(const void *key, const void *base, const size_t n_items,
	const size_t size, const CompareFp compare, char *result) {
	size_t low = 0, high = n_items;
	while (low < high) {
		size_t mid = (low + high) / 2;
		void *mid_elem = (char *)base + mid * size;
		int cmp_res = compare(key, mid_elem);
		if (cmp_res == 0) {
			*result = 1;
			return mid_elem;
		}
		if (cmp_res < 0)
			high = mid;
		else
			low = mid + 1;
	}
	*result = 0;
	return (char *)base + low * size;
}


Food* add_record(Food *tab, int *np, const CompareFp compare, const Food *new) {
	char found;
	Food *pos = bsearch2(new, tab, *np, sizeof(Food), compare, &found);
	if (found) {
		pos->amount += new->amount;
		return pos;
	}

	memmove(pos + 1, pos, (char *)(tab + *np) - (char *)pos);
	*pos = *new;
	(*np)++;
	return pos;
}


int read_goods(Food *tab, FILE *stream, const int sorted) {
	int n;
	fscanf(stream, "%d", &n);
	int count = 0;
	for (int i = 0; i < n; ++i) {
		Food f;
		fscanf(stream, "%s %f %d %d.%d.%d", f.name, &f.price, &f.amount,
		       &f.exp_date.day, &f.exp_date.month, &f.exp_date.year);
		if (sorted)
			add_record(tab, &count, cmp, &f);
		else
			tab[count++] = f;
	}
	return count;
}


float value(Food *food_tab, const size_t n, const Date curr_date, const int days) {
	struct tm tm_date = {0};
	tm_date.tm_mday = curr_date.day;
	tm_date.tm_mon = curr_date.month - 1;
	tm_date.tm_year = curr_date.year - 1900;

	time_t base_time = mktime(&tm_date);
	base_time += (time_t)days * 24 * 3600;

	struct tm *target = localtime(&base_time);
	Date target_date = {
		.day = target->tm_mday,
		.month = target->tm_mon + 1,
		.year = target->tm_year + 1900
	};

	float total = 0.0;
	for (size_t i = 0; i < n; ++i) {
		if (cmp_date(&food_tab[i].exp_date, &target_date) == 0) {
			total += food_tab[i].price * food_tab[i].amount;
		}
	}
	return total;
}


int read_int() {
	char buff[RECORD_MAX];
	int value;
	fgets(buff, RECORD_MAX, stdin);
	sscanf(buff, "%d", &value);
	return value;
}


void print_art(Food *food_tab, int n, const char *name) {
	for (int i = 0; i < n; ++i) {
		if (strcmp(food_tab[i].name, name) == 0) {
			printf("%.2f %d %02d.%02d.%04d\n", food_tab[i].price, food_tab[i].amount,
			       food_tab[i].exp_date.day, food_tab[i].exp_date.month, food_tab[i].exp_date.year);
		}
	}
}


int main(void) {
	int n;
	Food food_tab[FOOD_MAX];
	char buff[RECORD_MAX];
	const int to_do = read_int();

	switch (to_do) {
		case 1:  
			n = read_goods(food_tab, stdin, 1);
			scanf("%s", buff);
			print_art(food_tab, n, buff);
			break;
		case 2: 
			n = read_goods(food_tab, stdin, 0);
			Date curr_date;
			int days;
			scanf("%d %d %d", &curr_date.day, &curr_date.month, &curr_date.year);
			scanf("%d", &days);
			printf("%.2f\n", value(food_tab, (size_t)n, curr_date, days));
			break;
		default:
			printf("NOTHING TO DO FOR %d\n", to_do);
	}
	return 0;
}
