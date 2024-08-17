/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:03:46 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/17 22:16:22 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	initialize_utils(int utils[]);
int		check_sequences(int tab[4][4], int comb[16], int utils[]);

int	check(int tab[4][4], int comb[16])
{
	int	utils[24];

	initialize_utils(utils);
	return (check_sequences(tab, comb, utils));
}

int	main()
{
	int a[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 1}, {3, 4, 1, 2}, {4, 1, 2, 3}};
	int b[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
	printf("-%d", check(a, b));
}
