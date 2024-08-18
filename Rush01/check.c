/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:11:53 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/18 18:45:15 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern int	g_comb[16];

int	get_value(int tab[4][4], int utils[], int i, int d)
{
	int	y;
	int	x;

	y = utils[0] + (utils[2] * i) + (utils[4] * d);
	x = utils[1] + (utils[3] * i) + (utils[5] * d);
	return (tab[y][x]);
}

int	get_initial_value(int tab[4][4], int utils[], int i)
{
	return (tab[utils[0] + (utils[2] * i)][utils[1] + (utils[3] * i)]);
}

int	get_max_sequence(int tab[4][4], int utils[], int i)
{
	int	c;
	int	d;
	int	e;
	int	value;

	c = 1;
	d = 1;
	e = get_initial_value(tab, utils, i);
	while (d < 4)
	{
		value = get_value(tab, utils, i, d);
		if (value > e)
		{
			e = value;
			c++;
		}
		d++;
	}
	return (c);
}

void	initialize_utils(int utils[])
{
	utils[0] = 0;
	utils[1] = 0;
	utils[2] = 0;
	utils[3] = 1;
	utils[4] = 1;
	utils[5] = 0;
	utils[6] = 3;
	utils[7] = 0;
	utils[8] = 0;
	utils[9] = 1;
	utils[10] = -1;
	utils[11] = 0;
	utils[12] = 0;
	utils[13] = 0;
	utils[14] = 1;
	utils[15] = 0;
	utils[16] = 0;
	utils[17] = 1;
	utils[18] = 0;
	utils[19] = 3;
	utils[20] = 1;
	utils[21] = 0;
	utils[22] = 0;
	utils[23] = -1;
}

int	check_sequences(int tab[4][4], int comb[16], int utils[])
{
	int	uc;
	int	t;
	int	i;
	int	a;
	int	max_sequence;

	uc = 0;
	t = 0;
	a = 0;
	while (t < 4)
	{
		i = 0;
		while (i < 4)
		{
			max_sequence = get_max_sequence(tab, &utils[uc * 6], i);
			if (max_sequence != comb[a])
				return (0);
			a++;
			i++;
		}
		uc++;
		t++;
	}
	return (1);
}
