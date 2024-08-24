/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeddah <almeddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:06:49 by almeddahn n       #+#    #+#             */
/*   Updated: 2024/08/24 16:29:37 by almeddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

int	count_words(char *str, char *sep, int n)
{
	while (is_sep(*str, sep))
		str++;
	while (*str)
	{
		while (!is_sep(*str, sep))
			str++;
		while (is_sep(*str, sep))
			str++;
		n++;
	}
	return (n);
}

char	**ft_split2(char *str, char **str_sep, char *sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str)
	{
		while (is_sep(*str, sep) && *str)
			str++;
		i = 0;
		while (!is_sep(str[i], sep) && str[i])
			i++;
		if (*str)
		{
			str_sep[j] = malloc(sizeof(char) * (i + 1));
			str_sep[j][0] = '\0';
			ft_strncat(str_sep[j++], str, i);
			str += i;
		}
	}
	return (str_sep);
}

char	**ft_split(char *str, char *sep)
{
	int		nb_words;
	char	**str_sep;

	nb_words = count_words(str, sep, 0);
	str_sep = malloc(sizeof(char *) * (nb_words + 1));
	if (!*str)
	{
		str_sep[0] = malloc(sizeof(char) * 1);
		str_sep[0][0] = '\0';
	}
	else
		ft_split2(str, str_sep, sep);
	str_sep[nb_words] = 0;
	return (str_sep);
}

// #include "stdio.h"

// int	main(void)
// {
// 	char	test[50] = " [] bonjour 4 je / suis  moi  ";
// 	char	sep[6] = " /[]";
// 	char	**out;
// 	int		i;

// 	i = 0;
// 	out = ft_split(test, sep);
// 	while (out[i])
// 	{
// 		printf("%s\n", out[i]);
// 		free(out[i]);
// 		i++;
// 	}
// 	free(out);
// 	return (0);
// }
