void stack_create(struct Stack * s)
{
	s->n = 0;
};

void stack_push(struct Stack * s, Data x)
{
	s->n++;
	s->a[s->n] = x;
};

Data stack_pop(struct Stack * s)
{
	s->n--;
	return s->a[s->n + 1];
};

Data stack_get(struct Stack * s)
{
	return s->a[s->n];
};

void stack_print(struct Stack * s)
{
	for (int i = 1; i <= s->n; ++i)
	{
		printf("%d ", s->a[i]);
	};
	printf("\n");
};

int stack_size(struct Stack * s)
{
	return s->n;
};

void stack_clear(struct Stack * s)
{
	s->n = 0;
};