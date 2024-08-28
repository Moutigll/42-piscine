/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mainc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:05:22 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/28 11:28:25 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	check_arg(int argc)
{
	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		size;
	char	buf[4097];

	if (check_arg(argc) == 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(1, "Cannot read file.\n", 18);
			return (1);
		}
		size = read(fd, buf, 4096);
		while (size > 0)
		{
			buf[size] = '\0';
			ft_putstr(buf, size);
			size = read(fd, buf, 4096);
		}
		if (size == -1)
			write(1, "Error reading file.\n", 20);
		close(fd);
	}
	return (0);
}
