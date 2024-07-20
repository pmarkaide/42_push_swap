/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:47:27 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/20 11:12:45 by pmarkaid         ###   ########.fr       */
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

int	stack_len(t_node **head)
{
	int		len;
	t_node	*tmp;

	len = 0;
	tmp = *head;
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

t_node *find_highest(t_node **head)
{
	t_node	*tmp;
	t_node	*highest;

	tmp = *head;
	highest = tmp;
	while (tmp != NULL)
	{
		if(tmp->nbr > highest->nbr)
			highest = tmp;
		tmp = tmp->next;
	}
	return(highest);
}
