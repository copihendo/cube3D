void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	int i;
	int j;

	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			j = 0;
			while (j < i)
			{
				if (av[1][i] == av[1][j])
					break;
				j++;
			}
			if (i == j)
				ft_putchar(av[1][j]);
			i++;
		}
		i = 0;
		while(av[2][i])
		{
			j = 0;
			while(av[1][j])
			{
				if (av[1][j] == av[2][i])
					break;
				j++;
			}
			if (av[1][j] != '\0')
			{
				i++;
				continue;
			}
			j = 0;
			while (j < i)
			{
				if (av[2][i] == av[2][j])
					break;
				j++;
			}
			if (i = j)
				ft_putchar(av[2][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return(0);
}


#include <unistd.h>

int main(int ac, char **av)
{
	int used[255];
	int i, j;

	if (ac == 3)
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (av[i][j])
			{
				if(!used[(unsigned char)av[i][j]])
				{
					used[(unsigned char)av[i][j]] = 1;
					write (1, &av[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, '\n', 1);
	return (0);
}


int main (int ac, char **av)
{
	int i,j;
	int used[255];

	if (ac == 3)
	{
		i = 0;
		while( i < 255)
			used[i++] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while(av[i][j])
			{
				if(!used[(unsigned char)av[i][j]])
				{
					used[(unsigned char)av[i][j]] = 1;
					write(1, &av[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write (1, '\n', 1);
	return (0);
}

int ft_putcheck(char *str, char c, int index)
{
	int i;

	 i = 0;
	 while (i < index)
	 {
		 if (str[i] == c)
		 	return (1);
		i++;
	 }
	return(0);
}

int main (int ac, char **av)
{
	int i;
	int j=0;
	if (ac == 3)
	{
		i = 0;
		while(av[1][i])
		{
			if(check(av[1], av[1][i], i) == 0)
			{
				j = 0;
				while(av[2][j])
				{
					if (av[2][j] == av[1][i])
					{
						ft_putchar(av[1][i]);
						break;
					}
					j++;
				}
			}
			i++;
		}

	}
	ft_putchar('\n');
}