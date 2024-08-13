/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:31:57 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/13 15:38:47 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	if (nb < 0 || nb > 2147483647)
		return (0);
	i = 0;
	result = 1;
	while (i++ < nb)
	{
		result *= i;
	}
	return (result);
}
