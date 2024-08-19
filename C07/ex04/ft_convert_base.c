/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:43:52 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/19 00:52:29 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
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

int	convert(char *str, char *base, int i, int base_len)
{
	int	k;
	int	result;

	result = 0;
	while (str[i])
	{
		k = 0;
		while (base[k] && base[k] != str[i])
			k++;
		if (base[k] == '\0')
			break ;
		result = result * base_len + k;
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	base_len;

	if (is_base_correct(base) == 0)
		return (0);
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	sign = 1;
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	base_len = 0;
	while (base[base_len])
		base_len++;
	return (convert(str, base, i, base_len) * sign);
}

/*int	main(void)
{
	printf("%d\n", ft_atoi_base("nneefiff", "poneyvif"));
	printf("%d\n", ft_atoi_base("eenno", "  poney-vif"));
	printf("%d\n", ft_atoi_base("-++---+-nneefff", "poneyvif"));
	printf("%d\n", ft_atoi_base("4833215", "01"));
	printf("%d\n", ft_atoi_base("-10000000000000000000000000000000", "01"));
	printf("%d\n", ft_atoi_base("F49A2C", "0123456789ABCDEF"));
}*/