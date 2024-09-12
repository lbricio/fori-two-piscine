/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:03:57 by naharumi          #+#    #+#             */
/*   Updated: 2024/09/04 17:45:42 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_map_matrix(t_map *map)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (map->matrix[i])
	{
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
	map->matrix = NULL;
}

char	*get_line(t_map *map, char *file_buf, int *i)
{
	int		j;
	int		error;
	char	*line;

	line = malloc(sizeof(char) * BUFFER_SIZE);
	if (!line)
		return (NULL);
	error = 0;
	j = 0;
	while (file_buf[*i] != '\n' && file_buf[*i] != '\0')
	{
		if (file_buf[*i] != map->empty && file_buf[*i] != map->obstacle)
			error = 1;
		line[j] = file_buf[*i];
		(*i)++;
		j++;
	}
	line[j] = '\0';
	if (map->cols == 0)
		map->cols = j;
	else if (map->cols != j || j == 0 || error == 1)
		return (NULL);
	(*i)++;
	return (line);
}

char	*init_matrix(t_map *map, char *file_buf, int *i, int size)
{
	int	row;

	row = 0;
	while (*i < size && row < map->rows)
	{
		map->matrix[row] = get_line(map, file_buf, i);
		if (!map->matrix[row])
		{
			free_map_matrix(map);
			return (NULL);
		}
		row++;
	}
	if (row != map->rows || (*i < size && file_buf[*i] != '\0'))
	{
		free_map_matrix(map);
		return (NULL);
	}
	return (*map->matrix);
}
