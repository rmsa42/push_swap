/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:14:34 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/19 13:06:35 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotating_a(t_node **a)
{
	int	size;
	int	position;

	position = check_position(*a, min(*a));
	size = ft_lstsize_ps(*a);
	while ((*a)->data != min(*a))
	{
		if (position > size / 2)
			rrotate_a(a, 0);
		else
			rotate_a(a, 0);
	}
}

void	sort_hundred(t_node **a, t_node **b)
{
	t_info_a	info_a;
	t_nbr_info	nbr2sort;
	t_nbr_info	target;

	if (check_sort(*a) == 0)
		return ;
	push_b(b, a, 0);
	push_b(b, a, 0);
	info_a.size_a = ft_lstsize_ps(*a);
	while (info_a.size_a > 3)
	{
		nbr2sort = a_nbr2move(*a, *b, info_a);
		nbr2sort.size_list = ft_lstsize_ps(*a);
		target = b_target(*b, nbr2sort.data);
		target.size_list = ft_lstsize_ps(*b);
		sort(a, b, nbr2sort, target);
		info_a.size_a = ft_lstsize_ps(*a);
	}
	sort_three(a);
	put_all_a(a, b);
	rotating_a(a);
}
