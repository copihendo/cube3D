#include "libft.h"

static size_t	ft_dig_cap(long int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int k)
{
	char		*arr;
	int			i;
	long int	n;

	n = k;
	i = ft_dig_cap(n);
	if (!(arr = ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		arr[0] = '-';
		n = -n;
	}
	arr[i] = '\0';
	while (i-- && arr[i] != '-')
	{
		arr[i] = n % 10 + '0';
		n /= 10;
	}
	return (arr);
}
