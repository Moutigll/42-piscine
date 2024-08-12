/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:56:53 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/12 12:29:06 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (*to_find == '\0')
		return ((char *)str);
	if (str == NULL || to_find == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 1;
			while (str[i + j] == to_find[j] && to_find[j] != '\0')
			{
				j++;
			}
			if (to_find[j] == '\0')
			{
				return ((str + i));
			}
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	a[] = "abcdefghijklmnopqrstuvwxyz";
	char	b[] = "defgh";
	char	c[] = "pruegh";
	char	d[] = "";
	char	e[] = "abcd";

	printf("\n%s", ft_strstr(a, b));
	printf("\n%s", ft_strstr(a, c));
	printf("\n%s", ft_strstr(a, d));
	printf("\n%s", ft_strstr(a, e));
}*/
