/*
char *_strtok(char *str, char *delimiter)
{
	static char *t_start = NULL;
	static char *t_end = NULL;
	char *rtn;
	size_t *d_len;

	if (str)
	{
		t_start = t_end = str;


	}

	else if (!str && t_end)
	{
		free(t_start);
		d_len = delimited_str(t_end, delimiter);
		t_end = &t_start[d_len[1]];
		t_start[d_len[0]] = '\0';
	}
	else
		return (NULL);
	return (t_start);
}
size_t *delimited_str(static char token, char *d)
{
	size_t i, j, k, count, values[2];


	for (i = 0; token[i]; i++)
	{
		for (j = 0, k = i, count = 0;(token[i] == d[0]) && d[j]; k++, j++)
		{
			if (token[k] == d[i])
				count++;

			else
			{
				count = 0;
				break;
			}
		}
		if (count != 0)
		{
			values[0] = i;
			values[1] = i + (_strlen(d) - 1);
		}
	}
}
*/
