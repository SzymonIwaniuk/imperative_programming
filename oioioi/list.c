#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define BUFFER_SIZE 1024

typedef void (*DataFp)(void*);
typedef void (*ConstDataFp)(const void*);
typedef int  (*CompareDataFp)(const void*, const void*);

typedef struct ListElement {
    struct ListElement *next;
    void *data;
} ListElement;

typedef struct {
    ListElement *head;
    ListElement *tail;
    ConstDataFp dump_data;
    DataFp free_data;
    CompareDataFp compare_data;
    DataFp modify_data;
} List;

void *safe_malloc(const size_t size) {
    void *ptr = malloc(size);
    if(ptr) return ptr;
    printf("malloc error\n");
    exit(EXIT_FAILURE);
}

void *safe_strdup(const char *string) {
    void *ptr = safe_malloc(strlen(string) + 1);
    strcpy(ptr, string);
    return ptr;
}

void init_list(List* p_list, const ConstDataFp dump_data, const DataFp free_data,
               const CompareDataFp compare_data, const DataFp modify_data) {
    p_list->head = p_list->tail = NULL;
    p_list->dump_data = dump_data;
    p_list->free_data = free_data;
    p_list->compare_data = compare_data;
    p_list->modify_data = modify_data;
}

void dump_list(const List* p_list) {
    ListElement *el = p_list->head;
    while (el) {
        p_list->dump_data(el->data);
        printf(" ");
        el = el->next;
    }
    printf("\n");
}

void dump_list_if(const List* p_list, const void *data) {
    ListElement *el = p_list->head;
    while (el) {
        if (p_list->compare_data(el->data, data) == 0) {
            p_list->dump_data(el->data);
            printf(" ");
        }
        el = el->next;
    }
    printf("\n");
}

void free_list(List* p_list) {
    ListElement *el = p_list->head;
    while (el) {
        ListElement *next = el->next;
        p_list->free_data(el->data);
        free(el);
        el = next;
    }
    p_list->head = p_list->tail = NULL;
}

void push_front(List* p_list, void *data) {
    ListElement *el = safe_malloc(sizeof(ListElement));
    el->data = data;
    el->next = p_list->head;
    p_list->head = el;
    if (!p_list->tail)
        p_list->tail = el;
}

void push_back(List* p_list, void *data) {
    ListElement *el = safe_malloc(sizeof(ListElement));
    el->data = data;
    el->next = NULL;
    if (p_list->tail)
        p_list->tail->next = el;
    else
        p_list->head = el;
    p_list->tail = el;
}

void pop_front(List* p_list) {
    if (!p_list->head) return;
    ListElement *tmp = p_list->head;
    p_list->head = tmp->next;
    if (!p_list->head)
        p_list->tail = NULL;
    p_list->free_data(tmp->data);
    free(tmp);
}

void reverse(List* p_list) {
    ListElement *prev = NULL, *curr = p_list->head, *next;
    p_list->tail = p_list->head;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    p_list->head = prev;
}

ListElement* find_insertion_point(const List* p_list, const ListElement* p_element) {
    ListElement *curr = p_list->head;
    ListElement *prev = NULL;
    while (curr && p_list->compare_data(curr->data, p_element->data) < 0) {
        prev = curr;
        curr = curr->next;
    }
    return prev;
}

void push_after(List* p_list, void* data, ListElement* previous) {
    ListElement *el = safe_malloc(sizeof(ListElement));
    el->data = data;
    if (!previous) {
        el->next = p_list->head;
        p_list->head = el;
        if (!p_list->tail)
            p_list->tail = el;
    } else {
        el->next = previous->next;
        previous->next = el;
        if (p_list->tail == previous)
            p_list->tail = el;
    }
}

void insert_in_order(List* p_list, void* data) {
    ListElement temp = {NULL, data};
    ListElement* prev = find_insertion_point(p_list, &temp);
    if (prev == NULL && p_list->head && p_list->compare_data(p_list->head->data, data) == 0) {
        if (p_list->modify_data) p_list->modify_data(p_list->head->data);
        return;
    }
    if (prev && prev->next && p_list->compare_data(prev->next->data, data) == 0) {
        if (p_list->modify_data) p_list->modify_data(prev->next->data);
        return;
    }
    push_after(p_list, data, prev);
}


void dump_int(const void* d) {
    printf("%d", *(int*)d);
}

void free_int(void* d) {
    free(d);
}

int cmp_int(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* create_data_int(const int v) {
    int* ptr = safe_malloc(sizeof(int));
    *ptr = v;
    return ptr;
}


typedef struct DataWord {
    char* word;
    int counter;
} DataWord;

void dump_word (const void* d) {
    printf("%s", ((DataWord*)d)->word);
}

void dump_word_lowercase(const void* d) {
    const char *s = ((DataWord*)d)->word;
    while (*s) {
        putchar(tolower(*s));
        s++;
    }
}

void free_word(void* d) {
    DataWord *dw = d;
    free(dw->word);
    free(dw);
}

int cmp_word_alphabet(const void* a, const void* b) {
    return strcasecmp(((DataWord*)a)->word, ((DataWord*)b)->word);
}

int cmp_word_counter(const void* a, const void* b) {
    return ((DataWord*)a)->counter - ((DataWord*)b)->counter;
}

void modify_word(void* p) {
    ((DataWord*)p)->counter++;
}

void* create_data_word(const char* string, const int counter) {
    DataWord* dw = safe_malloc(sizeof(DataWord));
    dw->word = safe_strdup(string);
    dw->counter = counter;
    return dw;
}

// --------- Parser and test logic -------------

void stream_to_list(List* p_list, FILE* stream) {
    const char delimits[] = " \r\t\n.,?!:;-";
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, stream)) {
        char *token = strtok(buffer, delimits);
        while (token) {
            void *data = create_data_word(token, 1);
            if (p_list->compare_data)
                insert_in_order(p_list, data);
            else
                push_back(p_list, data);
            token = strtok(NULL, delimits);
        }
    }
}

void list_test(List* p_list, const int n) {
    char op;
    int v;
    for (int i = 0; i < n; ++i) {
        scanf(" %c", &op);
        switch (op) {
            case 'f':
                scanf("%d", &v);
                push_front(p_list, create_data_int(v));
                break;
            case 'b':
                scanf("%d", &v);
                push_back(p_list, create_data_int(v));
                break;
            case 'd':
                pop_front(p_list);
                break;
            case 'r':
                reverse(p_list);
                break;
            case 'i':
                scanf("%d", &v);
                insert_in_order(p_list, create_data_int(v));
                break;
            default:
                printf("No such operation: %c\n", op);
                break;
        }
    }
}

int main(void) {
    int to_do, n;
    List list;

    scanf ("%d", &to_do);
    switch (to_do) {
        case 1:
            scanf("%d", &n);
            init_list(&list, dump_int, free_int, cmp_int, NULL);
            list_test(&list, n);
            dump_list(&list);
            free_list(&list);
            break;
        case 2:
            init_list(&list, dump_word, free_word, NULL, NULL);
            stream_to_list(&list, stdin);
            dump_list(&list);
            free_list(&list);
            break;
        case 3:
            scanf("%d", &n);
            init_list(&list, dump_word_lowercase, free_word, cmp_word_alphabet, modify_word);
            stream_to_list(&list, stdin);
            list.compare_data = cmp_word_counter;
            const DataWord data = { NULL, n };
            dump_list_if(&list, &data);
            free_list(&list);
            break;
        default:
            printf("NOTHING TO DO FOR %d\n", to_do);
            break;
    }
    return 0;
}
