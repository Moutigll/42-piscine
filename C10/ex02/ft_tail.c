/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:15:03 by ele-lean          #+#    #+#             */
/*   Updated: 2024/08/28 13:15:05 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 32768

void	print_error(const char *msg, const char *file)
{
	if (file != NULL)
	{
		write(2, file, strlen(file));
		write(2, ": ", 2);
	}
	write(2, msg, strlen(msg));
	write(2, "\n", 1);
}

void	ft_cat(int fd)
{
	char	buf[BUF_SIZE];
	ssize_t	bytes_read;
	ssize_t	result;

	bytes_read = read(fd, buf, BUF_SIZE);
	while (bytes_read > 0)
	{
		result = write(1, buf, bytes_read);
		if (result == -1)
		{
			print_error(strerror(errno), NULL);
			close(fd);
			return ;
		}
		bytes_read = read(fd, buf, BUF_SIZE);
	}
	if (bytes_read == -1)
		print_error(strerror(errno), NULL);
	close(fd);
}

int	main(int argc, char *argv[])
{
	int	fd;
	int	index;

	index = 1;
	if (argc == 1)
		ft_cat(0);
	else
	{
		while (index < argc)
		{
			fd = open(argv[index], O_RDONLY);
			if (fd == -1)
				print_error(strerror(errno), argv[index]);
			else
				ft_cat(fd);
			index++;
		}
	}
	return (0);
}
