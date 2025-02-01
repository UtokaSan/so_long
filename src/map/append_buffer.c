/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:24:01 by fboulbes          #+#    #+#             */
/*   Updated: 2025/02/01 21:31:25 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**allocate_empty_buffer(char *data)
{
	char	**temp;

	temp = malloc(sizeof(char *) * 2);
	if (!temp)
		return (NULL);
	temp[0] = ft_strdup(data);
	if (!temp[0])
	{
		free(temp);
		return (NULL);
	}
	temp[1] = NULL;
	return (temp);
}

void	free_partial_buffer(char **buffer, int size)
{
	int	i;

	i = 0;
	if (!buffer)
		return ;
	while (i < size)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

static int	copy_old_buffer_to_new(char **new_buffer, char **old_buffer,
int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		new_buffer[i] = ft_strdup(old_buffer[i]);
		if (!new_buffer[i])
		{
			free_partial_buffer(new_buffer, i);
			return (0);
		}
		i++;
	}
	return (1);
}

unsigned int	calculate_buffer_size(char **buffer)
{
	unsigned int	size;

	size = 0;
	while (buffer && buffer[size])
		size++;
	return (size);
}

char	**append_buffer(char **buffer, char *data)
{
	char	**temp;
	int		buffer_size;

	buffer_size = calculate_buffer_size(buffer);
	if (!data || data[0] == '\0')
		return (NULL);
	if (!buffer)
		return (allocate_empty_buffer(data));
	temp = malloc(sizeof(char *) * (buffer_size + 2));
	if (!temp)
		return (NULL);
	if (!copy_old_buffer_to_new(temp, buffer, buffer_size))
	{
		free(temp);
		return (NULL);
	}
	temp[buffer_size] = ft_strdup(data);
	if (!temp[buffer_size])
	{
		free_partial_buffer(temp, buffer_size);
		return (NULL);
	}
	temp[buffer_size + 1] = NULL;
	free_partial_buffer(buffer, buffer_size);
	return (temp);
}
