/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:55:37 by jalombar          #+#    #+#             */
/*   Updated: 2024/09/30 11:02:31 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinjoin(char const *s1, char const *s2, char const *s3)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1)
			* sizeof(char));
	if (!str)
		return (NULL);
	i = ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	i += ft_strlcpy(str + i, s2, ft_strlen(s2) + 1);
	ft_strlcpy(str + i, s3, ft_strlen(s3) + 1);
	return (str);
}
