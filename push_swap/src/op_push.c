/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:39:34 by jdutille          #+#    #+#             */
/*   Updated: 2025/05/28 18:44:11 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_node **from, t_node **to)
{
	t_node	*node_push;

	if (!*from)
		return ;
	node_push = *from;
	*from = node_push->next;
	if (*from)
		(*from)->prev = NULL;
	node_push->next = *to;
	if (*to)
		(*to)->prev = node_push;
	node_push->prev = NULL;
	*to = node_push;
}

void	pa(t_node **A, t_node **B)
{
	push(B, A);
	write(1, "pa\n", 3);
}

void	pb(t_node **A, t_node **B)
{
	push(A, B);
	write(1, "pb\n", 3);
}
