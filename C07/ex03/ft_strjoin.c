/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:19:37 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/19 00:25:59 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	calc_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	total_len;
	int	sep_len;

	i = 0;
	total_len = 0;
	sep_len = 0;
	while (sep[sep_len] != '\0')
		sep_len++;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++] != '\0')
			total_len++;
		if (i < size - 1)
			total_len += sep_len;
		i++;
	}
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		j;
	int		c;
	int		total_len;

	total_len = calc_total_len(size, strs, sep);
	s = (char *)malloc(sizeof(char) * (total_len + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	c = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			s[c++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i < size - 1)
			s[c++] = sep[j++];
		i++;
	}
	s[c] = '\0';
	return (s);
}
