/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:53:01 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/07 14:47:29 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse(char *str)
{
	char	temp;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

void	ft_breaknbr(int n, char *str, int i)
{
	if (n >= 10)
	{
		ft_breaknbr((n / 10), str, i + 1);
		ft_breaknbr((n % 10), str, i);
	}
	else
		str[i] = n + '0';
}

int	ft_checklen(int n)
{
	int	counter;

	counter = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		counter++;
	}
	while (n >= 10)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		negative;

	negative = 0;
	len = ft_checklen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == INT_MIN)
		return (str = ft_memcpy(str, "-2147483648", 12));
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	ft_breaknbr(n, str, 0);
	if (negative)
		str[len - 1] = '-';
	str[len] = '\0';
	ft_reverse(str);
	return (str);
}
