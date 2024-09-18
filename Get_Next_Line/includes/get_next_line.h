/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:09:35 by scruz-ra          #+#    #+#             */
/*   Updated: 2023/11/16 16:09:35 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>


size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int search);
char	*ft_strjoin(char *s1, char *buffer);
char	*get_lines(char *s1);
char	*new_line(char *s1);
char	*read_n_storage(int fd, char *s1);
char	*get_next_line(int fd);

#endif