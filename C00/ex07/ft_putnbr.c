/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:10:59 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/10 10:51:50 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
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
