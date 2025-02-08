/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:24:31 by yebi              #+#    #+#             */
/*   Updated: 2025/02/08 19:41:59 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
ssize_t	search_newline(char *str, ssize_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strcpy_for_gnl(char *src, ssize_t bytes_read);
char	*prestr_cpy(char *src, char *buf, ssize_t trial_count,
			ssize_t bytes_read);
void	ft_strcat_for_gnl(char *dst, char *src);
ssize_t	ft_strlen(char *s);

#endif
