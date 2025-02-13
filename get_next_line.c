/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:24:28 by yebi              #+#    #+#             */
/*   Updated: 2025/02/13 17:39:09 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *newline_join(char *tmp, char *buf)
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

static void	save_remaining_buffer(char *buf, ssize_t bytes_read)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	if (bytes_read == 0) 
	{
    	buf[0] = '\0';
    	return;
	}
	while (i < bytes_read && buf[i] != '\n')
		i++;
	if (i < bytes_read && buf[i] == '\n')
		i++;
	while (i < bytes_read)
		buf[j++] = buf[i++];
	while(j < bytes_read)
		buf[j++] = '\0';
}

char	*get_next_line(int fd)
{
	char		*result;
	char		*tmp;
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		bytes_read;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	if (buf[0] != '\0')
		result = ft_strjoin(NULL, buf);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == 0)
			break;
		if (bytes_read < 0)
			return (NULL);
		if(ft_strchr(buf,'\n') == NULL)
		{
			tmp = result;
			result = ft_strjoin(tmp, buf);
			if (result == NULL)
				return (NULL);
		}
		else
		{
			tmp = result;
			result = newline_join(tmp, buf);
			break ;
		}
	}
	save_remaining_buffer(buf, bytes_read);
	return (result);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("7-onechar.txt", O_RDONLY);
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
