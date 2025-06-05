/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:40:33 by jdutille          #+#    #+#             */
/*   Updated: 2025/05/28 21:04:07 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// fonction qui retoure le nbr le plus grand de la stack
t_node	*max_unindexed(t_node *A)
{
	t_node	*current;
	t_node	*max;

	current = A;
	max = NULL;
	while (current && current->index != -1)
		current = current->next;
	if (!current)
		return (NULL);
	max = current;
	current = current->next;
	while (current)
	{
		if (current->index == -1 && current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}

// fonction qui assigne l'index le plus haut au nbr le plus grand
void	sort_index(t_node **A)
{
	int		idx;
	t_node	*max_node;

	idx = size_stack(*A) - 1;
	while (idx >= 0)
	{
		max_node = max_unindexed(*A);
		if (!max_node)
			break ;
		max_node->index = idx;
		idx--;
	}
}

// fonction pour de savoir le nbr de passe necessaire pour trier via radix
int	max_bit(t_node *A)
{
	int		n;
	int		max_idx;
	t_node	*current;

	n = 0;
	max_idx = 0;
	current = A;
	while (current)
	{
		if (current->index > max_idx)
			max_idx = current->index;
		current = current->next;
	}
	while ((max_idx >> n) != 0)
		n++;
	return (n);
}

void	radix_sort(t_node **A, t_node **B)
{
	int	nbr_bits;
	int	len;
	int	i;
	int	j;

	nbr_bits = max_bit(*A);
	i = 0;
	while (i < nbr_bits)
	{
		j = 0;
		len = size_stack(*A);
		while (j < len)
		{
			if (((*A)->index >> i) & 1)
				ra(A);
			else
				pb(A, B);
			j++;
		}
		while (*B)
			pa(A, B);
		i++;
	}
}
