/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:55:08 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/28 17:41:18 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_len(long int nbr, int base_len)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

void	reverse_str(char *str)
{
	int		i;
	int		j;
	char	temp;
	int		len;

	len = ft_strlen(str);
	i = 0;
	j = len - 1;
	if (str[0] == '-')
		i++;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

void	get_res(long int nb, char *base_to, char *res, int *i)
{
	int	base_len;

	base_len = ft_strlen(base_to);
	if (nb == 0)
	{
		res[(*i)++] = base_to[0];
	}
	else
	{
		while (nb > 0)
		{
			res[(*i)++] = base_to[nb % base_len];
			nb /= base_len;
		}
	}
}

char	*ft_putnbr_base(long int nbr, char *base_to, int is_neg)
{
	char		*res;
	int			len;
	int			base_len;
	int			i;
	long int	nb;

	base_len = ft_strlen(base_to);
	len = get_len(nbr, base_len);
	if (is_neg)
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	nb = nbr;
	if (is_neg)
	{
		res[i++] = '-';
		nb = -nb;
	}
	get_res(nb, base_to, res, &i);
	res[i] = '\0';
	reverse_str(res);
	return (res);
}
