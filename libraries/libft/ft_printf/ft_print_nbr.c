/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:04:57 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/02 16:37:34 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr(unsigned long nb)
{
	int	counter;

	counter = 0;
	if (nb / 10)
		counter += ft_putnbr((nb / 10));
	ft_print_c((nb % 10) + '0');
	return (++counter);
}

int	ft_print_nbr(long nb)
{
	if (nb < 0)
	{
		ft_print_c('-');
		return (ft_putnbr(-nb) + 1);
	}
	return (ft_putnbr(nb));
}
