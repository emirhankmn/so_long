/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:30:12 by eakman            #+#    #+#             */
/*   Updated: 2023/11/12 21:16:03 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <unistd.h>

void	path_error(char *errormsg)
{
	int	i;

	i = 0;
	while (errormsg[i])
	{
		write(2, &errormsg[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(0);
}

void	check_parameters(int ac, char **av)
{
	int	map_name_len;

	if (ac > 2)
		path_error("Too many arguments (It should be only two)");
	if (ac < 2)
		path_error("The Map file is missing.");
	map_name_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_name_len - 4], ".ber", 4))
		path_error("Map file extention is wrong (It should be .ber).");
}
