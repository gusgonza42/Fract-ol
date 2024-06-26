/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:02:19 by gusgonza          #+#    #+#             */
/*   Updated: 2024/05/12 16:50:23 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	
	fd = open("giant_line.txt", O_RDONLY);
	//fd = 0;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	/*while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}**/
	if (fd > 0)
		close(fd);
	return (0);
}

/*
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		line_number;
	int		counter;

	if (argc < 2)
	{
		fprintf(stderr, "Durete los argumentos\n");
		return (1);
	}
	counter = 0;
	while (++counter < argc)
	{
		fd = open(argv[counter], O_RDONLY);
		line = get_next_line(fd);
		line_number = 0;
		printf("=================================\n");
		printf("%s:\n", argv[counter]);
		printf("=================================\n");
		while (line)
		{
			printf("%d: %s\n", line_number++, line);
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (0);
}
*/
