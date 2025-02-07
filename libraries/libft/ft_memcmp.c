/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:41:37 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/07 14:48:02 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			{
				return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
			}
			i++;
		}
	}
	return (0);
}
