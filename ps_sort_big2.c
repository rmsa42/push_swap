/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:47:41 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/08 12:54:51 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	a_top(t_node **a, t_nbr_info nbr2sort)
{
	while ((*a)->data != nbr2sort.data)
	{
		if (nbr2sort.rotations > nbr2sort.size_list / 2)
			rrotate_a(a, 0);
		else
			rotate_a(a, 0);
	}
}

void	b_top(t_node **b, t_nbr_info target)
{
	while ((*b)->data != target.data)
	{
		if (target.rotations > target.size_list / 2)
			rrotate_b(b, 0);
		else
			rotate_b(b, 0);
	}
}

void	ab_top(t_node **a, t_node **b, t_nbr_info nbr2sort, t_nbr_info target)
{
	while ((*a)->data != nbr2sort.data && (*b)->data != target.data)
	{
		if (nbr2sort.rotations > nbr2sort.size_list / 2
			&& target.rotations > target.size_list / 2)
			rrr(a, b, 1);
		else if (nbr2sort.rotations < nbr2sort.size_list / 2
			&& target.rotations > target.size_list / 2)
			rotate_a(a, 0);
		else if (target.rotations < target.size_list / 2
			&& nbr2sort.rotations > nbr2sort.size_list / 2)
			rotate_b(b, 0);
		else
			rr(a, b, 1);
	}
}

void	sort(t_node **a, t_node **b, t_nbr_info nbr2sort, t_nbr_info target)
{
	ab_top(a, b, nbr2sort, target);
	if ((*a)->data == nbr2sort.data && (*b)->data != target.data)
		b_top(b, target);
	else if ((*b)->data == target.data && (*a)->data != nbr2sort.data)
		a_top(a, nbr2sort);
	push_b(b, a, 0);
}
