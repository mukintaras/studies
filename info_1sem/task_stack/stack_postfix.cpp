#include <stdio.h>
#include <stdlib.h>

//##################################################
//##################################################
//##################################################

typedef int Data;
#define errmsg -1;

struct Stack {
	int n;
	int size;
	Data * a;
};

struct Stack * stack_create(int size)
{
	static struct Stack s;
	s.a = (Data*)malloc(sizeof(Data) * size);
	s.n = 0;
	s.size = size;
	return &s;
};

int stack_is_empty(struct Stack * s)
{
	return (s->n > 0)?0:1;
};

void stack_push(struct Stack * s, Data x)
{
	s->n++;
	if (s->n >= s->size)
	{
		s->size *= 2;
		s->a = (Data*)realloc(s->a, s->size * sizeof(Data));
	}
	s->a[s->n] = x;
};

Data stack_pop(struct Stack * s)
{
	if (s->n > 0)
	{
		s->n--;
		return s->a[s->n + 1];
	}
	else
		return errmsg;
};

Data stack_get(struct Stack * s)
{
	if (s->n > 0)
		return s->a[s->n];
	else
		return errmsg;
};

void stack_print(struct Stack * s)
{
	printf("--- ");
	if (s->n > 0) 
	{
		for (int i = 1; i <= s->n; ++i)
		{
			printf("%d ", s->a[i]);
		};
		printf("\n");
	}
	else
		printf("Empty stack\n");
};

int stack_size(struct Stack * s)
{
	return s->n;
};

void stack_clear(struct Stack * s)
{
	s->n = 0;
};

void stack_destroy(struct Stack * s)
{
	free(s->a);
};

int main()
{
	// char ch = '7';
	// printf("%c\n", ch);
	// printf("%c\n", ch - '0');
	// printf("%d\n", ch);
	// printf("%d\n", ch - '0');

	struct Stack * s = stack_create(16);
	char c;
	int i = 0;

	scanf("%c", &c);
	while (c != '=')
	{
		//printf("%c\n", c);
		if (((c - '0') >= 0) && ((c - '0') <= 9))
		{
			stack_push(s, c - '0');
		}
		else
		{
			if (c == '+')
			{	
				i = stack_pop(s) + stack_pop(s);
				stack_push(s, i);
			};
			if (c == '-')
			{	
				int pop1 = stack_pop(s);
				int pop2 = stack_pop(s);
				i = pop2 - pop1;
				//printf("555 %d %d %d\n", pop1, pop2, i);
				stack_push(s, i);
			};
			if (c == '*')
			{	
				i = stack_pop(s) * stack_pop(s);
				stack_push(s, i);
			}
		};
		scanf(" %c", &c);
		//stack_print(s);
	};

	printf("%d\n", stack_pop(s));

	stack_destroy(s);

	return 0;
}