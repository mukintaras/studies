// #include <stdio.h>
// #include <stdlib.h>

// typedef int Data;

// struct Node 
// {
// 	Data val;
//     struct Node * next;
// };

// struct List 
// {
// 	struct Node * head;
// };

struct List * list_create ()
{
	struct List *l = (struct List *)malloc(sizeof(struct List));
	l->head = NULL;
	return l;
}

void list_add_first (struct List * list, Data x)
{
	struct Node *fr = (struct Node *)malloc(sizeof(struct Node));
	fr->val = x;
	fr->next = list->head;
	list->head = fr;
};

void list_add_last (struct List * list, Data x)
{
	struct Node *fr = (struct Node *)malloc(sizeof(struct Node));
	fr->val = x;
	fr->next = NULL;

	struct Node * last = list->head;
	if (last == NULL)
	{
		list->head = fr;
	}
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = fr;
	};
};

// struct Node * list_goto_last (struct List * list)
// {
// 	struct Node * last = list->head;
// 	while (last->next != NULL)
// 		last = last->next;
// 	return last;
// };

Data list_remove_first (struct List * list)
{
	struct Node * first = list->head;
	list->head = list->head->next;
	Data ret = first->val;
	free((void *)first);
	return ret;
};

Data list_remove_last (struct List * list)
{
	struct Node * last = list->head;
	while (last->next != NULL)
		last = last->next;
	if (list->head == last)
		list_remove_first(list);
	else 
	{
		struct Node * prelast = list->head;
		while ((prelast->next)->next != NULL)
			prelast = prelast->next;
		Data ret = last->val;
		prelast->next = NULL;
		free((void *)last);
		return ret;
	};
};

Data list_get_first (struct List * list)
{
	return list->head->val;
};

Data list_get_last (struct List * list)
{
	struct Node * last = list->head;
	while (last->next != NULL)
		last = last->next;
	return last->val;
};

void list_print (struct List * list)
{
	if (list->head == NULL)
		printf("Empty list\n");
	else
	{
		struct Node * last = list->head;
		while (last->next != NULL)
		{
			printf("%d ", last->val);
			last = last->next;
		};
		printf("%d\n", last->val);
	};
};

int list_size(struct List * list)
{
	int ret = 1;
	struct Node * last = list->head;
	if (last == NULL)
		return 0;
	else
	{
		while (last->next != NULL)
		{
			ret++;
			last = last->next;
		};	
		return ret;
	};
};

void list_clear(struct List * list)
{
	int size = list_size(list);
	for (int i = 0; i < size; ++i)
	{
		list_remove_first(list);
	};
};

void list_destroy(struct List * list)
{
	list_clear(list);
	free((void *)list);
};

// int main()
// {
// 	struct List * list = list_create();
// 	list_print(list);
	
// 	list_add_first(list, 5); list_print(list);

// 	list_add_first(list, 6); list_print(list);

// 	list_add_last(list, 8); list_print(list);

// 	printf("%d\n", list_size(list)); list_print(list);

// 	printf("%d\n", list_get_last(list)); list_print(list);

// 	printf("%d\n", list_remove_first(list)); list_print(list);
// 	printf("%d\n", list_size(list)); list_print(list);

// 	printf("%d\n", list_remove_last(list)); list_print(list);
// 	printf("%d\n", list_size(list)); list_print(list);

// 	printf("%d\n", list_remove_last(list)); list_print(list);
// 	printf("%d\n", list_size(list)); list_print(list);

// 	return 0;
// }