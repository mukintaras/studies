struct Rect1 convert01(struct Rect0 a)
{
	struct Rect1 b;
	b.lt.x = a.x;
	b.lt.y = a.y;
	b.rb.x = a.x + a.width;
	b.rb.y = a.y - a.height;
	return b;
};

struct Rect0 convert10(struct Rect1 a)
{
	struct Rect0 b;
	b.x = a.lt.x;
	b.y = a.lt.y;
	b.width = a.rb.x - a.lt.x;
	b.height = a.lt.y - a.rb.y;
	return b;
};