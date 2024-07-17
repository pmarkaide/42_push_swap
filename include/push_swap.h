/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:08:08 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/17 16:00:41 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h" /* libft library */
# include <fcntl.h>              /* for open */
# include <limits.h>             /* for LONG_MAX, LONG_MIN */
# include <stdlib.h>             /* for malloc, free, exit */
# include <unistd.h>             /* for read, write */

void	remove_extra_spaces(char *str);
void	white_spaces_into_spaces(char *str);
void	is_valid_char(char *str);
void	clean_input(int argc, char **argv);
char	**parse_input(int argc, char **argv);
int		**is_valid_input(char **input);
void	exit_on_error(void);
int		**input_nbrs_to_valid_ints(char **input);
int		nbr_to_int(char *str, int *error);

#endif /* PUSH_SWAP_H */