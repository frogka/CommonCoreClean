/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:13:38 by jdutille          #+#    #+#             */
/*   Updated: 2024/12/01 18:10:45 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_converteur(va_list *args, char str, int *compte)
{
	if (str == 'c')
		ft_putchar_len(va_arg(*args, int), compte);
	else if (str == 's')
		ft_putstr_len(va_arg(*args, char *), compte);
	else if (str == 'd' || str == 'i')
		ft_putnbr_len(va_arg(*args, int), compte);
	else if (str == 'u')
		ft_unsigned_len(va_arg(*args, unsigned int), compte);
	else if (str == '%')
		ft_putchar_len('%', compte);
	else if (str == 'x' || str == 'X')
	{
		if (str == 'x')
			ft_hexa_lower((unsigned int)va_arg(*args, unsigned long long),
				compte);
		else
			ft_hexa_upper((unsigned int)va_arg(*args, unsigned long long),
				compte);
	}
	else if (str == 'p')
	{
		ft_putptr_len(va_arg(*args, unsigned long), compte);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		compte;
	va_list	args;

	if (!*str)
		return (0);
	va_start(args, str);
	i = 0;
	compte = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_converteur(&args, str[i], &compte);
			i++;
		}
		else
		{
			ft_putchar_len((char)str[i], &compte);
			i++;
		}
	}
	va_end(args);
	return (compte);
}
