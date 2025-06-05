/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:32:13 by jdutille          #+#    #+#             */
/*   Updated: 2024/12/01 17:43:44 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_len(const unsigned long nombre, int *compte)
{
	if (!nombre)
	{
		ft_putstr_len("(nil)", compte);
		return ;
	}
	else
	{
		ft_putstr_len("0x", compte);
		ft_hexa_lower(nombre, compte);
	}
}
