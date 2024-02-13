/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiliazers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:29:12 by eakman            #+#    #+#             */
/*   Updated: 2023/11/23 11:30:24 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	line_counter(char *path)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		free(line);
	}
	return (count);
}

int	column_counter(char *path)
{
	int		count;
	char	*line;
	int		fd;

	count = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line[count])
		count++;
	free(line);
	return (count - 1);
}

char	**map_initiliazer(char *path, t_main *main)
{
	char	*line;
	int		i;
	int		fd;
	char	*temp;
	char	**map;

	fd = open(path, O_RDONLY);
	main->map->x = column_counter(path);
	main->map->y = line_counter(path);
	map = (char **)malloc(sizeof(char *) * (main->map->y + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < main->map->y)
	{
		temp = get_next_line(fd);
		line = ft_strtrim(temp, "\n");
		map[i] = line;
		free(temp);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	main_initiliazer(char *path, t_main **main)
{
	(*main)->map = (t_map *)malloc(sizeof(t_map));
	if (!(*main)->map)
		return (1);
	(*main)->sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (!(*main)->sprite)
		return (free((*main)->map), 1);
	(*main)->read_count = 0;
	(*main)->p_count = 0;
	(*main)->c_count = 0;
	(*main)->e_count = 0;
	(*main)->m_count = 0;
	(*main)->mlx = mlx_init();
	(*main)->map->map = map_initiliazer(path, *main);
	if (!(*main)->map->map)
		return (free((*main)->sprite), free((*main)->map), 1);
	(*main)->win = mlx_new_window((*main)->mlx, (*main)->map->x * PIXEL,
			(*main)->map->y * PIXEL, "so_long");
	return (0);
}
