/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:20:40 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/13 14:46:37 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_base_correct(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	if (is_base_correct(base) == 1)
	{
		base_len = 0;
		while (base[base_len])
			base_len++;
		if (nbr < 0)
		{
			ft_putchar('-');
			if (nbr == -2147483648)
			{
				ft_putnbr_base(-(nbr / base_len), base);
				ft_putchar(base[-(nbr % base_len)]);
				return ;
			}
			nbr = -nbr;
		}
		if (nbr >= base_len)
			ft_putnbr_base(nbr / base_len, base);
		ft_putchar(base[nbr % base_len]);
	}
}

/*int	main(void)
{
	ft_putnbr_base(4833215, "poneyvif");
	ft_putchar('\n');
	ft_putnbr_base(4833215, "  poney-vif");
	ft_putchar('\n');
	ft_putnbr_base(-4833215, "poneyvif");
	ft_putchar('\n');
	ft_putnbr_base(4833215, "0");
	ft_putchar('\n');
	ft_putnbr_base(-2147483648, "01");
	ft_putchar('\n');
	ft_putnbr_base(4833215, "0123456789ABCDEF");
}*/
