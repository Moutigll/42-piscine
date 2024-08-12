/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:52:07 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/12 10:09:55 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n < 1)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

/*int main(void)
{
	char a[] = "abcd";
	char b[] = "abcdef";
	char c[] = "";
	printf("\n%d", ft_strncmp(a, b, 3));
	printf("\n%d", ft_strncmp(b, a, 10));
	printf("\n%d", ft_strncmp(a, c, 0));
	printf("\n%d", ft_strncmp(c, a, 1));
	printf("\n%d", ft_strncmp(c, c, 0));
}*/
