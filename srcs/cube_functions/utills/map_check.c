/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 11:53:18 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/03 11:44:19 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int			if_empty(int x, int y, t_struct_m *main)
{
	if (y < 0 || x < 0)
		return (0);
	else if (main->cubecopy[y][x] == ' ')
	{
		main->place.error = 18;
		ft_error(main);
		return (0);
	}
	return (1);
}

int			ft_check_empty(int x, int y, t_struct_m *main)
{
	if (if_empty(x - 1, y, main) == 0)
		return (0);
	if (if_empty(x + 1, y, main) == 0)
		return (0);
	if (if_empty(x, y + 1, main) == 0)
		return (0);
	if (if_empty(x, y - 1, main) == 0)
		return (0);
	if (if_empty(x + 1, y + 1, main) == 0)
		return (0);
	if (if_empty(x - 1, y - 1, main) == 0)
		return (0);
	if (if_empty(x - 1, y + 1, main) == 0)
		return (0);
	if (if_empty(x + 1, y - 1, main) == 0)
		return (0);
	return (0);
}

void		flood_fill(int x, int y, t_struct_m *main)
{
	int		yy;

	yy = main->ray.yy - 1;
	if (main->cubecopy[y][x] == '1')
		return ;
	if (main->cubecopy[y][x] != '0' && main->cubecopy[y][x] != '2')
		return ;
	if (x <= 0 || y <= 0 || y == (yy) ||
	x == (ft_strlen(main->cubecopy[y]) - 1))
	{
		main->place.error = 15;
		return ;
	}
	main->cubecopy[y][x] = 'X';
	flood_fill(x + 1, y + 1, main);
	flood_fill(x - 1, y - 1, main);
	flood_fill(x + 1, y - 1, main);
	flood_fill(x - 1, y + 1, main);
	flood_fill(x, y + 1, main);
	flood_fill(x, y - 1, main);
	flood_fill(x + 1, y, main);
	flood_fill(x - 1, y, main);
}
