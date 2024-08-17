/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:11:53 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/17 20:48:51 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check(int tab[4][4], int comb[16])
{
	//             starty  startx  evy  evx  checky  checkx
	int	utils[] = {
		0, 0, 0, 1, 1, 0,
		3, 0, 0, 1, -1, 0,
		0, 0, 1, 0, 0, 1,
		0, 3, 1, 0, 0, -1
	};
	int	uc = 0;
	int t = 0;
	int i;
	int a = 0;
	int c;
	int d;
	int e;

	while(t < 4)
	{
		i = 0;
		while (i < 4)
		{
			c = 1;
			d = 1;
			e = tab[utils[uc] + (utils[uc + 2] * i)][utils[uc + 1] + (utils[uc + 3] * i)];
			while (d < 4)
			{
				if (tab[utils[uc] + (utils[uc + 2] * i) + (utils[uc + 4] * d)][utils[uc + 1] + (utils[uc + 3] * i) + (utils[uc + 5] * d)] > e)
				{
					e = tab[utils[uc] + (utils[uc + 2] * i) + (utils[uc + 4] * d)][utils[uc + 1] + (utils[uc + 3] * i) + (utils[uc + 5] * d)];
					c++;
				}
				d++;
			}
			if (c != comb[a])
				return (0);
			a++;
			i++;
		}
		uc += 6;
		t++;
	}
	return (1);
}

int main()
{
	int a[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 1}, {3, 4, 1, 2}, {4, 1, 2, 3}};
	int b[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
	printf("-%d", check(a, b));
}
