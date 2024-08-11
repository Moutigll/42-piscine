/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:04:21 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/11 18:35:55 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_hex(unsigned char c)
{
	const char	*hex;

	hex = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] < 32 || (unsigned char)str[i] > 126)
		{
			ft_put_hex((unsigned char)str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}

/*int	main(void)
{
	char	txt[] = "Coucou\ntu vas bien ?";

	ft_putstr_non_printable(txt);
	return 0;
}*/
