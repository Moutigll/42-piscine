/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:03:46 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/18 22:47:48 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	generate_combinations(int permutations[24][4]);
static int	g_perms[24][4];
static int	g_index = 0;
int			g_comb[16];

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	permute(int *arr, int l, int r)
{
	int	i;

	if (l == r)
	{
		i = 0;
		while (i < 4)
		{
			g_perms[g_index][i] = arr[i];
			i++;
		}
		g_index++;
	}
	else
	{
		i = l;
		while (i <= r)
		{
			swap(&arr[l], &arr[i]);
			permute(arr, l + 1, r);
			swap(&arr[l], &arr[i]);
			i++;
		}
	}
}

void	fill_permutations(void)
{
	int	arr[4];

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	g_index = 0;
	permute(arr, 0, 3);
}

int	check_comb(const char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (i % 2 == 0)
		{
			if (argv[i] < '1' || argv[i] > '4')
				return (0);
			g_comb[i / 2] = argv[i] - '0';
		}
		else
		{
			if (argv[i] != ' ')
				return (0);
		}
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

int	main(int argc,unsigned char const *argv[])
{
	fill_permutations();
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!check_comb(argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	generate_combinations(g_perms);
	return (0);
}
