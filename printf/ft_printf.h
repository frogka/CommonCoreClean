/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:17:32 by jdutille          #+#    #+#             */
/*   Updated: 2024/12/01 17:55:04 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);

void	ft_putstr_len(char *str, int *compte);
void	ft_putchar_len(char c, int *compte);
void	ft_putnbr_len(int nombre, int *compte);
void	ft_unsigned_len(unsigned int nombre, int *compte);
void	ft_hexa_lower(const unsigned long long nombre, int *compte);
void	ft_hexa_upper(const unsigned long long nombre, int *compte);
void	ft_putptr_len(const unsigned long nombre, int *compte);

#endif