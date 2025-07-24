/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:12:52 by jdutille          #+#    #+#             */
/*   Updated: 2024/11/28 19:14:24 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_len(int nombre, int *compte)
{
	if (nombre == -2147483648)
	{
		ft_putstr_len("-2147483648", compte);
		return ;
	}
	if (nombre < 0)
	{
		ft_putchar_len('-', compte);
		ft_putnbr_len(nombre * -1, compte);
	}
	else
	{
		if (nombre >= 10)
		{
			ft_putnbr_len(nombre / 10, compte);
		}
		ft_putchar_len(nombre % 10 + '0', compte);
	}
}
