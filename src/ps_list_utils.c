/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:31 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/19 13:06:33 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(long dt)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->data = dt;
	node->next = NULL;
	return (node);
}

int	check_position(t_node *list, int target)
{
	int	i;

	i = 0;
	while (list->data != target)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int	ft_lstsize_ps(t_node *a)
{
	int	i;

	i = 0;
	if (a == NULL)
		return (0);
	else
	{
		while (a != NULL)
		{
			i++;
			a = a->next;
		}
		return (i);
	}
}

long	ft_atoi_2(const char *str)
{
	int		i;
	long	c;
	int		n;

	n = 1;
	c = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = n * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = (str[i] - '0') + (c * 10);
		i++;
	}
	return (c * n);
}

t_node	*stack_init(char *argv[], int flag)
{
	t_node	*a;
	t_node	*head_a;
	int		i;

	i = 1;
	if (flag == 0)
		i = flag;
	a = NULL;
	head_a = NULL;
	a = create_node(ft_atoi_2(argv[i]));
	i++;
	head_a = a;
	while (argv[i])
	{
		a->next = create_node(ft_atoi_2(argv[i]));
		a = a->next;
		i++;
	}
	return (head_a);
}
