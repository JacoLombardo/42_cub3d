/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:54:31 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/07 14:46:46 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	tot_size;

	tot_size = nmemb * size;
	p = (void *)malloc(tot_size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, tot_size);
	return (p);
}
