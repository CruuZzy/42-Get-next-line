/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:08:55 by scruz-ra          #+#    #+#             */
/*   Updated: 2023/11/16 16:08:55 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}

char	*ft_strchr(const char *str, int search)
{
	int	c;

	c = 0;
	if (!str)
		return (NULL);
	if (search == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[c] != '\0')
	{
		if (str[c] == (char)search)
			return ((char *)&str[c]);
		c++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *buffer)
{
	size_t	c;
	size_t	d;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		*s1 = '\0';
	}
	if (!s1 || !buffer)
		return (NULL);
	str = malloc(sizeof(char)
			* ((ft_strlen(s1) + ft_strlen(buffer)) + 1));
	if (!str)
		return (NULL);
	c = -1;
	d = 0;
	if (s1)
		while (s1[++c] != '\0')
			str[c] = s1[c];
	while (buffer[d] != '\0')
		str[c++] = buffer[d++];
	str[ft_strlen(s1) + ft_strlen(buffer)] = '\0';
	free(s1);
	return (str);
}

char	*get_lines(char *s1)
{
	int		c;
	char	*str;

	c = 0;
	if (!s1[c])
		return (NULL);
	while (s1[c] && s1[c] != '\n')
		c++;
	str = (char *)malloc(sizeof(char) * (c + 2));
	if (!str)
		return (NULL);
	c = 0;
	while (s1[c] && s1[c] != '\n')
	{
		str[c] = s1[c];
		c++;
	}
	if (s1[c] == '\n')
	{
		str[c] = s1[c];
		c++;
	}
	str[c] = '\0';
	return (str);
}

char	*new_line(char *s1)
{
	int		c;
	int		d;
	char	*str;

	c = 0;
	while (s1[c] && s1[c] != '\n')
		c++;
	if (!s1[c])
	{
		free(s1);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) - c + 1));
	if (!str)
		return (NULL);
	d = 0;
	c++;
	while (s1[c])
		str[d++] = s1[c++];
	str[d] = '\0';
	free(s1);
	return (str);
}
