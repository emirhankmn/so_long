/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:02:55 by eakman            #+#    #+#             */
/*   Updated: 2023/11/12 17:32:11 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	map_wall_check(t_main *main)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < main->map->y)
	{
		if (main->map->map[row][0] != '1' || main->map->map[row][main->map->x
			- 1] != '1')
			ft_error("Error\nMap checker: Left or Right is wrong.", main);
		row++;
	}
	while (col < (main->map->x - 1))
	{
		if (main->map->map[0][col] != '1' || main->map->map[main->map->y
			- 1][col] != '1')
			ft_error("Error\nMap checker: Top or Bottom is wrong.", main);
		col++;
	}
}

static void	map_count_checker(t_main *main)
{
	if (main->e_count <= 0)
		ft_error("Error\nExit not found.", main);
	else if (main->e_count > 1)
		ft_error("Error\nThere are multiple exits.", main);
	else if (main->c_count <= 0)
		ft_error("Error\nCollectible not found.", main);
	else if (main->p_count <= 0)
		ft_error("Error\nPlayer not found.", main);
	else if (main->p_count > 1)
		ft_error("Error\nThere are multiple player.", main);
}

void	map_cem_checker(t_main **main, int i, int j)
{
	if ((*main)->map->map[i][j] == 'C')
		(*main)->c_count++;
	if ((*main)->map->map[i][j] == 'E')
		(*main)->e_count++;
}

void	map_checker(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	while (i < (main->map->y))
	{
		j = 0;
		while (j < (main->map->x))
		{
			if (main->map->map[i][j] == 'P')
			{
				main->p_count++;
				main->player_x = j;
				main->player_y = i;
			}
			map_cem_checker(&main, i, j);
			j++;
		}
		i++;
	}
	map_count_checker(main);
	map_wall_check(main);
}
