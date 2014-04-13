#include <dlfcn.h>
#include <stdio.h>

char s[1000];

int main()
{
	scanf("%s", &s[0]);
	const char* name = s;

	void* lib_check = dlopen(name, RTLD_LAZY);

	if (lib_check == NULL)
		printf("NO\n");
	else
		printf("YES\n");
	
	return 0;
}