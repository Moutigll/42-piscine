/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:38:44 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/24 17:43:20 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	split(char *str)
{
	char	*list[2];
	int		i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		list[0][i] = str[i];
		i++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i] != ':')
		return (0);
	while (str[i] == ' ')
		i++;
	while (str[i] > 31 && str[i] < 128)
	{
		list[1][i] = str[i];
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (list);
}
