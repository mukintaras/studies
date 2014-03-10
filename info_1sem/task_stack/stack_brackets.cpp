#include <stdio.h>
#include <stdlib.h>

//##################################################
//##################################################
//##################################################

typedef char Data;

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
		return -1;
};

Data stack_get(struct Stack * s)
{
	if (s->n > 0)
		return s->a[s->n];
	else
		return 'E';
};

void stack_print(struct Stack * s)
{
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

//##################################################
//##################################################
//##################################################

int opnbr(char c)
{
	if ((c == '(') || (c == '{') || (c == '[') || (c == '<'))
		return 1;
	else
		return 0;
};

int anybr(char c)
{
	if ((c == ')') || (c == '}') || (c == ']') || (c == '>'))
		return 1;
	else
		if ((c == '(') || (c == '{') || (c == '[') || (c == '<'))
			return 1;
		else
			return 0;
};

char oposbr(char c)
{
	if (c == ')')
		return '(';
	if (c == '}')
		return '{';
	if (c == ']')
		return '[';
	if (c == '>')
		return '<';
};



int main()
{
	struct Stack * s = stack_create(16);
	char c;
	int good = 1;
	scanf("%c", &c);
	
	while (anybr(c) && good)
	{
		if (opnbr(c))
			stack_push(s, c);
		else
			{
			if (oposbr(c) == stack_get(s))
				stack_pop(s);
			else
				good = 0;
			};
		scanf("%c", &c);		
	};

	printf("%s\n", (good && (stack_size(s) == 0))?"YES":"NO");

	stack_destroy(s);

	return 0;
}