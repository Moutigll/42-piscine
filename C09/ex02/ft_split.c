/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:01:58 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/26 16:41:03 by ele-lean         ###   ########.fr       */
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

	i = 1;
	size = 0;
	while (str[i])
	{
		if (is_in_char(charset, str[i]) == 0
			&& is_in_char(charset, str[i - 1]) == 1)
		
			return (size);
	}
}

char	**ft_split(char *str, char *charset)
{
	char	tab[];

	tab = (*char) malloc(get_size);
}

int	main(void)
{
	printf("%s", ft_split("Salut, voici une phrase normal,avec different,separateurs.", " ,."));
}
