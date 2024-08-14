/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:05:18 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/14 13:42:23 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	a;

	a = 1;
	if (nb < 2)
		return (0);
	while (a++ < nb)
		if (nb % a == 0 && a != nb)
			return (0);
	return (1);
}

/*int	main(void)
{
	printf("%d", ft_is_prime(4));
	printf("\n%d", ft_is_prime(12));
}*/
