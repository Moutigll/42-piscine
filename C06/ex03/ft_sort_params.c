/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:32:43 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/20 17:51:48 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
 
int ft_strcmp(const char *s1, const char *s2)
{
    int i;
 
    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}
 
void    ft_sort_strings(int num, const char **s)
{
    int         i;
    int         j;
    int         min_idx;
    const char  *temp;
 
    i = 0;
    while (i < num - 1)
    {
        min_idx = i;
        j = i + 1;
        while (j < num)
        {
            if (ft_strcmp(s[j], s[min_idx]) < 0)
                min_idx = j;
            j++;
        }
        if (min_idx != i)
        {
            temp = s[i];
            s[i] = s[min_idx];
            s[min_idx] = temp;
        }
        i++;
    }
}
 
int main(int argc, const char *argv[])
{
    int i;
    int j;
 
    i = 1;
    ft_sort_strings(argc - 1, argv + 1);
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            write(1, &argv[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
    return (0);
}