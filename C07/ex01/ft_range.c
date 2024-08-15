/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:45:12 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/15 16:31:47 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	i;
	int	range_size;

	if (min >= max)
		return (NULL);
	range_size = max - min;
	ptr = (int *)malloc(range_size * 4);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (min < max)
	{
		ptr[i] = min;
		min++;
		i++;
	}
	return (ptr);
}

/*int main()
{
	int	*test;
	int	min = -42;
	int max = 43;
	int size;
	int i;

	size = max - min;
	test = ft_range(min, max);

	for (i = 0; i < size; i++)
	{
		printf("%d ", test[i]);
	}
	printf("\n");
}
*/