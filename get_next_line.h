/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:24:31 by yebi              #+#    #+#             */
/*   Updated: 2025/02/05 18:12:13 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
ssize_t search_newline(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strcpy_for_gnl(char *src);
char	*prestr_cpy(char *src, char *buf, ssize_t trial_count, ssize_t bytes_read);
void	ft_strcat_for_gnl(char *dst, char *src);

#endif
