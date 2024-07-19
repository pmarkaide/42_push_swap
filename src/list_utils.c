/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:47:27 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/19 16:33:46 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int nbr)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		exit_on_error();
	node->nbr = nbr;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	append_node(t_node **head, t_node *node)
{
	t_node	*tmp;

	if (!*head)
	{
		*head = node;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

int	stack_len(t_node *head)
{
	int		len;
	t_node	*tmp;

	len = 0;
	tmp = head;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	add_node_on_top(t_node **head, t_node *node)
{
	if (!*head)
	{
		*head = node;
		return ;
	}
	node->next = *head;
	(*head)->prev = node;
	*head = node;
}

void print_list(t_node **head)
{
	t_node	*tmp;

	if (!*head)
	{
		ft_putstr_fd("list is empty\n", 2);
		return;
	}
	tmp = *head;
	while (tmp != NULL)
	{
		ft_printf("%d\n",tmp->nbr);
		tmp = tmp->next;
	}
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
void	pa(t_node **b, t_node **a)
{
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **a, t_node **b)
{
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}

void	ra(t_node **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_node **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_node **a)
{
	rev_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node **b)
{
	rev_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	ft_putstr_fd("rrr\n", 1);
}

// do I need to check for empty list?
int is_sorted(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
	{
		if(tmp->nbr > tmp->next->nbr)
			return(0);
		tmp =  tmp->next;
	}
	return(1);
}
