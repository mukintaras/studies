int list_count_all(struct Node * list, Data x)
{
	struct Node * a = list;
	Data res = 0;
	while (a->next != list)
	{
		a = a->next;
		if (a->data == x)
			res++;
	};
	return res;
};