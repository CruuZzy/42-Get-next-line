/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:09:04 by scruz-ra          #+#    #+#             */
/*   Updated: 2023/11/16 16:09:04 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*read_n_storage(int fd, char *s1)
{
	char	*buffer;
	int		read_b;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_b = 1;
	while (!ft_strchr(s1, '\n') && read_b != 0)
	{
		read_b = read(fd, buffer, BUFFER_SIZE);
		if (read_b == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[read_b] = '\0';
		s1 = ft_strjoin(s1, buffer);
	}
	free(buffer);
	return (s1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s1;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	s1 = read_n_storage(fd, s1);
	if (!s1)
		return (NULL);
	line = get_lines(s1);
	s1 = new_line(s1);
	return (line);
}
