#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <Windows.h>

void proc()
{
	const char *lable = "|/-\\";
	int i = 0;
	char bar[101];
	memset(bar, '\0', sizeof(bar));

	for (; i <= 100; i++)
	{
		printf("[%-100s][%d%%][%c]\r", bar, i, lable[i % 4]);
		bar[i] = '#';
		fflush(stdout);
		Sleep(100);
	}
	printf("\n");
}

int main()
{
	proc();
	return 0;
}