/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:32:42 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/19 21:10:21 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_print_addr(unsigned long long addr)
{
	char	buffer[16];
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		buffer[i] = hex[addr % 16];
		addr = addr / 16;
		i--;
	}
	write(1, buffer, 16);
	write(1, ": ", 2);
}

void	ft_p_cnt_hex(unsigned char *c, unsigned int size, unsigned int i)
{
	unsigned int	j;

	j = 0;
	while (j < 16)
	{
		if (j < size - i)
			ft_print_hex(c[i + j]);
		else
			write(1, "  ", 2);
		if (j % 2)
			ft_putchar(' ');
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned char	*c;

	c = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		ft_print_addr((unsigned long long)(c + i));
		ft_p_cnt_hex(c, size, i);
		j = 0;
		while (j < 16 && j < size - i)
		{
			if (c[i + j] >= 32 && c[i + j] <= 126)
				ft_putchar(c[i + j]);
			else
				ft_putchar('.');
			j++;
		}
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}

int	main(void)
{
	char	test[] = "Bonjour les Aminche. C'est fou tout ce qu'on peut faire";

	ft_print_memory(test, 100);
	return (0);
}
