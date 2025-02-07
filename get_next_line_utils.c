/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:24:24 by yebi              #+#    #+#             */
/*   Updated: 2025/02/06 16:09:35 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t search_newline(char *str)
{
	ssize_t judge;
	ssize_t i;

	judge = 0;
	i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			judge = 1;
		i++;
	}
	return (judge);
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

char	*ft_strcpy_for_gnl(char *src)
{
	char	*dst;
	ssize_t	len;
	ssize_t	i;

	len = 0;
	while(src[len] && src[len] != '\n')
		len++;
	dst = (char *)malloc(sizeof(char) * (len + search_newline(src) + 1));
	if(dst == NULL)
		return(NULL);
	i = 0;
	while(i < len)
	{
		dst[i] = src[i];
		i++;
	}
	if(src[i] == '\n')
	{
		dst[i] = '\n';
		i++;
	}
		dst[i] = '\0';
	return(dst);
}

char	*prestr_cpy(char *src, char *buf, ssize_t trial_count, ssize_t bytes_read)
{
	char *dst;
	ssize_t	len;
	ssize_t	i;

	len = 0;
	while (buf[len] != '\n' && len < bytes_read)
		len++;
	dst = (char *)malloc(sizeof(char) * (trial_count * BUFFER_SIZE + len +  search_newline(buf) + 1));
	if (dst == NULL)
		return (NULL);
	ft_bzero(dst, trial_count * BUFFER_SIZE + len + search_newline(buf) + 1);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void	ft_strcat_for_gnl(char *dst, char *src)
{
	ssize_t	i;
	ssize_t	dst_len;

	i = 0;
	dst_len = 0;
	while (dst[dst_len])
		dst_len++;
	while (src[i] && src[i] != '\n')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if(search_newline(src))
	{
		dst[dst_len + i] = '\n';
		i++;
	}
		dst[dst_len + i] = '\0';
	return;
}
