/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:11:04 by jdutille          #+#    #+#             */
/*   Updated: 2025/05/28 19:01:33 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// fonction pour les doubles
int	duplicate(t_node *head, int numbers)
{
	while (head)
	{
		if (head->value == numbers)
			return (1);
		head = head->next;
	}
	return (0);
}

// fonction pour la limite des int
int	int_range(char *av)
{
	long	num;

	num = ft_atol(av);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

// fonction qui verifie le nbr de signes et si le nombre est en chiffre
int	valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// Fonction qui ajoute un nouveau nœud à la fin de la pile A
void	add_numbers(t_node **A, int numbers)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		arg_error();
	new_node->value = numbers;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*A == NULL)
	{
		*A = new_node;
		return ;
	}
	current = *A;
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}

// atol pour verifier qu'un arg ne depasse pas le int min/max
long	ft_atol(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
