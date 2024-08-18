/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations_combinations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_username <your_email@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:00:00 by your_username     #+#    #+#             */
/*   Updated: 2024/08/18 12:00:00 by your_username    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern int	g_comb[16];
void	initialize_utils(int utils[]);
int		check_sequences(int tab[4][4], int comb[16], int utils[]);

int	check(int tab[4][4], int comb[16])
{
	int	utils[24];

	initialize_utils(utils);
	return (check_sequences(tab, comb, utils));
}

void	print_combination(int p1[4], int p2[4], int p3[4], int p4[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		printf("%d ", p1[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 4)
	{
		printf("%d ", p2[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 4)
	{
		printf("%d ", p3[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 4)
	{
		printf("%d ", p4[i]);
		i++;
	}
	printf("\n\n");
}

int	check1(int p1[4], int p2[4], int p3[4], int p4[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (p1[i] == p2[i] || p1[i] == p3[i] || p1[i] == p4[i]
			|| p2[i] == p3[i] || p2[i] == p4[i] || p3[i] == p4[i])
			return (0);
		i++;
	}
	int a[4][4] = {
		{p1[0], p1[1], p1[2], p1[3]},
		{p2[0], p2[1], p2[2], p2[3]},
		{p3[0], p3[1], p3[2], p3[3]},
		{p4[0], p4[1], p4[2], p4[3]}
	};

	// Vérification de la grille
	if (check(a, g_comb) == 1)
	{
		print_combination(p1, p2, p3, p4);
		return (1);
	}

	return (0);
}

void	generate_combinations(int permutations[24][4])
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 24)
		{
			k = 0;
			while (k < 24)
			{
				l = 0;
				while (l < 24)
				{
					check1(permutations[i], permutations[j], permutations[k], permutations[l]);
					l++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
}
