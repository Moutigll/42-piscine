/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:52:21 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/18 19:36:58 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	initialize_utils(int utils[]);
int		check_sequences(int tab[4][4], int utils[]);

int	check(int tab[4][4])
{
	int	utils[24];

	initialize_utils(utils);
	return (check_sequences(tab, utils));
}

void	check1(int p1[4], int p2[4], int p3[4], int p4[4])
{
	int	i;
	int	a[4][4];

	i = 0;
	while (i < 4)
	{
		if (p1[i] == p2[i] || p1[i] == p3[i] || p1[i] == p4[i]
			|| p2[i] == p3[i] || p2[i] == p4[i] || p3[i] == p4[i])
			return ;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		a[0][i] = p1[i];
		a[1][i] = p2[i];
		a[2][i] = p3[i];
		a[3][i] = p4[i];
		i++;
	}
	if (check(a) == 1)
		print_combination(p1, p2, p3, p4);
}

void	generate_combinations(int perm[24][4])
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = -1;
	while (i++ < 23)
	{
		j = -1;
		while (j++ < 23)
		{
			k = -1;
			while (k++ < 23)
			{
				l = -1;
				while (l++ < 23)
				{
					check1(perm[i], perm[j], perm[k], perm[l]);
				}
			}
		}
	}
}
