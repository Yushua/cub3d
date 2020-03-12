#include "cube.h"

int             close(int keycode, t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
    return (0);
}

int     main(void)
{
    t_struct_m  main;
    t_data  img;
    t_vars  vars;
    t_place  place;

    main.img = &img;
    main.vars = &vars;
    main.place = &place;
    main.vars->mlx = mlx_init();
    main.vars->win = mlx_new_window(main.vars->mlx, 1920, 1080, "Hello world!");
    main.img->img = mlx_new_image(main.vars->mlx, 1920, 1080);
    main.img->addr = mlx_get_data_addr(main.img->img, &main.img->bits_per_pixel, &main.img->line_length,
                                 &main.img->endian);
    texture(&main);
    mlx_put_image_to_window(main.vars->mlx, main.vars->win, main.img->img, 0, 0);
    // mlx_loop_hook(main.vars->mlx, render_next_frame, YourStruct);
    mlx_hook(main.vars->win, 2, 1L<<0, close, &vars);
    mlx_loop(main.vars->mlx);
}

//keyinput set
//animations