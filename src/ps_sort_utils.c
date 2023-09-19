/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:20:08 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/19 13:06:59 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_node *list)
{
	int	max;

	max = list->data;
	while (list != NULL)
	{
		if (list->data > max)
			max = list->data;
		list = list->next;
	}
	return (max);
}

int	min(t_node *list)
{
	int	min;

	min = list->data;
	while (list != NULL)
	{
		if (list->data < min)
			min = list->data;
		list = list->next;
	}
	return (min);
}
