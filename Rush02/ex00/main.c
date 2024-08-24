/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeddah <almeddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:57:29 by almeddah          #+#    #+#             */
/*   Updated: 2024/08/24 17:12:55 by almeddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	check_dict(char *dict_name, int *fd)
{
	*fd = open(dict_name, O_RDONLY);
	if (*fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}

int	check_args(int argc, char **argv, int *fd)
{
	char	*dict_name;

	dict_name = "numbers.dict";
	if (argc < 2 || argc > 4)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (**argv)
	{
		if (**argv < '0' || **argv > '9')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		(*argv)++;
	}
	if (argc == 3)
		dict_name = ++(*argv);
	if (!check_dict(dict_name, fd))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*line;
	t_list1	*list;

	if (!check_args(argc, ++argv, &fd))
		return (0);
	line = "";
	while (line != NULL)
	{
		i = 0;
		line = get_next_line(fd);
		ft_split(line, " ");
		free(line);
	}
	close(fd);
	return (0);
}
