/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:29:43 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/19 13:06:53 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_four(t_node **a, t_node **b, int i)
{
	if (i == 0)
		push_b(b, a, 0);
	else if (i == 1)
	{
		rotate_a(a, 0);
		if (check_sort(*a) == 0)
			return ;
		push_b(b, a, 0);
	}
	else if (i == 2)
	{
		rotate_a(a, 0);
		rotate_a(a, 0);
		if (check_sort(*a) == 0)
			return ;
		push_b(b, a, 0);
	}
	else if (i == 3)
	{
		rrotate_a(a, 0);
		if (check_sort(*a) == 0)
			return ;
		push_b(b, a, 0);
	}
}

void	top_five(t_node **a, t_node **b, int i)
{
	if (i <= 2)
		top_four(a, b, i);
	else if (i == 3)
	{
		rrotate_a(a, 0);
		rrotate_a(a, 0);
		if (check_sort(*a) == 0)
			return ;
		push_b(b, a, 0);
	}
	else if (i == 4)
	{
		rrotate_a(a, 0);
		if (check_sort(*a) == 0)
			return ;
		push_b(b, a, 0);
	}
}

int	target(t_node **a, int min_t)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = *a;
	min_t = min(*a);
	while (temp->data != min_t)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	sort_four(t_node **a, t_node **b)
{
	int	i;
	int	min;

	if (check_sort(*a) == 0)
		return ;
	min = 0;
	i = target(a, min);
	top_four(a, b, i);
	sort_three(a);
	push_a(b, a, 0);
}

void	sort_five(t_node **a, t_node **b)
{
	int		min;
	int		i;

	if (check_sort(*a) == 0)
		return ;
	min = 0;
	i = target(a, min);
	top_five(a, b, i);
	i = target(a, min);
	if (check_sort(*a) == 0)
		return ;
	top_four(a, b, i);
	sort_three(a);
	push_a(b, a, 0);
	push_a(b, a, 0);
}
