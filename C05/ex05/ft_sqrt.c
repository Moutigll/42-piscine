/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:51:39 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/14 13:44:07 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power -1));
}

int	ft_sqrt(int nb)
{
	int	a;

	a = 0;
	while (ft_recursive_power(a, 2) < nb && a <= 46340)
		a++;
	if (ft_recursive_power(a, 2) == nb)
		return (a);
	else
		return (0);
}

/*int	main(void)
{
	printf("%d", ft_sqrt(64));
	printf("\n%d", ft_sqrt(65));
}*/
