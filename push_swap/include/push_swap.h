/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:27:22 by jdutille          #+#    #+#             */
/*   Updated: 2025/05/28 21:09:58 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

///////OPERATIONS/////////

void				rrotate(t_node **head);
void				rra(t_node **A);
void				rrb(t_node **B);
void				rrr(t_node **A, t_node **B);
void				swap(t_node **head);
void				sa(t_node **A);
void				sb(t_node **B);
void				ss(t_node **A, t_node **B);
void				rotate(t_node **head);
void				ra(t_node **A);
void				rb(t_node **B);
void				rr(t_node **A, t_node **B);
void				push(t_node **from, t_node **to);
void				pa(t_node **A, t_node **B);
void				pb(t_node **A, t_node **B);

/////////PARSING///////////

void				single_arg(char *arg, t_node **A);
void				check_and_add(char *arg, t_node **A, char **split);
int					duplicate(t_node *head, int numbers);
int					int_range(char *av);
long				ft_atol(char *str);
int					valid_number(char *str);
void				add_numbers(t_node **A, int numbers);
void				free_stack(t_node **A);
void				arg_error(void);

//////////CHECK////////////
int					size_stack(t_node *A);
int					is_sorted(t_node **A);
void				free_split(char **tab);

///////////SORTING////////////
void				sort_stack(t_node **A, t_node **B);
void				sort_3(t_node **A);
void				sort_5(t_node **A, t_node **B);
int					max_index(t_node *A);

/////////RADIX SORT////////////
t_node				*max_unindexed(t_node *A);
void				sort_index(t_node **A);
int					max_bit(t_node *A);
void				radix_sort(t_node **A, t_node **B);

#endif