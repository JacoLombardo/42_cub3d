/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:16:43 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/02 16:37:37 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr_base(unsigned long nb, char *base)
{
	int	counter;

	counter = 0;
	if (nb / 16)
		counter += ft_putnbr_base((nb / 16), base);
	ft_print_c(base[nb % 16]);
	return (++counter);
}

int	ft_print_ptr(unsigned long p)
{
	if (!p)
		return (ft_print_s("(nil)"));
	ft_print_c('0');
	ft_print_c('x');
	return (ft_putnbr_base(p, "0123456789abcdef") + 2);
}
