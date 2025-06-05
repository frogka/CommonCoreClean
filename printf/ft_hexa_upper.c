/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_upper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:53:33 by jdutille          #+#    #+#             */
/*   Updated: 2024/12/01 17:50:56 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_upper(const unsigned long long nombre, int *compte)
{
	if (nombre / 16)
	{
		ft_hexa_upper(nombre / 16, compte);
	}
	if (nombre % 16 < 10)
		ft_putchar_len((nombre % 16) + '0', compte);
	else
		ft_putchar_len((char)(nombre % 16) - 10 + 'A', compte);
}
