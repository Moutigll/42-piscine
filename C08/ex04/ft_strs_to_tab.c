/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:25:02 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/19 15:16:49 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <string.h>

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return (len);
}

char *ft_strdup(char *src)
{
    char *dup;
    int len = ft_strlen(src);
    dup = (char *)malloc((len + 1) * sizeof(char));
    if (!dup)
        return (NULL);
    for (int i = 0; i < len; i++)
        dup[i] = src[i];
    dup[len] = '\0';
    return (dup);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    t_stock_str *array;
    int i;

    array = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
    if (!array)
        return (NULL);
    for (i = 0; i < ac; i++)
    {
        array[i].size = ft_strlen(av[i]);
        array[i].str = av[i];
        array[i].copy = ft_strdup(av[i]);
        if (!array[i].copy)
        {
            while (i-- > 0)
                free(array[i].copy);
            free(array);
            return (NULL);
        }
    }
    array[ac].str = 0; // Indique la fin du tableau
    return (array);
}
