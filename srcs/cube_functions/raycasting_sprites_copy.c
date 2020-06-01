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

int         render_next_frame_sprites_copy(t_struct_m *main)
{
	int i = 0;
	//function used to sort the sprites
	// void sortSprites(int* order, double* dist, int amount);

	//print sprites
	while (i < main->numSprites)
	{
		main->spriteOrder[i] = i;
		main->spriteDistance[i] = ((main->Ray.posX - main->sprites[i].x) * (main->Ray.posX - main->sprites[i].x) + (main->Ray.posY - main->sprites[i].y) * (main->Ray.posY - main->sprites[i].y));
		i++;
	}
	bubble_sort(main);

	// sortSprites(main, main->spriteOrder, main->spriteDistance, main->numSprites);

	i = 0;
	while (i < main->numSprites)
	{
		double spritex = main->sprites[main->spriteOrder[i]].x - main->Ray.posX;
		double spritey = main->sprites[main->spriteOrder[i]].y - main->Ray.posY;

		//transform sprite with the inverse camera matrix
		// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
		// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
		// [ planeY   dirY ]                                          [ -planeY  planeX ]

		double invDet = 1.0 / (main->Ray.planeX * main->Ray.dirY - main->Ray.dirX * main->Ray.planeY);

		double transformX = invDet * (main->Ray.dirY * spritex - main->Ray.dirX * spritey);
		double transformY = invDet * (-main->Ray.planeY * spritex + main->Ray.planeX * spritey);

		int spriteScreenX = (int)((main->place.s_width / 2) * (1 + transformX / transformY));
		
		//parameters for scaling and moving the sprites
		#define uDiv 1
		#define vDiv 1
		#define vMove 0.0

		// main->sprite.vMoveScreen = (int)(vMove / transformY);

		//calculate height of the sprite on screen

		int spriteHeight = abs((int)(main->place.s_height / (transformY)));//using "transformY" instead of the real distance prevents fisheye

		//calculate lowest and highest pixel to fill in current stripe
		int drawStartY = -spriteHeight / 2 + main->place.s_height / 2;
		if (drawStartY < 0)
			drawStartY = 0;
		int drawendY = spriteHeight / 2 + main->place.s_height / 2;
		if (drawendY >= main->place.s_height)
			drawendY = main->place.s_height - 1;

		//calculate width of the sprite
		int spriteWidth = abs((int)(main->place.s_height / (transformY)));
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if (drawStartX < 0)
			drawStartX = 0;
		int drawendX = spriteWidth / 2 + spriteScreenX;
		if (drawendX >= main->place.s_width)
			drawendX = main->place.s_width - 1;

		int stripe = drawStartX;
		int		y;
		int		d;
		int		texY;
		int		colour;
		int		texX;
		// printf("transformy == [%f]\n stripe == [%d]\n zbuffer == [%f]\n",transformY, stripe, main->ZBuffer[stripe]);
		while (stripe < drawendX)
		{
			texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * main->texture->texture_width / spriteWidth) / 256;
			if (transformY > 0 && stripe > 0 && stripe < main->place.s_width && transformY < main->ZBuffer[stripe])
			{
				y = drawStartY;
				while (y < drawendY)
				{
					d = (y) * 256 - main->place.s_height * 128 + spriteHeight * 128;
					texY = ((d * main->texture[4].texture_height) / spriteHeight) / 256;
					colour	= main->texture[4].texture_adress[main->texture[4].texture_width * texY + texX];
					printf("x == [%d] y == [%d] colour == [%d] ", stripe, y, colour);
					my_mlx_pixel_put(main, stripe, y, colour);
					printf("\n");
					y++;
				}
			}
			stripe++;
		}
		i++;
	}
}