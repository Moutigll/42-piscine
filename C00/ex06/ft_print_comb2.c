/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:21:13 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/10 11:51:31 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	check_size(char c)
{
	if (c < 10)
	{
		ft_putchar('0');
		ft_putchar(c + 48);
	}
	else
	{
		ft_putchar(c / 10 + 48);
		ft_putchar(c % 10 + 48);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			check_size(a);
			ft_putchar(' ');
			check_size(b);
			if (b != 99 || a != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			b++;
		}
		a ++;
	}
}
