/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:24:28 by yebi              #+#    #+#             */
/*   Updated: 2025/02/06 16:05:21 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*result;
	char		*prestr;
	char		*buf;
	ssize_t	bytes_read;
	ssize_t trial_count;

	buf = (char *)malloc(sizeof(char)*(BUFFER_SIZE + 1));
	if(buf == NULL)
		return (NULL);
	ft_bzero(buf,BUFFER_SIZE);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if(bytes_read == 0)
		return (NULL);
	trial_count = 0;
	while (bytes_read != 0)
	{
		if (bytes_read == -1)
			return (NULL);
		if (trial_count == 0)
		{
			result = ft_strcpy_for_gnl(buf);
			if(result == NULL)
				return (NULL);
		}
		else
		{
			prestr = ft_strcpy_for_gnl(result);
			if(prestr == NULL)
				return (NULL);
			result = prestr_cpy(prestr, buf, trial_count, bytes_read);
			free(prestr);
			if(result == NULL)
				return (NULL);
			ft_strcat_for_gnl(result, buf);
		}
		if(search_newline(buf))
			break;
		trial_count++;
		ft_bzero(buf, BUFFER_SIZE);
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (result);
}

#include <fcntl.h> 
#include <stdio.h>

int	main(void)
{
	const char *filename = "a.txt";
	char *result;
	int fd;
	fd = open(filename, O_RDONLY);
	if(fd == -1)
	{
		printf("error\n");
		return (-1);
	}
	result = get_next_line(fd);
	if(result == NULL)
	{
		printf("result is NULL\n");
		close(fd);
		return (1);
	}
	printf("%s",result);
	close(fd);
	return (0);
}
