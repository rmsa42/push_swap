/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:51:11 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/19 14:52:02 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct node
{
	long		data;
	struct node	*next;
}					t_node;

typedef struct info_a
{
	int	rotations_a;
	int	size_a;
}				t_info_a;

typedef struct info_b
{
	int	rotations_b;
	int	size_b;
}				t_info_b;

typedef struct nbr_info
{
	long	data;
	int		rotations;
	int		size_list;
}					t_nbr_info;

t_node		*stack_init(char *argv[], int flag);
t_node		*create_node(long dt);
void		free_list(t_node **lst, int i);
void		free_array_ps(char *array[], int flag);
void		check_args(char *argv[], int flag);
void		check_dup(t_node *a);
void		check_int_max_min(t_node *a);
int			check_sort(t_node *a);
void		error(void);
int			ft_lstsize_ps(t_node *a);
int			check_position(t_node *list, int target);
int			min(t_node *list);
int			max(t_node *list);
t_node		*swap_a(t_node *a, int i);
t_node		*swap_b(t_node *b, int i);
void		push_b(t_node **b, t_node **a, int i);
void		push_a(t_node **b, t_node **a, int i);
void		rotate_a(t_node **a, int i);
void		rotate_b(t_node **b, int i);
void		rrotate_a(t_node **a, int i);
void		rrotate_b(t_node **b, int i);
void		ss(t_node *a, t_node *b, int i);
void		rr(t_node **a, t_node **b, int i);
void		rrr(t_node **a, t_node **b, int i);
void		sort_two(t_node **a);
void		sort_three(t_node **a);
void		sort_four(t_node **a, t_node **b);
void		sort_five(t_node **a, t_node **b);
void		sort_hundred(t_node **a, t_node **b);
void		sort(t_node **a, t_node **b, t_nbr_info nbr2sort,
				t_nbr_info target);
void		put_all_a(t_node **a, t_node **b);
int			mv_calcs(t_info_a info_a, t_info_b info_b);
t_nbr_info	a_nbr2move(t_node *a, t_node *b, t_info_a info_a);
t_nbr_info	b_target(t_node *b, int data_a);
void		check_error(t_node **a, t_node **b);

#endif