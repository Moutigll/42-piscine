/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:06:51 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/12 10:06:12 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

/*int main(void)
{
	char a[] = "abcd";
	char b[] = "abcdef";
	char c[] = "";
	printf("\n%d", ft_strcmp(a, b));
	printf("\n%d", ft_strcmp(b, a));
	printf("\n%d", ft_strcmp(a, c));
	printf("\n%d", ft_strcmp(c, a));
	printf("\n%d", ft_strcmp(c, c));
}*/
