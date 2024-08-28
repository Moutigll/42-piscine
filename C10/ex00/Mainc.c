/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mainc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:05:22 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/27 16:27:47 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int len)
{
	int		i;

	if (len == 0)
		len = ft_strlen(str);
	i = -1;
	while (++i < len)
		ft_putchar(str[i]);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	buf[4097];
	int		size;
	int		i;

	if (argc <= 1)
	{
		write(1, "File name missing.", 18);
		return (0);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.", 19);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	size = read(fd, buf, 4096);
	i = -1;
	if (fd != -1)
		while (buf[i++])
			ft_putchar(buf[i]);
	else
		write(1, "Cannot read file.", 17);
	close(fd);
}
