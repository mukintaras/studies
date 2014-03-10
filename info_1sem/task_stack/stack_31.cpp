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
}

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
	return s->a[s->n];
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