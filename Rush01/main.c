/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:03:46 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/17 18:00:02 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	pregen(int comb[16])
{
	int	i;
	int	j;
	int	tab[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	int a[16] = {}
	int	k;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if(comb[k] == 4)
			{
				tab[a[k*2]][a[k*2+1]] = 1;
			}
		}
		i++
	}
}

int check(int tab[4][4], int comb[16])
{
	utils[]
	while(t < 4)
	{
		while (i < 4)
		{
			k = 0;
			c = 1;
			while (tab[i][k] < tab[i][k+1])
				c++;
			if(c != comb[a])
				return (0);
			i++;
			a++;
		}
	t++;
	}
}

void	print_tab(int tab[4][4])
{
	int		i;
	int	tab[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = tab[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	int	i;
	int	comb[16];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (i < 32)
	{
		if (argv[i][0] < '1' || argv[i][0] > '4')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		comb[i - 1] = argv[i][0] - '0';
		i++;
	}
	pregen(comb)
	print_tab(tab);
	printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, ", comb[0], comb[1], comb[2], comb[3], comb[4], comb[5], comb[6], comb[7], comb[8], comb[9], comb[10], comb[11], comb[12], comb[13], comb[14], comb[15]);
	return (0);
}
