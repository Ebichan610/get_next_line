/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:24:28 by yebi              #+#    #+#             */
/*   Updated: 2025/02/08 19:55:51 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(char *s)
{
	ssize_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

static void	save_remaining_buffer(char *buf, ssize_t bytes_read)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	while (i < bytes_read && buf[i] != '\n')
		i++;
	if (i < bytes_read && buf[i] == '\n')
		i++;
	while (i < bytes_read)
		buf[j++] = buf[i++];
	buf[j] = '\0';
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	ssize_t		trial_count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	trial_count = 0;
	if (buf[0] == '\0')
		ft_bzero(buf, BUFFER_SIZE + 1);
	else
	{
		result = ft_strcpy_for_gnl(buf, ft_strlen(buf));
		trial_count++;
		ft_bzero(buf, BUFFER_SIZE);
	}
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	while (bytes_read > 0)
	{
		if (trial_count == 0)
		{
			result = ft_strcpy_for_gnl(buf, bytes_read);
			if (!result)
				return (NULL);
		}
		else
		{
			result = prestr_cpy(result, buf, trial_count, bytes_read);
			if (!result)
				return (NULL);
			ft_strcat_for_gnl(result, buf);
		}
		if (search_newline(buf, bytes_read))
			break ;
		trial_count++;
		ft_bzero(buf, BUFFER_SIZE);
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	save_remaining_buffer(buf, bytes_read);
	return (result);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("a.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
