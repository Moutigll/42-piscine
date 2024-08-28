/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:02:49 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/28 10:44:39 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

/*int	is_not_empty(char *str)
{
	return (str[0] != '\0');
}

int	main(void)
{
	char	*tab[] = {"", "a", "", NULL};

	if (ft_any(tab, &is_not_empty))
		printf("Au moins une chaîne n'est pas vide.\n");
	else
		printf("Toutes les chaînes sont vides.\n");
	return (0);
}*/
