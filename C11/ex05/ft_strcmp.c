/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:06:51 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/27 14:15:35 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
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
