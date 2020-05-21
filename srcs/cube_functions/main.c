/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/05/17 20:21:11 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

#define D 100
#define W 119
#define S 115
#define A 97
#define esc 65367

// int 	render_next_frame_cube(t_struct_m *main)
// {
// 	background(main);
//     cube(main);
// 	mlx_hook(main->vars->win, 2, 1l<<0, wasd, main);
//     cube(main);
// 	mlx_put_image_to_window(main->vars->mlx, main->vars->win, main->img->img, 0, 0);
// 	return (0);
// }

int     main(void)
{
    t_struct_m  main;

    background(&main);
    set_value(&main);
    ft_size_store_map(&main);
    readmap(&main);
    set_location(&main);
    printf("this means my other functions stil work\n");
    //map_correct(main);
    if (main.place.error == -1)
        printf("no error\n");
    // else if (main.place.error_c == 0) //don't forget to free
    //     return (0);
    printmap(&main);
    main.vars.mlx = mlx_init();
    main.vars.win = mlx_new_window(main.vars.mlx, main.place.s_width, main.place.s_height, "cube");
    main.img.img = mlx_new_image(main.vars.mlx, main.place.s_width, main.place.s_height);
    main.img.addr = mlx_get_data_addr(main.img.img, &main.img.bits_per_pixel, &main.img.line_length,
                                 &main.img.endian);
    // background(&main);
    // cube(&main);
	mlx_loop_hook(main.vars.mlx, render_next_frame, &main);
    mlx_hook(main.vars.win, 2, 1L<<0, wasd_2, &main);
    mlx_loop(main.vars.mlx);

}