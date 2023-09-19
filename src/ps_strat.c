/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:10:08 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/19 13:07:02 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_max(t_node *b, t_info_a info_a)
{
	t_info_b	info_b;
	int			target;

	target = max(b);
	info_b.size_b = ft_lstsize_ps(b);
	info_b.rotations_b = check_position(b, target);
	return (mv_calcs(info_a, info_b));
}

int	btw_min_max(t_node *b, int data_a, t_info_a info_a)
{
	t_node		*temp_b;
	t_info_b	info_b;
	int			target;

	temp_b = b;
	target = min(b);
	info_b.size_b = ft_lstsize_ps(b);
	while (temp_b != NULL)
	{
		if (data_a > temp_b->data)
		{
			if (target < temp_b->data)
				target = temp_b->data;
		}
		temp_b = temp_b->next;
	}
	info_b.rotations_b = check_position(b, target);
	return (mv_calcs(info_a, info_b));
}

t_nbr_info	a_nbr2move(t_node *a, t_node *b, t_info_a info_a)
{
	t_node		*temp_a;
	t_nbr_info	nbr2move;
	int			moves;
	int			cheaper_nbr;

	cheaper_nbr = 0;
	temp_a = a;
	info_a.rotations_a = 0;
	while (temp_a != NULL)
	{
		if (temp_a->data > max(b) || temp_a->data < min(b))
			moves = min_max(b, info_a);
		else if (temp_a->data < max(b) && temp_a->data > min(b))
			moves = btw_min_max(b, temp_a->data, info_a);
		if (cheaper_nbr > moves || info_a.rotations_a == 0)
		{
			cheaper_nbr = moves;
			nbr2move.rotations = info_a.rotations_a;
			nbr2move.data = temp_a->data;
		}
		info_a.rotations_a++;
		temp_a = temp_a->next;
	}
	return (nbr2move);
}

t_nbr_info	b_target(t_node *b, int data_a)
{
	t_node		*temp_b;
	t_nbr_info	target;

	temp_b = b;
	if (data_a > max(b) || data_a < min(b))
	{
		target.data = max(b);
		target.rotations = check_position(b, target.data);
		return (target);
	}
	else
		target.data = min(b);
	while (temp_b != NULL)
	{
		if (data_a > temp_b->data)
		{
			if (target.data < temp_b->data)
				target.data = temp_b->data;
		}
		temp_b = temp_b->next;
	}
	target.rotations = check_position(b, target.data);
	return (target);
}
