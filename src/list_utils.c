/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:47:27 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/18 16:08:42 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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

int stack_len(t_node *head)
{
    int len;
    t_node *tmp;

    len = 0;
    tmp = head;
    while (tmp)
    {
        len++;
        tmp = tmp->next;
    }
    return (len);
}

void add_node_on_top(t_node **head, t_node *node)
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

void sa(t_node **a)
{
    swap(a);
    ft_putstr_fd("sa\n", 1);
}

void sb(t_node **b)
{
    swap(b);
    ft_putstr_fd("sb\n", 1);
}
void pa(t_node **b, t_node **a)
{
    push(b, a);
    ft_putstr_fd("pa\n", 1);
}

void pb(t_node **a, t_node **b)
{
    push(a, b);
    ft_putstr_fd("pb\n", 1);
}
