/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:45:43 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/18 15:31:44 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void push_a(t_node **a, t_node **b)
{
    t_node *tmp;

    if (!*b)
        return ;
    tmp = *b;
    *b = (*b)->next;
    if (*b)
        (*b)->prev = NULL;
    tmp->next = NULL;
    add_node_on_top(a, tmp);
    ft_putstr_fd("pa\n", 1);
}
void push_b(t_node **a, t_node **b)
{
    t_node *tmp;

    if (!*a)
        return ;
    tmp = *a;
    *a = (*a)->next;
    if (*a)
        (*a)->prev = NULL;
    tmp->next = NULL;
    add_node_on_top(b, tmp);
    ft_putstr_fd("pb\n", 1);
}
void swap_a(t_node **a)
{
    t_node *tmp;

    if (!*a || !(*a)->next)
        return ;
    tmp = *a;
    *a = (*a)->next;
    (*a)->prev = NULL;
    tmp->next = (*a)->next;
    if (tmp->next)
        tmp->next->prev = tmp;
    (*a)->next = tmp;
    tmp->prev = *a;
    ft_putstr_fd("sa\n", 1);
}
void swap_b(t_node **b)
{
    t_node *tmp;

    if (!*b || !(*b)->next)
        return ;
    tmp = *b;
    *b = (*b)->next;
    (*b)->prev = NULL;
    tmp->next = (*b)->next;
    if (tmp->next)
        tmp->next->prev = tmp;
    (*b)->next = tmp;
    tmp->prev = *b;
    ft_putstr_fd("sb\n", 1);
}
