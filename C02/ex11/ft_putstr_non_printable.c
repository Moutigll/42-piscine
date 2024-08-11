/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:04:21 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/11 12:29:28 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	char_to_hex(char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] < 32 || str[a] > 126)
		{
			char_to_hex(str[a]);
		}
		else
		{
			ft_putchar(str[a]);
		}
		a++;
	}
}

/*int	main(void)
{
	char	txt[] = "Coucou\ntu vas bien ?";

	ft_putstr_non_printable(txt);
	return 0;
}*/
