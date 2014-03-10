union data convert(union data x)
{
	union data new;
	for (int i = 0; i < 8; ++i)
		new.arr[i] = x.arr[8 - i - 1];
	return new;
};