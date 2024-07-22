/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:45:43 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/22 22:26:23 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **from, t_node **to)
{
	t_node	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	tmp->next = *to;
	if (*to)
		(*to)->prev = tmp;
	*to = tmp;
}

void	swap(t_node **head)
{
	t_node	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	tmp->next = (*head)->next;
	if (tmp->next)
		tmp->next->prev = tmp;
	(*head)->next = tmp;
	tmp->prev = *head;
}

void	rotate(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	if (!*head || !(*head)->next)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	(*head)->prev = tmp;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	tmp->next->next = NULL;
}

void	rev_rotate(t_node **head)
{
	t_node	*tmp;
	t_node	*new_last;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	new_last = tmp->prev;
	if (new_last)
		new_last->next = NULL;
	tmp->next = *head;
	(*head)->prev = tmp;
	tmp->prev = NULL;
	*head = tmp;
}

void	sa(t_node **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_node **b, t_node **a, int n)
{
	while(n-- > 0)
	{
		push(b, a);
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_node **a, t_node **b, int n)
{
	while(n-- > 0)
	{
		push(a, b);
		ft_putstr_fd("pb\n", 1);
	}
}

void	ra(t_node **a, int n)
{
	while(n-- > 0)
	{
		rotate(a);
		ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_node **b, int n)
{
	while(n-- > 0)
	{
		rotate(b);
		ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_node **a, t_node **b, int n)
{
	while(n-- > 0)
	{
		ra(a, 1);
		rb(b, 1);
		ft_putstr_fd("rr\n", 1);
	}
}

void	rra(t_node **a, int n)
{
	while(n-- > 0)
	{
		rev_rotate(a);
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_node **b, int n)
{
	while(n-- > 0)
	{
		rev_rotate(b);
		ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_node **a, t_node **b, int n)
{
	while(n-- > 0)
	{
		rra(a, 1);
		rrb(b, 1);
		ft_putstr_fd("rrr\n", 1);
	}
}
