/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker        #+#    #+#                */
/*   Updated: 2020/03/12 13:04:55 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void            texture(t_struct_m *main)
{
    main->place->x = 5;
    main->place->y = 5;
    while(main->place->x != 105)
    {
        main->place->y = 5;
        while (main->place->y != 105)
        {
            my_mlx_pixel_put(main->img, main->place->x, main->place->y, 0x00FF0000);
            main->place->y++;
        }
        main->place->x++;
    }
}
