/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:21:03 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/27 14:25:29 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

void	operation(int a, char d, int b, char operators[5])
{
	int		(*operations[5])(int, int);

	if ((a == 0 || b == 0) && d == '/')
		write(1, "Stop : division by zero", 23);
	else if ((a == 0 || b == 0) && d == '%')
		write(1, "Stop : modulo by zero", 21);
	else
	{
		operations[0] = add;
		operations[1] = sub;
		operations[2] = mul;
		operations[3] = divi;
		operations[4] = mod;
		if (d == operators[0])
			ft_putnbr(operations[0](a, b));
		else if (d == operators[1])
			ft_putnbr(operations[1](a, b));
		else if (d == operators[2])
			ft_putnbr(operations[2](a, b));
		else if (d == operators[3])
			ft_putnbr(operations[3](a, b));
		else if (d == operators[4])
			ft_putnbr(operations[4](a, b));
	}
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	operators[5];

	if (argc != 4)
		return (0);
	if (ft_strcmp(argv[2], "+") != 0 && ft_strcmp(argv[2], "-") != 0
		&& ft_strcmp(argv[2], "*") != 0 && ft_strcmp(argv[2], "/") != 0
		&& ft_strcmp(argv[2], "%") != 0)
	{
		write(1, "0", 1);
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	operators[0] = '+';
	operators[1] = '-';
	operators[2] = '*';
	operators[3] = '/';
	operators[4] = '%';
	operation(a, argv[2][0], b, operators);
}
