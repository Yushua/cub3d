/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/05/13 20:54:40 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    verLine(int x, int  drawStart, int  drawEnd, int col, t_struct_m *main)
{
    int h   = main->place.s_height / 2;
    int i   = 0;
    int     colour;

    colour = create_trgb(main->place.Fcol1, main->place.Fcol2, main->place.Fcol3);//floor
    while (i != h)
    {
        my_mlx_pixel_put(main, x, i, colour);
        i++;
    }
    colour = create_trgb(main->place.Ccol1, main->place.Ccol2, main->place.Ccol3);//cealing
    while (i != main->place.s_height)
    {
        my_mlx_pixel_put(main, x, i, colour);
        i++;
    }
    if (main->Ray.side == 0)
    {
        if(main->Ray.posX > main->Ray.mapX)//N
            col = 0xFFE771;
        if(main->Ray.posX < main->Ray.mapX)//S
            col = 0xE86A4F;
    }
    if (main->Ray.side == 1)
    {
        if(main->Ray.posY > main->Ray.mapY)
            col = 0xA963FF;//left
        if(main->Ray.posY < main->Ray.mapY)
            col = 0x4FE0E8;//right
    }
	while (drawStart < drawEnd)
	{
		my_mlx_pixel_put(main, x, drawStart, col);
		drawStart++;
	}
}

int 	render_next_frame(t_struct_m *main)
{
    main->Ray.x = 0;

    //w = main->place.s_width

    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame
    while (main->Ray.x < main->place.s_width)
    {
        main->Ray.cameraX = 2 * main->Ray.x / (double)main->place.s_width - 1;//x-coordinate in camera space
        main->Ray.rayDirX = main->Ray.dirX + main->Ray.planeX * main->Ray.cameraX;
        main->Ray.rayDirY = main->Ray.dirY + main->Ray.planeY * main->Ray.cameraX;

        main->Ray.mapX = (int)main->Ray.posX;
	    main->Ray.mapY = (int)main->Ray.posY;

        main->Ray.hit = 0;
        
        //length of ray from one x or y-side to next x or y-side
        main->Ray.deltaDistX = (main->Ray.rayDirY == 0) ? 0 : ((main->Ray.rayDirX == 0) ? 1 : fabs(1 / main->Ray.rayDirX));
        main->Ray.deltaDistY = (main->Ray.rayDirX == 0) ? 0 : ((main->Ray.rayDirY == 0) ? 1 : fabs(1 / main->Ray.rayDirY));
        //calculate step and initial sideDist
        if (main->Ray.rayDirX < 0)
        {
            main->Ray.stepX = -1;
            main->Ray.sideDistX = (main->Ray.posX - main->Ray.mapX) * main->Ray.deltaDistX;
        }
        else
        {
            main->Ray.stepX = 1;
            main->Ray.sideDistX = (main->Ray.mapX + 1.0 - main->Ray.posX) * main->Ray.deltaDistX;
        }
        if (main->Ray.rayDirY < 0)
        {
            main->Ray.stepY = -1;
            main->Ray.sideDistY = (main->Ray.posY - main->Ray.mapY) * main->Ray.deltaDistY;
        }
        else
        {
            main->Ray.stepY = 1;
            main->Ray.sideDistY = (main->Ray.mapY + 1.0 - main->Ray.posY) * main->Ray.deltaDistY;
        }
        //perform DDA
        while (main->Ray.hit == 0)
        {
            //jump to next map square, OR in x-direction, OR in y-direction
            if (main->Ray.sideDistX < main->Ray.sideDistY)
            {
                main->Ray.sideDistX += main->Ray.deltaDistX;
                main->Ray.mapX += main->Ray.stepX;
                main->Ray.side = 0;
            }
            else
            {
                main->Ray.sideDistY += main->Ray.deltaDistY;
                main->Ray.mapY += main->Ray.stepY;
                main->Ray.side = 1;
            }
            //Check if ray has hit a wall
            if (main->place.cubemap[main->Ray.mapY][main->Ray.mapX] == '1')//collision
                main->Ray.hit = 1;
        }
        //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
        if (main->Ray.side == 0)
            main->Ray.perpWallDist = ((main->Ray.mapX - main->Ray.posX + (1 - main->Ray.stepX) / 2) / main->Ray.rayDirX);
        else
            main->Ray.perpWallDist = ((main->Ray.mapY - main->Ray.posY + (1 - main->Ray.stepY) / 2) / main->Ray.rayDirY);
        //Calculate height of line to draw on screen

        int lineHeight = (int)(main->place.s_height / main->Ray.perpWallDist);

        //calculate lowest and highest pixel to fill in current stripe
        int drawStart = (-lineHeight / 2 + main->place.s_height / 2);
        if(drawStart < 0)
            drawStart = 0;
        int drawEnd = (lineHeight / 2 + main->place.s_height / 2);
        if(drawEnd >= main->place.s_height)
            drawEnd = main->place.s_height - 1;
        if (main->Ray.x == 300)
            printf(" side == [%d]\n x == [%d]\n Mapx == [%d]\n MapY == [%d]\n posX == [%f]\n posY == [%f]\n\n", main->Ray.side, main->Ray.x, main->Ray.mapX, main->Ray.mapY, main->Ray.posX, main->Ray.posY);
        else
            verLine(main->Ray.x, drawStart, drawEnd, main->place.col, main);
        main->Ray.x++;
    }
	mlx_put_image_to_window(main->vars.mlx, main->vars.win, main->img.img, 0, 0);
	return (0);
}
