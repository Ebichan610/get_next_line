/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:24:24 by yebi              #+#    #+#             */
/*   Updated: 2025/02/19 08:11:11 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

ssize_t	ft_strlen(char *s)
{
	ssize_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;
	char	*start;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
		return (NULL);
	start = result;
	while (s1_len-- > 0)
		*result++ = *s1++;
	while (s2_len-- > 0)
		*result++ = *s2++;
	*result = '\0';
	return (start);
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
