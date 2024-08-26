/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:41:32 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/26 19:48:04 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

/*void	ft_putnbr(int n)
{
	printf("%d\n", n);
}

int	main(void)
{
	int tab[] = {1, 2, 3, 4, 5};
	int length = sizeof(tab) / sizeof(tab[0]);

	ft_foreach(tab, length, &ft_putnbr);
	return 0;
}*/