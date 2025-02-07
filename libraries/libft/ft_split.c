/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:29:17 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/07 14:49:01 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	if (str[i] == c || str[i] == '\0')
		count = 0;
	else
		count = 1;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			if (str[i] != '\0')
				count++;
		}
		if (str[i] != '\0')
			i++;
		else
			return (count);
	}
	return (count);
}

int	ft_freeall(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int	ft_makewords(const char *str, char **tab, char c)
{
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			j++;
			i++;
		}
		if (j)
		{
			tab[k] = ft_substr(str, (i - j), j);
			if (!tab[k++])
				return (ft_freeall(tab));
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	words = ft_countwords(s, c);
	tab = (char **)malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!ft_makewords(s, tab, c))
		return (NULL);
	tab[words] = NULL;
	return (tab);
}
