/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:24:02 by jdutille          #+#    #+#             */
/*   Updated: 2025/05/28 18:50:57 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!(*head) || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	(*head) = second;
	second->prev = NULL;
}

void	ra(t_node **A)
{
	rotate(A);
	write(1, "ra\n", 3);
}

void	rb(t_node **B)
{
	rotate(B);
	write(1, "rb\n", 3);
}

void	rr(t_node **A, t_node **B)
{
	rotate(A);
	rotate(B);
	write(1, "rr\n", 3);
}
