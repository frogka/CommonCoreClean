/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:48:45 by jdutille          #+#    #+#             */
/*   Updated: 2025/05/28 19:17:46 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// split dans le cas d'un seul argument
void	single_arg(char *arg, t_node **A)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(arg, ' ');
	if (!split)
		arg_error();
	while (split[i])
	{
		check_and_add(split[i], A, split);
		i++;
	}
	free_split(split);
}

// fonction qui verifie les arguments
void	check_and_add(char *arg, t_node **A, char **split)
{
	if (!valid_number(arg))
	{
		free_split(split);
		free_stack(A);
		arg_error();
	}
	if (!int_range(arg))
	{
		free_split(split);
		free_stack(A);
		arg_error();
	}
	if (duplicate(*A, ft_atoi(arg)))
	{
		free_split(split);
		free_stack(A);
		arg_error();
	}
	add_numbers(A, ft_atoi(arg));
}

// libere la memoire de la pile
void	free_stack(t_node **A)
{
	t_node	*current;
	t_node	*tmp;

	if ((*A) == NULL || A == NULL)
		return ;
	current = *A;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*A = NULL;
}

// message d'erreur
void	arg_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
