/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:43:55 by jdutille          #+#    #+#             */
/*   Updated: 2025/05/28 18:51:04 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrotate(t_node **head)
{
	t_node	*last;
	t_node	*newlast;
	t_node	*first;

	if (!(*head) || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	newlast = last->prev;
	newlast->next = NULL;
	first->prev = last;
	last->next = first;
	(*head) = last;
	last->prev = NULL;
}

void	rra(t_node **A)
{
	rrotate(A);
	write(1, "rra\n", 4);
}

void	rrb(t_node **B)
{
	rrotate(B);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **A, t_node **B)
{
	rrotate(A);
	rrotate(B);
	write(1, "rrr\n", 4);
}
