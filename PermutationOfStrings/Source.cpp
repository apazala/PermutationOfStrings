#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int next_permutation(int n, char **s)
{
	if (n <= 1)return 0;

	int i, j;
	i = n - 1;
	while (i > 0 && strcmp(s[i - 1], s[i]) >= 0)
		i--;
	if (i == 0) return 0;
	j = i - 1; /*pivot*/
	i++;
	while (i < n && strcmp(s[j], s[i]) < 0)
		i++;
	i--;

	char *temp;
	temp = s[i];
	s[i] = s[j];
	s[j] = temp;


	for (i = j + 1, j = n - 1; i < j; i++, j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}


	return 1;
}


int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = (char**) calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = (char *) calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}