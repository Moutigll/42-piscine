/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:36:13 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/27 14:44:45 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}*/

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		min_idx;
	char	*temp;

	i = 0;
	while (tab[i] != NULL)
	{
		min_idx = i;
		j = i + 1;
		while (tab[j] != NULL)
		{
			if (cmp(tab[j], tab[min_idx]) < 0)
				min_idx = j;
			j++;
		}
		if (min_idx != i)
		{
			temp = tab[i];
			tab[i] = tab[min_idx];
			tab[min_idx] = temp;
		}
		i++;
	}
}

/*int	main(void)
{
	char *tab[] = {"banana", "apple", "cherry", NULL};

	ft_advanced_sort_string_tab(tab, ft_strcmp);
	for (int i = 0; tab[i] != NULL; i++) {
		printf("%s\n", tab[i]);
	}
	return (0);
}
*/