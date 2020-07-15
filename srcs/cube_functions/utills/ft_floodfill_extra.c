/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_floodfill_extra.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:05:44 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/03 11:43:54 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static void			if_x(int x, int y, t_struct_m *main)
{
	int yy;

	yy = y;
	if (y < 0 || x < 0 || y == main->ray.yy || x >= main->ray.xx)
		yy = y;
	else if (main->cubecopy[y][x] == '0' || main->cubecopy[y][x] == '2')
		main->cubecopy[y][x] = 'X';
}

static void			ft_place_x(t_struct_m *main, int x, int y)
{
	if_x(x - 1, y, main);
	if_x(x + 1, y, main);
	if_x(x, y - 1, main);
	if_x(x, y + 1, main);
}

void				ft_floodfill_extra(t_struct_m *main)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < main->ray.yy)
	{
		while (main->cubecopy[y][x] != '\0')
		{
			if (main->cubecopy[y][x] == 'X')
				ft_place_x(main, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
