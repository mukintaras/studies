int cmp_int(const void * p1, const void * p2)
{
	int q1, q2;
	q1 = *(int*)p1;
	q2 = *(int*)p2;
	return (q1-q2);
};