/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:30:47 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/25 12:31:33 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_highest(t_node **head)
{
	t_node	*tmp;
	t_node	*highest;

	tmp = *head;
	highest = tmp;
	while (tmp != NULL)
	{
		if (tmp->nbr > highest->nbr)
			highest = tmp;
		tmp = tmp->next;
	}
	return (highest);
}

t_node	*find_smallest(t_node **head)
{
	t_node	*tmp;
	t_node	*smallest;

	tmp = *head;
	smallest = tmp;
	while (tmp != NULL)
	{
		if (tmp->nbr < smallest->nbr)
			smallest = tmp;
		tmp = tmp->next;
	}
	return (smallest);
}

int	distance_to_top(t_node **head, t_node *node)
{
	t_node	*tmp;
	int		top;
	int		bottom;

	tmp = *head;
	top = 0;
	while (tmp != node)
	{
		top++;
		tmp = tmp->next;
	}
	tmp = node;
	bottom = 0;
	while (tmp != NULL)
	{
		bottom--;
		tmp = tmp->next;
	}
	if (abs(top) < abs(bottom))
		return (top);
	else
		return (bottom);
}
