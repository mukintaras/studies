// #include <stdio.h>
// #include <stdlib.h>

// typedef int Data;

// struct Node 
// {
//     struct Node * next;
//     struct Node * prev;
//     Data data;
// };

// struct List 
// {
//  struct Node * head;
// }

void list_init(struct Node * list) 
{
    list->next = list;
    list->prev = list;
    list->data = 0;
};

void list_insert(struct Node * list, struct Node * t)
{
    t->next = list->next;
    t->prev = list;
    list->next->prev = t;
    list->next = t;
};

void list_insert_before(struct Node * list, struct Node * t) 
{
    t->prev = list->prev;
    t->next = list;
    list->prev->next = t;
    list->prev = t;
};

void list_remove(struct Node * t) 
{
    struct Node * nxt = t->next;
    struct Node * prv = t->prev;
    nxt->prev = t->prev;
    prv->next = t->next;
};

void list_push_front(struct Node * list, Data d) 
{
    struct Node * node = (struct Node *)malloc(sizeof(struct Node));
    node->data = d;
    node->next = list->next;
    node->prev = list;
    list->next->prev = node;
    list->next = node;
};

void list_push_back(struct Node * list, Data d) 
{
    struct Node * node = (struct Node *)malloc(sizeof(struct Node));
    node->data = d;
    node->prev = list->prev;
    node->next = list;
    list->prev->next = node;
    list->prev = node;
};

Data list_pop_front(struct Node * list) 
{
    struct Node * nxt = list->next;
    Data x = nxt->data;
    nxt->next->prev = list;
    list->next = nxt->next;
    free(nxt);
    return x;
};

Data list_pop_back(struct Node * list) 
{
    struct Node * nxt = list->prev;
    Data x = nxt->data;
    nxt->prev->next = list;
    list->prev = nxt->prev;
    free(nxt);
    return x;
};

int list_is_empty(struct Node * list) 
{
    if ((list->prev == list->next) && (list->next == list)) 
        return 1;
    else
        return 0;
};

Data list_delete(struct Node * t) 
{
    if (list_is_empty(t)) 
        return 0;
    Data x = t->data;
    struct Node * nxt = t->next;
    struct Node * prv = t->prev;
    nxt->prev = prv;
    prv->next = nxt;
    free(t);
    return x;
};

void list_clear(struct Node * list) 
{
    struct Node * item = list->next;
    while (item != list) {
        struct Node * k = item->next;
        free(item);
        item = k;
    }
    list->next = list;
    list->prev = list;
};

void print_it(Data d, void * param)
{
	printf("%d ", d);
};

void acc(Data d, void * param) 
{
    *(int*)param += d;
};

void list_foreach(struct Node * list, void (*func)(Data d, void * param), void * param) 
{
    struct Node * item = list->next;
    while (item != list) {
        func(item->data, param);
        item = item->next;
    };
};

void list_print (struct Node * list) 
{
    list_foreach(list, print_it, NULL);
    printf("\n");
};

Data list_sum (struct Node * list) 
{
    int x = 0;
    list_foreach(list, acc, &x);
    return x;
};

// int main()
// {
//     code

//     return 0;
// }
