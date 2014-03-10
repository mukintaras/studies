#include <stdio.h>

int main()
{
	char cc1, cc2, cc3;
	scanf("%c%c%c", &cc1, &cc2, &cc3);
	printf("char %c%c%c\n", cc1, cc2, cc3);
	printf("as is %d%d%d\n", cc1, cc2, cc3);
	printf("(int) %d%d%d\n", (int)cc1, (int)cc2, (int)cc3);
	return 0;
}