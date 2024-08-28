/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:43:52 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/28 21:10:15 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str);
char	*ft_putnbr_base(long int nbr, char *base_to, int is_neg);

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

int	skip_whitespace(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i] == ' ' || nbr[i] == '\t'
		|| nbr[i] == '\n' || nbr[i] == '\v'
		|| nbr[i] == '\f' || nbr[i] == '\r')
		i++;
	return (i);
}

int	decode_base(char *nbr, char *base, int base_len, int start_idx)
{
	int	k;
	int	result;
	int	i;

	result = 0;
	i = start_idx;
	while (nbr[i])
	{
		k = 0;
		while (base[k] && base[k] != nbr[i])
			k++;
		if (base[k] == '\0')
			break ;
		result = result * base_len + k;
		i++;
	}
	return (result);
}

char	*is_minus_zero(int dec_value, char *base_to)
{
	char	*res;

	if (dec_value == 0)
	{
		res = (char *)malloc(2 * sizeof(char));
		if (res == NULL)
			return (NULL);
		res[0] = base_to[0];
		res[1] = '\0';
		return (res);
	}
	return (NULL);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;
	int		sti;
	int		dec_value;
	char	*res;

	sign = 1;
	if (!is_base_correct(base_from) || !is_base_correct(base_to))
		return (NULL);
	sti = skip_whitespace(nbr);
	while (nbr[sti] != '\0' && (nbr[sti] == '+' || nbr[sti] == '-'))
	{
		if (nbr[sti] == '-')
			sign = -sign;
		sti++;
	}
	dec_value = decode_base(nbr, base_from, ft_strlen(base_from), sti) * sign;
	res = is_minus_zero(dec_value, base_to);
	if (res != NULL)
		return (res);
	return (ft_putnbr_base(dec_value, base_to, sign < 0));
}

/*void	test_convert_base(char *nbr, char 
*base_from, char *base_to, char *expected)
{
	char *result = ft_convert_base(nbr, base_from, base_to);
	printf("Conversion de '%s' (base '%s') à base '%s':\n",
	 nbr, base_from, base_to);
	printf("Résultat attendu: '%s'\n", expected);
	if (result == NULL)
		printf("Résultat obtenu: NULL\n");
	else
		printf("Résultat obtenu: '%s'\n", result);
	free(result);
	printf("\n");
}

int	main() {
	test_convert_base("-0", "0123456789", "01", "101010");
	test_convert_base("-42", "0123456789", "01", "-101010");
	test_convert_base("101010", "01", "0123456789ABCDEF", "2A");
	test_convert_base("2A", "0123456789ABCDEF", "0123456789", "42");
	test_convert_base("42", "0123456789", "01234567", "52");
	test_convert_base("52", "01234567", "0123456789ABCDEF", "2A");
	test_convert_base("42", "0", "01", "NULL");
	test_convert_base("42", "0123456789", "0", "NULL");
	test_convert_base("42", "01+-", "01", "NULL");
	test_convert_base("42", "0123456789", "01+-", "NULL");
	test_convert_base("", "0123456789", "01", "0");
	test_convert_base("-10", "0123456789", "01", "-1010");
	return (0);
}*/
