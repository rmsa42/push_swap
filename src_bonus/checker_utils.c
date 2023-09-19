/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:40:21 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/19 14:51:31 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_error(t_node **a, t_node **b)
{
	if (*a != NULL)
		free_list(a, 0);
	if (*b != NULL)
		free_list(b, 0);
	error();
}
