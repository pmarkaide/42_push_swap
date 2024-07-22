/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:08:08 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/22 13:07:30 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h" /* libft library */
# include <fcntl.h>              /* for open */
# include <limits.h>             /* for LONG_MAX, LONG_MIN */
# include <stdlib.h>             /* for malloc, free, exit */
# include <unistd.h>             /* for read, write */

typedef struct s_node
{
	int				nbr;
	int				index;
	int				cost;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/* input */
char				**parse_input(int argc, char **argv);
int					**is_valid_input(char **input);

/* utils */
void				remove_extra_spaces(char *str);
void				white_spaces_into_spaces(char *str);
void				exit_on_error(void);

/* nbr_to_int */
int					**input_nbrs_to_valid_ints(char **input);

/* moves */
void				push(t_node **from, t_node **to);
void				swap(t_node **head);
void				rotate(t_node **head);
void				rev_rotate(t_node **head);
void				ra(t_node **head);
void				rb(t_node **head);
void				rr(t_node **a, t_node **b);
void				rra(t_node **head);
void				rrb(t_node **head);
void				rrr(t_node **a, t_node **b);
void				sa(t_node **head);
void				sb(t_node **head);
void				ss(t_node **a, t_node **b);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);

/* list utils*/
t_node				*create_node(int nbr);
void				append_node(t_node **head, t_node *node);
int					stack_len(t_node **head);
void				add_node_on_top(t_node **head, t_node *node);
void				print_list(t_node **head);
int					is_sorted(t_node **head);
t_node				*find_highest(t_node **head);
t_node				*find_smallest(t_node **head);
int					distance_to_top(t_node **head, t_node *node);

/* push_swap */
void				push_swap(t_node **a, t_node **b);
void				sort_three(t_node **head);

#endif /* PUSH_SWAP_H */