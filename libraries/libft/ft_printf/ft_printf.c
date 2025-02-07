/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:45:47 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/02 16:37:40 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_sort(va_list args, char format)
{
	if (format == 'c')
		return (ft_print_c(va_arg(args, int)));
	else if (format == 's')
		return (ft_print_s(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long)));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_nbr(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == '%')
		return (ft_print_c('%'));
	else
		return (-1);
}

int	ft_handle(va_list args, const char *format, int *args_count)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_print_c(format[i]);
		else
		{
			i++;
			temp = ft_sort(args, format[i]);
			if (temp == -1)
				return (-1);
			else
			{
				count += temp;
				*args_count += 1;
			}
		}
		i++;
	}
	return (count + i);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		args_count;
	va_list	args;

	count = 0;
	args_count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	count = ft_handle(args, format, &args_count);
	va_end(args);
	if (count == -1)
		return (-1);
	else
		return (count - (args_count * 2));
}

/* int	main(void)
{
	printf("C: %i \n", ft_printf(" % "));
	printf("CP: %i \n", printf(" % "));
	printf("C: %i \n", ft_printf("% "));
	printf("CP: %i \n", printf("%"));
	printf("C: %i \n", ft_printf(" %"));
	printf("CP: %i \n", printf(" %"));
	return (0);
} */
