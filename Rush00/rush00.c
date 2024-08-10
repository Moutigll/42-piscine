/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:54:53 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/10 12:31:34 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

//Render the top and bottom lines with the choosen characters
void	line(int a)
{
	int	c;

	c = 0;
	ft_putchar('o');
	while (c < (a - 2))
	{
		ft_putchar('-');
		c++;
	}
	if (a != 1)
	{
		ft_putchar('o');
	}
}

//Render the lines between the top and bottom ones
void	lineb(int a)
{
	int	c;

	c = 0;
	ft_putchar('|');
	while (c < (a - 2))
	{
		ft_putchar(' ');
		c++;
	}
	if (a != 1)
	{
		ft_putchar('|');
	}
	ft_putchar('\n');
}

//Main function that render the lines in the correct order
void	rush(int a, int b)
{
	int	c;

	line(a);
	ft_putchar('\n');
	if (b > 2)
	{
		c = 0;
		while (c < (b - 2))
		{
			lineb(a);
			c++;
		}
	}
	if (b > 1)
	{
		line(a);
	}
}
