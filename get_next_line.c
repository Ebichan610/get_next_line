/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:24:28 by yebi              #+#    #+#             */
/*   Updated: 2024/12/06 04:12:55 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*result;
	static char		*joint;
	static void		buf[BUFFER_SIZE];
	static size_t	count;
	static ssize_t	bytes_read;

	count = BUFFER_SIZE;
	bytes_read = read(fd, buf, count);
	while (bytes_read != 0)
	{
		if (bytes_read == -1)
			return (NULL);
		joint = (char *)malloc(sizeof(char) * count);
		if (joint == NULL)
			return (NULL);
	}
}

int	main(void)
{
}
