/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:52:05 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/12 11:06:03 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rrr(t_node **a, t_node **b, int i)
{
	rrotate_a(a, 1);
	rrotate_b(b, 1);
	if (i != 0)
		ft_printf("rrr\n");
}
