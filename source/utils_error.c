/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:54:13 by eakman            #+#    #+#             */
/*   Updated: 2023/11/23 15:32:05 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <unistd.h>

void	ft_free(t_main *main)
{
	int	i;

	i = 0;
	while (main->map->map[i])
	{
		free(main->map->map[i]);
		i++;
	}
	free(main->map->map);
	free(main->map);
	free(main->sprite);
}

void	ft_error(char *errormsg, t_main *main)
{
	int	i;

	i = 0;
	while (errormsg[i])
	{
		write(2, &errormsg[i], 1);
		i++;
	}
	write(2, "\n", 1);
	ft_free(main);
	exit(0);
}

void	virtual_map_free(int **v_map, t_main *main)
{
	int	i;

	i = 0;
	while (i < main->map->y)
	{
		free(v_map[i]);
		i++;
	}
	free(v_map);
}

int	ft_x_button(t_main *main)
{
	int	i;

	i = 0;
	while (main->map->map[i])
		free(main->map->map[i++]);
	free(main->map->map);
	free(main->map);
	free(main->sprite);
	mlx_destroy_window(main->mlx, main->win);
	exit(0);
	return (0);
}

void	map_control(t_main *main, int i, int j)
{
	if (main->map->map[i][j] != 'P' || main->map->map[i][j] != '1'
		|| main->map->map[i][j] != 'C' || main->map->map[i][j] != 'E'
		|| main->map->map[i][j] != '0')
	{
		ft_error("Error\nWrong character on map.", main);
	}
}
