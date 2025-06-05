/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:40:54 by jdutille          #+#    #+#             */
/*   Updated: 2025/05/28 18:43:43 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	*head = second;
}

void	sa(t_node **A)
{
	swap(A);
	write(1, "sa\n", 3);
}

void	sb(t_node **B)
{
	swap(B);
	write(1, "sb\n", 3);
}

void	ss(t_node **A, t_node **B)
{
	swap(A);
	swap(B);
	write(1, "ss\n", 3);
}
