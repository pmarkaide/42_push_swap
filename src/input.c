/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:43:50 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/17 12:51:18 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_overflow(long nb, char next_char, int neg) {
    if (neg > 0)
    {
        if (nb > INT_MAX / 10)
            return 1;
        if (nb == INT_MAX / 10 && next_char - '0' > INT_MAX % 10)
            return 1;
    }
    else
    {
        if (nb > -(long)(INT_MIN / 10))
            return 1;
        if (nb == -(long)(INT_MIN / 10) && next_char - '0' > -(INT_MIN % 10))
            return 1;
    }
    return 0;
}

int nbr_to_int(char *str, int *error)
{
    int i;
    long nb;
    int neg;

    i = 0;
    nb = 0;
    neg = 1;

    while (str[i] && (ft_isspace(str[i])))
        i++;
    if (str[i] == '-')
        neg = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] && ft_isdigit(str[i]))
    {
        if (check_overflow(nb, str[i], neg))
            *error = 1;
        nb = 10 * nb + str[i++] - '0';
    }
    if (nb < INT_MIN || nb > INT_MAX)
        *error = 1;
    return (int)nb;
}

int **is_valid_input(char **input)
{
    int len;
    int **res;
    int error;
    int   i;
    
    i = 0;
    error = 0;
    len = ft_char_array_len(input);
    res = malloc(sizeof(int *) * len);
    if (!res)
        exit_on_error();
    while(i < len)
    {
        res[i] = malloc(sizeof(int));
        if (!res[i])
            exit_on_error();
        res[i][0] = nbr_to_int(input[i], &error);
        if (error == 1)
            exit_on_error();
        i++;
    }
    res[i] = NULL;
    return res;
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
            exit_on_error();
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

    i = 0;
    clean_input(argc, argv);
    if(argc == 2)
        res = ft_split(argv[1], ' ');
    else
    {
        res = malloc(sizeof(char *) * argc);
        if (!res)
            exit_on_error(); //TODO: HANDLE FREE
        while (i < argc - 1)
        {
            res[i] = ft_strdup(argv[i + 1]);
            if(res[i] == NULL)
                exit_on_error();
            i++;
        }
        res[i] = NULL;
    }
    return (res);
}

