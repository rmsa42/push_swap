/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strat2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:36:22 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/19 13:07:04 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mv_calc1(t_info_a info_a, t_info_b info_b)
{
	int	nbr_m;

	nbr_m = 0;
	if ((info_a.size_a - info_a.rotations_a) < 
		(info_b.size_b - info_b.rotations_b))
		nbr_m = info_b.size_b - info_b.rotations_b;
	else if ((info_b.size_b - info_b.rotations_b) < 
		(info_a.size_a - info_a.rotations_a))
		nbr_m = info_a.size_a - info_a.rotations_a;
	else
		nbr_m = info_a.size_a - info_a.rotations_a;
	return (nbr_m);
}

int	mv_calc2(int rotations_a, int rotations_b)
{
	int	nbr_m;

	nbr_m = 0;
	if (rotations_a < rotations_b)
		nbr_m = rotations_b;
	else if (rotations_b < rotations_a)
		nbr_m = rotations_a;
	else
		nbr_m = rotations_a;
	return (nbr_m);
}

int	mv_calc3(t_info_b info_b)
{
	int	nbr_m;

	nbr_m = 0;
	if (info_b.rotations_b > info_b.size_b / 2)
		nbr_m = (info_b.size_b - info_b.rotations_b);
	else
		nbr_m = info_b.rotations_b;
	return (nbr_m);
}

int	mv_calc4(t_info_a info_a)
{
	int	nbr_m;

	nbr_m = 0;
	if (info_a.rotations_a > info_a.size_a / 2)
		nbr_m = (info_a.size_a - info_a.rotations_a);
	else
		nbr_m = info_a.rotations_a;
	return (nbr_m);
}

int	mv_calcs(t_info_a info_a, t_info_b info_b)
{
	int	nbr_m;

	nbr_m = 0;
	if (info_a.rotations_a > 0 && info_b.rotations_b > 0)
	{
		if (info_a.rotations_a >= info_a.size_a / 2
			&& info_b.rotations_b >= info_b.size_b / 2)
			nbr_m = mv_calc1(info_a, info_b);
		else if (info_a.rotations_a > info_a.size_a / 2
			&& info_b.rotations_b < info_b.size_b / 2)
			nbr_m = (info_a.size_a - info_a.rotations_a) + info_b.rotations_b;
		else if (info_b.rotations_b > info_b.size_b / 2
			&& info_a.rotations_a < info_a.size_a / 2)
			nbr_m = (info_b.size_b - info_b.rotations_b) + info_a.rotations_a ;
		else if (info_a.rotations_a <= info_a.size_a / 2
			&& info_b.rotations_b <= info_b.size_b / 2)
			nbr_m = mv_calc2(info_a.rotations_a, info_b.rotations_b);
	}
	if (info_a.rotations_a == 0)
		nbr_m = mv_calc3(info_b);
	else if (info_b.rotations_b == 0)
		nbr_m = mv_calc4(info_a);
	return (++nbr_m);
}
