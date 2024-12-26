/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:59:43 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/25 21:49:08 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

char	*get_next_line(int fd);
char	*gnl_strdup(const char *str);
char	*gnl_strjoin(const char *s1, const char *s2);
char	*gnl_strchr(const char *str, int c);
char	*gnl_substr(const char *str, unsigned int start, size_t len);
size_t	gnl_strlen(const char *str);
char	*insert_buffer(char *buffer, char *data);
#endif