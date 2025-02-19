/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:24:28 by yebi              #+#    #+#             */
/*   Updated: 2025/02/19 10:16:29 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*newline_join(char *tmp, char *buf)
{
	char	*result;
	size_t	tmp_len;
	size_t	buf_copied_len;
	char	*start;

	tmp_len = ft_strlen(tmp);
	buf_copied_len = ft_strchr(buf, '\n') - buf + 1;
	result = (char *)malloc(sizeof(char) * (tmp_len + buf_copied_len + 1));
	if (result == NULL)
		return (NULL);
	start = result;
	while (tmp_len-- > 0)
		*result++ = *tmp++;
	while (buf_copied_len-- > 0)
		*result++ = *buf++;
	*result = '\0';
	return (start);
}

static char	*process_newline(char *result, char *buf)
{
	char	*tmp;

	tmp = result;
	result = newline_join(tmp, buf);
	return (result);
}

static void	save_buffer(char *buf, ssize_t bytes_read)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	if (bytes_read == 0)
	{
		buf[0] = '\0';
		return ;
	}
	while (i < bytes_read && buf[i] != '\n')
		i++;
	if (i < bytes_read && buf[i] == '\n')
		i++;
	while (i < bytes_read)
		buf[j++] = buf[i++];
	while (j < bytes_read)
		buf[j++] = '\0';
}

static char	*gnl_deal(int fd, char *result, char *buf)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (result);
		tmp = result;
		if (ft_strchr(buf, '\n'))
			result = process_newline(tmp, buf);
		else
			result = ft_strjoin(tmp, buf);
		if (tmp != NULL)
			free(tmp);
		if (result == NULL)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	save_buffer(buf, bytes_read);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*result;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	if (buf[0] != '\0')
		result = ft_strjoin(NULL, buf);
	tmp = result;
	result = gnl_deal(fd, tmp, buf);
	return (result);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("1-brouette.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
