/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:29:25 by jdutille          #+#    #+#             */
/*   Updated: 2025/05/28 18:58:06 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
		single_arg(av[1], &a);
	else
	{
		i = 1;
		while (i < ac)
		{
			check_and_add(av[i], &a, NULL);
			i++;
		}
	}
	sort_index(&a);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
