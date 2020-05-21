/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/05/13 21:02:25 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void            cube(t_struct_m *main)
{
    int     x;
    int     y;
    int     w;
    int     h;

    x = main->place.x;
    y = main->place.y;
    w = main->place.w;
    h = main->place.h;
    while(w != 0)
    {
        y = main->place.y; //location
        h = main->place.h; //how many times
        while (h != 0)
        {
            my_mlx_pixel_put(main->img.img, x, y, 0x00FF0000);
            y++;
            h--;
        }
        x++;
        w--;
    }
}

int 	background(t_struct_m *main)
{
	int x = 0;
	int y = 0;
    int col = 0xffffffff;

	while (y < main->place.s_height)
	{
		while (x < main->place.s_width)
		{
			my_mlx_pixel_put(main, x, y, col);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
