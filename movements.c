/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:25:10 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/12 11:05:40 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_node	*swap_a(t_node *a, int i)
{
	int	temp;

	temp = 0;
	if (ft_lstsize_ps(a) <= 1)
		return (a);
	else
	{
		temp = a->data;
		a->data = a->next->data;
		a->next->data = temp;
		if (i != 1)
			ft_printf("sa\n");
		return (a);
	}
}

t_node	*swap_b(t_node *b, int i)
{
	int	temp;

	temp = 0;
	if (ft_lstsize_ps(b) <= 1)
		return (b);
	else
	{
		temp = b->data;
		b->data = b->next->data;
		b->next->data = temp;
		if (i != 1)
			ft_printf("sb\n");
		return (b);
	}
}

void	ss(t_node *a, t_node *b, int i)
{
	swap_a(a, 1);
	swap_b(b, 1);
	if (i != 0)
		ft_printf("ss\n");
}

void	push_b(t_node **b, t_node **a, int i)
{
	t_node	*new;
	t_node	*temp;

	if (!(*a))
		return ;
	new = NULL;
	if (*b == NULL)
	{
		*b = create_node((*a)->data);
	}
	else
	{
		new = create_node((*a)->data);
		new->next = *b;
		*b = new;
	}
	temp = *a;
	*a = (*a)->next;
	free(temp);
	if (i != 1)
		ft_printf("pb\n");
}

void	push_a(t_node **b, t_node **a, int i)
{
	t_node	*new;
	t_node	*temp;

	if (!(*b))
		return ;
	new = NULL;
	if (*a == NULL)
	{
		*a = create_node((*b)->data);
	}
	else
	{
		new = create_node((*b)->data);
		new->next = *a;
		*a = new;
	}
	temp = *b;
	*b = (*b)->next;
	free(temp);
	if (i != 1)
		ft_printf("pa\n");
}
