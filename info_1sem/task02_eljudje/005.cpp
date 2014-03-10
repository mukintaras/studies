#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	do
	{
		scanf('%c', &c);
		switch c {
			case '(': 
				st++;
				break;
			case ')':
				st--;
				break;
			case ' ':
				scanf('%c', &c2);
				if (c2 == '(')
				{
					st++;
				}
				else
				{
					
				}
		}
	} while (c != '\n');
	
	return 0;
}