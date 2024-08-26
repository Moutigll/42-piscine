/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:36:48 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/08 17:02:45 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned	int	str_len(char *strr)
{
	unsigned int	len;

	len = 0;
	while (*strr != '\0')
	{
		strr++;
		len++;
	}
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, &*str, str_len(str));
}
