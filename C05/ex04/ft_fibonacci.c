/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:25:39 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/13 16:58:25 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(double nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power -1));
}

int ft_fibonacci(int index)
{
	return (ft_recursive_power(1.6180339887, index)/2.236068);
}