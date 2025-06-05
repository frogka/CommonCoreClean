/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:58:59 by jdutille          #+#    #+#             */
/*   Updated: 2025/05/28 18:44:00 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// fonction qui trie selon le nombre d'arguments
void	sort_stack(t_node **A, t_node **B)
{
	int	size;

	size = size_stack(*A);
	if (is_sorted(A))
		return ;
	if (size == 2)
		sa(A);
	else if (size == 3)
		sort_3(A);
	else if (size <= 5)
		sort_5(A, B);
	else
		radix_sort(A, B);
}

// retourne l'index le plus grand de la pile A
int	max_index(t_node *A)
{
	int		max;
	t_node	*current;

	max = A->index;
	current = A->next;
	while (current != NULL)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

// trie pour 3 arguments
void	sort_3(t_node **A)
{
	int	biggest;

	biggest = max_index(*A);
	if ((*A)->index == biggest)
		ra(A);
	else if ((*A)->next->index == biggest)
		rra(A);
	if ((*A)->index > (*A)->next->index)
		sa(A);
}

// trie pour 4 et 5 arguments
void	sort_5(t_node **A, t_node **B)
{
	int	size;

	size = size_stack(*A);
	while (size--)
	{
		if ((*A)->index == 0 || (*A)->index == 1)
			pb(A, B);
		else
			ra(A);
	}
	sort_3(A);
	pa(A, B);
	pa(A, B);
	if ((*A)->index > (*A)->next->index)
		sa(A);
}
