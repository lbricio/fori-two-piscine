/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:11:24 by lebricio          #+#    #+#             */
/*   Updated: 2024/09/05 16:32:28 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	initialize_dp_arrays(int *prev_dp, int *curr_dp, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		prev_dp[i] = 0;
		curr_dp[i] = 0;
		i++;
	}
}

void	mark_square(t_map *map, int max_size, int max_row, int max_col)
{
	int	i;
	int	j;

	i = max_row;
	while (i > max_row - max_size && i >= 0)
	{
		j = max_col;
		while (j > max_col - max_size && j >= 0)
		{
			map->matrix[i][j] = map->full;
			j--;
		}
		i--;
	}
}

int	solve_bsq(t_map *map)
{
	int			*prev_dp;
	int			*curr_dp;
	t_max_info	max_info;

	if (map == NULL || map->matrix == NULL)
		return (ft_error("error\n"));
	prev_dp = (int *)malloc(map->cols * sizeof(int));
	curr_dp = (int *)malloc(map->cols * sizeof(int));
	if (!prev_dp || !curr_dp)
	{
		free(prev_dp);
		free(curr_dp);
		return (ft_error("error\n"));
	}
	initialize_dp_arrays(prev_dp, curr_dp, map->cols);
	max_info.max_size = 0;
	max_info.max_row = 0;
	max_info.max_col = 0;
	update_dp_and_find_max(map, prev_dp, curr_dp, &max_info);
	mark_square(map, max_info.max_size, max_info.max_row, max_info.max_col);
	free(prev_dp);
	free(curr_dp);
	return (0);
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	if (map == NULL || map->matrix == NULL)
		return ;
	i = 0;
	while (i < map->rows)
	{
		if (map->matrix[i] == NULL)
		{
			i++;
			continue ;
		}
		j = 0;
		while (map->matrix[i][j])
			write(1, &map->matrix[i][j++], 1);
		write(1, "\n", 1);
		free(map->matrix[i]);
		map->matrix[i] = NULL;
		i++;
	}
	free(map->matrix);
	map->matrix = NULL;
}
