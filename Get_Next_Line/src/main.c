/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 02:26:28 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/01/13 02:26:28 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd1;
	int		c;

	fd1 = open("../Tests/test.txt", O_RDONLY);
	if (fd1 == -1)
		return (1);
	c = 1;
	while ((line = get_next_line(fd1)) != NULL)
	{
		if (!line)
		{
			close(fd1);
			return (0);
		}
		printf("Linea [%d]: %s", c, line);
		free (line);
		c++;
	}
	close(fd1);
	return (0);
}
