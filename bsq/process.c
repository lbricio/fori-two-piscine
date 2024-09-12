/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebricio <lebricio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:31:12 by naharumi          #+#    #+#             */
/*   Updated: 2024/09/04 19:50:55 by lebricio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	calculate_minimum(int a, int b, int c)
{
	int	min_val;

	min_val = a;
	if (b < min_val)
		min_val = b;
	if (c < min_val)
		min_val = c;
	return (min_val);
}

void	update_cell(t_dp *dp, int i, int j, t_context *context)
{
	if (context->map->matrix[i][j] == context->map->empty)
	{
		if (i == 0 || j == 0)
			dp->curr_dp[j] = 1;
		else
		{
			dp->curr_dp[j] = 1 + calculate_minimum(dp->prev_dp[j],
					dp->curr_dp[j - 1], dp->prev_dp[j - 1]);
		}
		if (dp->curr_dp[j] > context->max_info->max_size)
		{
			context->max_info->max_size = dp->curr_dp[j];
			context->max_info->max_row = i;
			context->max_info->max_col = j;
		}
	}
	else
		dp->curr_dp[j] = 0;
}

void	process_row(t_dp *dp, int i, t_context *context)
{
	int	j;

	j = 0;
	while (j < context->map->cols)
	{
		update_cell(dp, i, j, context);
		j++;
	}
}

void	update_dp_and_find_max(t_map *map, int *prev_dp,
			int *curr_dp, t_max_info *max_info)
{
	int			i;
	int			*temp;
	t_dp		dp;
	t_context	context;

	dp.prev_dp = prev_dp;
	dp.curr_dp = curr_dp;
	context.map = map;
	context.max_info = max_info;
	i = 0;
	while (i < map->rows)
	{
		process_row(&dp, i, &context);
		temp = dp.prev_dp;
		dp.prev_dp = dp.curr_dp;
		dp.curr_dp = temp;
		i++;
	}
}
