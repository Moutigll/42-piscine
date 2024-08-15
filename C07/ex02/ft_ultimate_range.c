/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:33:10 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/15 17:19:52 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*ptr;
	int	i;
	int	range_size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	range_size = max - min;
	ptr = (int *)malloc(range_size * 4);
	if (ptr == NULL)
		return (-1);
	i = 0;
	while (min < max)
	{
		ptr[i] = min;
		min++;
		i++;
	}
	*range = ptr;
	return (range_size);
}

/*int main()
{
	int	*test;
	int	min = -42;
	int max = 43;
	int size;
	int i;

	size = max - min;
	test = ft_ultimate_range(10, min, max);

	for (i = 0; i < size; i++)
	{
		printf("%d ", test[i]);
	}
	printf("\n");
}
*/