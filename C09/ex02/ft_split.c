/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:01:58 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/26 18:37:19 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_in_char(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	get_size(char *str, char *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (is_in_char(charset, str[i]) == 0
			&& (i == 0 || is_in_char(charset, str[i - 1]) == 1))
			size++;
		i++;
	}
	return (size);
}

int	get_size_piece(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && is_in_char(charset, str[i]) == 0)
		i++;
	return (i);
}

char	*copy_piece(char *str, int len)
{
	char	*piece;
	int		j;

	piece = (char *)malloc((len + 1) * sizeof(char));
	if (!piece)
		return (NULL);
	j = 0;
	while (j < len)
	{
		piece[j] = str[j];
		j++;
	}
	piece[j] = '\0';
	return (piece);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		len;

	tab = (char **)malloc((get_size(str, charset) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (is_in_char(charset, *str))
			str++;
		if (*str)
		{
			len = get_size_piece(str, charset);
			tab[i] = copy_piece(str, len);
			if (!tab[i])
				return (NULL);
			i++;
			str += len;
		}
	}
	tab[i] = 0;
	return (tab);
}

/*int	main(void)
{
	char **result = ft_split("Salut, 
	voici une phrase normale, avec différents, séparateurs.", " ,.");

	if (result)
	{
		for (int i = 0; result[i]; i++)
		{
			printf("%s\n", result[i]);
			free(result[i]);
		}
		free(result);
	}
	return (0);
}
*/