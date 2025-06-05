/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_lower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:02:54 by jdutille          #+#    #+#             */
/*   Updated: 2024/12/01 17:50:42 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_lower(const unsigned long long nombre, int *compte)
{
	if (nombre / 16)
		ft_hexa_lower(nombre / 16, compte);
	if (nombre % 16 < 10)
		ft_putchar_len((nombre % 16) + '0', compte);
	else
		ft_putchar_len((char)(nombre % 16) - 10 + 'a', compte);
}
