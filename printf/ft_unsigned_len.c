/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:47:14 by jdutille          #+#    #+#             */
/*   Updated: 2024/11/28 19:14:38 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_len(unsigned int nombre, int *compte)
{
	if (nombre >= 10)
		ft_unsigned_len(nombre / 10, compte);
	ft_putchar_len(nombre % 10 + '0', compte);
}
