/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:21:03 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/28 10:56:55 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

void	handle_zero_division(char op)
{
	if (op == '/')
		write(1, "Stop : division by zero\n", 24);
	else if (op == '%')
		write(1, "Stop : modulo by zero\n", 22);
}

void	apply_operation(int a, int b, int (*operation)(int, int))
{
	ft_putnbr(operation(a, b));
	write(1, "\n", 1);
}

int	get_operator_index(char op, char operators[5])
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (op == operators[i])
			return (i);
		i++;
	}
	return (-1);
}

void	operation(int a, char op, int b)
{
	int		(*operations[5])(int, int);
	char	operators[5];
	int		i;

	operations[0] = add;
	operations[1] = sub;
	operations[2] = mul;
	operations[3] = divi;
	operations[4] = mod;
	operators[0] = '+';
	operators[1] = '-';
	operators[2] = '*';
	operators[3] = '/';
	operators[4] = '%';
	i = get_operator_index(op, operators);
	if (i == -1)
		write(1, "0\n", 2);
	else if ((op == '/' || op == '%') && b == 0)
		handle_zero_division(op);
	else
		apply_operation(a, b, operations[i]);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	op;

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	op = argv[2][0];
	if (argv[2][1] == '\0')
		operation(a, op, b);
	else
		write(1, "0\n", 2);
	return (0);
}
