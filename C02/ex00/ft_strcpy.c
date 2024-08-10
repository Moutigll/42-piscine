/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:30:01 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/09 12:34:14 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest += *src;
		src++;
	}
	return (dest);
}

int	main(void)
{
	char a[8] = "wgefwef";
	char b;
	char* pta = &a[8];
	char* ptb = &b;

	*ft_strcpy(&b, &a);
	printf('%c', &b);
	
}
