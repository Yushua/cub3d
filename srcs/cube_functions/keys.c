#include "cube.h"

#define D 65363
#define A 65361
#define W 65362
#define S 65364
#define esc 65307

// int             wasd(int keycode, t_struct_m *main)
// {
//     int x = main->place.x;
//     int y = main->place.y;

// 	printf("%d, X:%d, Y:%d\n", keycode, x, y);
// 	if (keycode == A || keycode == 97)
// 		main->place.x-=20;
// 	else if ((keycode == D || keycode == 100) && main->place.x != 0)
// 		main->place.x+=20;
// 	else if ((keycode == W || keycode == 119))
// 		main->place.y-=20;
// 	else if ((keycode == S || keycode == 115) && main->place.y <= 0)
// 		main->place.y+=20;
// 	if ((keycode == esc || keycode == 65307))
// 	{
// 		mlx_destroy_window(main->vars->mlx, main->vars->win);
// 		exit(0);
// 	}
// 	background(main);
//     cube(main);
// 	mlx_put_image_to_window(main->vars->mlx, main->vars->win, main->img->img, 0, 0);
// 	return (0);
// }


int             wasd_2(int keycode, t_struct_m *main)
{
	double moveSpeed = 0.1;
	double rotSpeed = 0.1;
    printf("keycode == %d\n", keycode);
    if (keycode > 0)
        background(main);
    if (keycode == W || keycode == 119)
    {
        if(main->place.cubemap[(int)(main->Ray.posY)][(int)(main->Ray.posX + main->Ray.dirX * moveSpeed)] != '1')
            main->Ray.posX += main->Ray.dirX * moveSpeed;
        if(main->place.cubemap[(int)(main->Ray.posY + main->Ray.dirY * moveSpeed)][(int)(main->Ray.posX)] != '1')
            main->Ray.posY += main->Ray.dirY * moveSpeed;
    }
    else if (keycode == S || keycode == 115)
    {
        if(main->place.cubemap[(int)(main->Ray.posY)][(int)(main->Ray.posX - main->Ray.dirX * moveSpeed)] != '1')
            main->Ray.posX -= main->Ray.dirX * moveSpeed;
        if(main->place.cubemap[(int)(main->Ray.posY - main->Ray.dirY * moveSpeed)][(int)(main->Ray.posX)] != '1')
            main->Ray.posY -= main->Ray.dirY * moveSpeed;        
    }
    else if (keycode == D || keycode == 100)
    {
        //both camera direction and camera plane must be rotated
        double olddirx = main->Ray.dirX;

        main->Ray.dirX = main->Ray.dirX * cos(-rotSpeed) - main->Ray.dirY * sin(-rotSpeed);
        main->Ray.dirY = olddirx * sin(-rotSpeed) + main->Ray.dirY * cos(-rotSpeed);

        double oldplanex = main->Ray.planeX;
                            
        main->Ray.planeX = main->Ray.planeX * cos(-rotSpeed) - main->Ray.planeY * sin(-rotSpeed);
        main->Ray.planeY = oldplanex * sin(-rotSpeed) + main->Ray.planeY * cos(-rotSpeed);        
    }
    else if (keycode == A || keycode == 97)
    {
        double oldDirX = main->Ray.dirX;

        main->Ray.dirX = main->Ray.dirX * cos(rotSpeed) - main->Ray.dirY * sin(rotSpeed);
        main->Ray.dirY = oldDirX * sin(rotSpeed) + main->Ray.dirY * cos(rotSpeed);

        double oldplanex = main->Ray.planeX;
                            
        main->Ray.planeX = main->Ray.planeX * cos(rotSpeed) - main->Ray.planeY * sin(rotSpeed);
        main->Ray.planeY = oldplanex * sin(rotSpeed) + main->Ray.planeY * cos(rotSpeed);        
    }
    if (keycode == esc || keycode == 65307)
    {
        mlx_destroy_window(main->vars.mlx, main->vars.win);
        exit(0);
    }
    return (0);
}