/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:30:16 by jdutille          #+#    #+#             */
/*   Updated: 2025/05/28 21:05:05 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// verifie si ma pile A est triée
int	is_sorted(t_node **A)
{
	t_node	*current;

	current = *A;
	if (current == NULL)
		return (1);
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

// retourne la taille de ma pile A
int	size_stack(t_node *A)
{
	int		size;
	t_node	*current;

	size = 0;
	current = A;
	if (A == NULL)
		return (0);
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

// libere la memoire de mon split
void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
