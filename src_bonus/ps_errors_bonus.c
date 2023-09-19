/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:00:02 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/19 13:07:37 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_list(t_node **lst, int i)
{
	t_node	*temp;

	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	if (i == 1)
		error();
}

void	free_array_ps(char *array[], int flag)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	if (flag == 1)
		error();
}
