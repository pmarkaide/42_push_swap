/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:45:43 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/25 11:58:26 by pmarkaid         ###   ########.fr       */
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
