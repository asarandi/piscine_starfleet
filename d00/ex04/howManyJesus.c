#include "header.h"
#include <string.h>

#define d 256
#define q 101

int	substr_count(char *text, char *pattern)
{
	int n = strlen((const char *)text);
	int m = strlen((const char *)pattern);

	int i = 0;
	char h = 1;

	while (i < m - 1)
	{
		h = (h * d) % q;
		i++;
	}

	char	p = 0;
	char	t = 0;

	i = 0;
	while (i < m)
	{
		p = (d * p + pattern[i]) % q;
		t = (d * t + text[i]) % q;
		i++;
	}

	int	count = 0;
	i = 0;
	while (i < n - m)
	{
		if (p == t)
		{
			if (strncmp((const char *)&text[i], (const char *)pattern, m) == 0)
				count++;
		}
		t = (d * (t - text[i] * h) + text[i + m]) % q;
		if (t < 0)
			t = t + q;
		i++;
	}
	return (count);
}


int howManyJesus(char *bible, char *jesus)
{
	return (substr_count(bible, jesus));
}
