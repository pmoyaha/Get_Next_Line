/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoyaha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:41:25 by pmoyaha           #+#    #+#             */
/*   Updated: 2019/07/06 09:26:59 by pmoyaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include "libft/libft.h"

int	get_next_line(int fd, char **line);

int	main(int argc, char ** argv)
{
	int		fd;
	int fd1;
	char	*line;

	if (argc < 2)
	{
		ft_putendl("Usage: prog_name <file>");
		return (0);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		fd1 = open(argv[2], O_RDONLY);
		write(1, "\n",10);
		while (get_next_line(fd, &line))
		{

			ft_putendl(line);
			free(line);
		}		
		while (get_next_line(fd1, &line))
		{
			ft_putendl(line);
			ft_strdel(&line);
		}
	}	
	return (0);
}
