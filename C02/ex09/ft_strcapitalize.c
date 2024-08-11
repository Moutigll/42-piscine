/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:42:48 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/11 10:50:48 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (str[a] != '\0')
	{
		b = str[a];
		c = str[a - 1];
		if ((b > 96 && b < 123) && (c == 45 || c == 43 || c == 32 || a == 0))
		{
			str[a] -= 32;
		}
		else if ((c > 64 && c < 91) || ((c > 96 && c < 123)))
		{
			if (b > 64 && b < 91)
			{
				str[a] += 32;
			}
		}
		a++;
	}
	return (str);
}
