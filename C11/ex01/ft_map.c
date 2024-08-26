/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:52:00 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/26 20:01:03 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*retab;

	retab = (int *) malloc(length * sizeof(int));
	if (!retab)
		return (NULL);
	i = 0;
	while (i < length)
	{
		retab[i] = f(tab[i]);
		i++;
	}
	return (retab);
}

/*int	square(int n)
{
	return (n * n);
}

int	main(void)
{
	int tab[] = {1, 2, 3, 4, 5};
	int length = sizeof(tab) / sizeof(tab[0]);
	int *result;
	int i;

	result = ft_map(tab, length, &square);
	if (result)
	{
		for (i = 0; i < length; i++)
			printf("%d\n", result[i]);
		free(result);
	}
	return (0);
}*/
