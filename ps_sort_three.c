/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:29:00 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/12 10:39:41 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	top_min(t_node **a)
{
	if ((*a)->next->next->data < (*a)->next->data)
	{
		swap_a(*a, 0);
		rotate_a(a, 0);
	}
}

void	middle_min(t_node **a)
{
	if ((*a)->data < (*a)->next->next->data)
		swap_a(*a, 0);
	else
		rotate_a(a, 0);
}

void	last_min(t_node **a)
{
	if ((*a)->data < (*a)->next->data)
		rrotate_a(a, 0);
	else
	{
		swap_a(*a, 0);
		rrotate_a(a, 0);
	}
}

void	sort_three(t_node **a)
{
	int	min_t;

	min_t = min(*a);
	if ((*a)->data == min_t)
	{
		top_min(a);
	}
	if ((*a)->next->data == min_t)
	{
		middle_min(a);
	}
	if ((*a)->next->next->data == min_t)
	{
		last_min(a);
	}
}

void	sort_two(t_node **a)
{
	if ((*a)->data > (*a)->next->data)
		swap_a(*a, 0);
}
