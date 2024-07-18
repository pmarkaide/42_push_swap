/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:45:43 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/18 16:07:01 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void push(t_node **from, t_node **to)
{
    t_node *tmp;

    if (!*to)
        return ;
    tmp = *to;
    *to = (*to)->next;
    if (*to)
        (*to)->prev = NULL;
    tmp->next = NULL;
    add_node_on_top(from, tmp);
}
void swap(t_node **head)
{
    t_node *tmp;

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


