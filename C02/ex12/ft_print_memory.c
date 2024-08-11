/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:32:42 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/11 14:38:21 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	char_to_hex(char c, int t)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (t == 0)
	{
		ft_putchar('\\');
	}
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_prt_addr(unsigned long long num)
{
	char	*hex_digits;
	char	buffer[16];
	int		i;

	hex_digits = "0123456789abcdef";
	i = 15;
	while (num > 0 || i >= 0)
	{
		buffer[i--] = hex_digits[num % 16];
		num /= 16;
	}
	i = 0;
	while (i < 16)
	{
		ft_putchar(buffer[i++]);
	}
	ft_putchar(':');
	ft_putchar(' ');
}

void	ft_prt_ctn(unsigned char *addr)
{
	int	i;

	i = 0;
	while (addr[i] != '\0')
	{
		if (i % 2 == 0)
		{
			ft_putchar(' ');
		}
		ft_putchar(addr[i]);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char *c;

	c = addr;
	ft_prt_addr((unsigned long long)addr);
	ft_prt_ctn(c);
	return (0);
}

int	main(void)
{
	char	*test;
	char	**addr;

	test = "Bonjour les ";
	addr = &test;
	printf("\nValleur attendue: %p", &test);
	ft_print_memory(addr, 1);
}
