int areaRect0 (struct Rect0 a)
{
	return a.width*a.height;
};

int areaRect1 (struct Rect1 a)
{
	return (a.rb.x - a.lt.x)*(a.lt.y - a.rb.y);
}