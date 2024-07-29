/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:02:39 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/29 13:40:49 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/**
 * @brief Pop the top element from one stack and pushes it to another stack.
 *        a->b c->d, pb, b a->c->d
 *
 * @param from The stack to pop from.
 * @param to The stack to push to.
 *
 * @return None, stack is modified in place.
 */
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

/**
 * @brief Swap the top two elements of the stack.
 *        a->b->c, sa, b->a->c
 *
 * @param head The stack to perform the swap on.
 *
 * @return None, stack is modified in place.
 */
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

/**
 * @brief Rotate the stack by moving the top element to the bottom.
 *        a->b->c, ra, b->c->a
 *
 * @param head The stack to perform the rotation on.
 *
 * @return None, stack is modified in place.
 */
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

/**
 * @brief rotate the stack by moving the bottom element to the top.
 *        a->b->c, rra, c->a->b
 *
 * @param head The stack to perform the reverse rotation on.
 *
 * @return None, stack is modified in place.
 */
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
