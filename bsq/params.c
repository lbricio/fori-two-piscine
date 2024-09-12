/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:06:23 by naharumi          #+#    #+#             */
/*   Updated: 2024/09/04 22:35:57 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_params(char *file_buf, int *i, t_map *map)
{
	*i = 0;
	while (file_buf[*i] != '\n')
		(*i)++;
	if (*i < 4)
		return (0);
	if (check_params(file_buf[*i - 3]) == 0
		|| check_params(file_buf[*i - 2]) == 0
		|| check_params(file_buf[*i - 1]) == 0)
		return (0);
	map->empty = file_buf[*i - 3];
	map->obstacle = file_buf[*i - 2];
	map->full = file_buf[*i - 1];
	if (map->empty == map->full || map->full == map->obstacle
		|| map->obstacle == map->empty)
		return (0);
	return (1);
}

int	get_qtrows(char *file_buf, int *i, t_map *map)
{
	int	j;

	j = 0;
	map->rows = 0;
	while (j < *i - 3)
	{
		if (file_buf[j] < '0' || file_buf[j] > '9')
		{
			map->rows = 0;
			break ;
		}
		map->rows = (map->rows * 10) + (file_buf[j] - '0');
		j++;
	}
	(*i)++;
	if (map->rows == 0)
		return (0);
	return (1);
}

char	*read_entire_file(int fd)
{
	int		file_size;
	char	buffer[BUFFER_SIZE + 1];
	char	*file_buf;
	char	*temp;

	file_buf = NULL;
	file_size = read(fd, buffer, BUFFER_SIZE);
	while (file_size > 0)
	{
		buffer[file_size] = '\0';
		temp = file_buf;
		file_buf = ft_strjoin(file_buf, buffer);
		free(temp);
		if (!file_buf)
			return (NULL);
		file_size = read(fd, buffer, BUFFER_SIZE);
	}
	if (file_size < 0)
		return (NULL);
	return (file_buf);
}

int	initialize_matrix(char *file_buf, t_map *map)
{
	int	i;

	i = 0;
	map->cols = 0;
	if (get_params(file_buf, &i, map) == 0
		|| get_qtrows(file_buf, &i, map) == 0)
		return (0);
	map->matrix = malloc(sizeof(char *) * map->rows);
	if (!map->matrix)
		return (0);
	if (!init_matrix(map, file_buf,
			&i, ft_strlen(file_buf)))
		return (0);
	return (1);
}

t_map	*read_file(int fd, t_map *map)
{
	char	*file_buf;

	file_buf = read_entire_file(fd);
	if (!file_buf)
		return (NULL);
	if (!initialize_matrix(file_buf, map))
	{
		free(file_buf);
		return (NULL);
	}
	free(file_buf);
	return (map);
}
