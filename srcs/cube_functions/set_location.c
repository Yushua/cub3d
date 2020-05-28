/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/04/29 13:02:14 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	set_location(t_struct_m *main)
{
    int     r;
    int     y;
    int     x;

    r = 0;
    y = 0;
    x = 0;

    printf("hello\n");
    while (r != 1)
    {
        while (main->place.cubemap[y][x] != '\0' && r != 1)
        {
            if (main->place.cubemap[y][x] == 'E')
            {
                r = 1;
                main->Ray.dirY = 0.0;
                main->Ray.dirX = 1.0;
                main->Ray.planeX = 0.0;
                main->Ray.planeY = 0.66;
            }
            else if (main->place.cubemap[y][x] == 'W')
            {
                r = 1;
                main->Ray.dirY = 0.0;
                main->Ray.dirX = -1;
                main->Ray.planeX = 0.0;
                main->Ray.planeY = -0.66;
            }
            else if (main->place.cubemap[y][x] == 'S')
            {
                r = 1;
                main->Ray.dirY = 1.0;
                main->Ray.dirX = 0.0;
                main->Ray.planeX = -0.66;
                main->Ray.planeY = 0.0;
            }
            else if (main->place.cubemap[y][x] == 'N')
            {
                r = 1;
                main->Ray.dirY = -1;
                main->Ray.dirX = 0.0;
                main->Ray.planeX = 0.66;
                main->Ray.planeY = 0.0;
            }
            x++;
        }
        if (r == 1)
            break ;
        x = 0;
        y++;
    }
    
    main->Ray.posY = y;
    main->Ray.posX = x;
    main->Ray.posY += 0.5;
    main->Ray.posX -= 0.5;
}