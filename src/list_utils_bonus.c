/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:04:47 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/27 14:26:59 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node	*create_node(int nbr)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
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

int	is_sorted(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
