/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:08:17 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/10 13:20:25 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	while (nb > 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb == 10)
	{
		ft_putchar('1');
		ft_putchar('0');
	}
	else
	{
		ft_putchar(nb + 48);
	}
}

void	ft_print_combn(int n)
{
	int	c;
	int d;

	int a[10] = {'9', '8', '7', '6', '5', '4', '3', '2', '1', '0'};
	while (a[n] <= 10 - n)
	{
		c = 0;
		while (c < n)
		{
			a[c] = a[c + 1] + 1;
			while (a[c] <= 10 - c)
			{
				d = 0
				while (d < n)
				{
					ft_putchar(a[c]);
				}
				
				ft_putchar(',');
				ft_putchar(' ');
				a[2]++;
			}
			c++;
		}
	}
}

int main(void)
{
	ft_print_combn(3):
}