/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:43:50 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/10 16:29:26 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void remove_extra_spaces(char *str)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (str[i]) {
        if (!ft_isspace(str[i]) || (i > 0 && !ft_isspace(str[i - 1])))
            str[j++] = str[i];
        i++;
    }

    str[j] = '\0';
}

void white_spaces_into_spaces(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_isspace(str[i]))
            str[i] = ' ';
        i++;
    }
}

void is_valid_char(char *str)
{
    int	i;

    i = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]))
            i++;
        else if (str[i] == '-' || str[i] == '+')
            i++;
        else if (ft_isspace(str[i]))
            i++;
        else
            error();
    }
}

void	clean_input(int argc, char **argv)
{
    int	i;

    i = 1;
    while (i < argc)
    {
        is_valid_char(argv[i]);
        remove_extra_spaces(argv[i]);
        white_spaces_into_spaces(argv[i]);
        i++;
    }
}

char	**parse_input(int argc, char **argv)
{
    char **res;
    int i;

    i = 1;
    clean_input(argc, argv);
    if(argc == 2)
        res = ft_split(argv[1], ' ');
    else
    {
        res = malloc(sizeof(char *) * argc);
        if (!res)
            error(); //TODO: HANDLE FREE
        while (i < argc)
        {
            res[i - 1] = ft_strdup(argv[i]);
            i++;
        }
        res[i - 1] = NULL;
    }
    return (res);
}

