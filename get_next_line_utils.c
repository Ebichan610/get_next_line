/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:24:24 by yebi              #+#    #+#             */
/*   Updated: 2025/02/08 19:45:41 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	search_newline(char *str, ssize_t len)
{
	ssize_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_cpy;

	s_cpy = (unsigned char *)s;
	while (n-- > 0)
	{
		*s_cpy = 0;
		s_cpy++;
	}
}

char	*ft_strcpy_for_gnl(char *src, ssize_t bytes_read)
{
	char	*dst;
	ssize_t	len;
	ssize_t	i;

	if (src == NULL)
		return (NULL);
	len = 0;
	while (len < bytes_read && src[len] && src[len] != '\n')
		len++;
	dst = (char *)malloc(sizeof(char) * (len + search_newline(src, bytes_read)
				+ 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < bytes_read && src[i] == '\n')
		dst[i++] = '\n';
	dst[i] = '\0';
	return (dst);
}

char	*prestr_cpy(char *src, char *buf, ssize_t trial_count,
		ssize_t bytes_read)
{
	char	*dst;
	ssize_t	len;
	ssize_t	i;

	if (src == NULL || buf == NULL)
		return (NULL);
	len = 0;
	while (len < bytes_read && buf[len] != '\n')
		len++;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + len + 2));
	if (dst == NULL)
		return (NULL);
	ft_bzero(dst, trial_count * BUFFER_SIZE + len + 1);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	free(src);
	return (dst);
}

void	ft_strcat_for_gnl(char *dst, char *src)
{
	ssize_t	i;
	ssize_t	dst_len;
	ssize_t	src_len;

	i = 0;
	dst_len = 0;
	src_len = 0;
	while (dst[dst_len])
		dst_len++;
	while (src[src_len])
		src_len++;
	while (src[i] && src[i] != '\n')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (search_newline(src, src_len))
	{
		dst[dst_len + i] = '\n';
		i++;
	}
	dst[dst_len + i] = '\0';
	return ;
}
