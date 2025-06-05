/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:59:51 by jdutille          #+#    #+#             */
/*   Updated: 2024/12/01 17:51:13 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_len(char *str, int *compte)
{
	int	a;

	a = 0;
	if (!str)
		return (ft_putstr_len("(null)", compte));
	while (str[a])
	{
		ft_putchar_len(str[a], compte);
		a++;
	}
}
