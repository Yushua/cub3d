#ifndef CUBE_H
# define CUBE_H

#include <stdio.h>
#include <stdlib.h>
#include "srcs/minilibx/mlx.h"

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int          x;
    int          y;
}               t_data;

typedef struct  s_vars {
        void    *mlx;
        void    *win;
}               t_vars;

typedef struct  s_place {
    int     x;
    int     y;
}               t_place;

typedef struct  s_struct_m {
    t_data  *img;
    t_vars  *vars;
    t_place  *place;
}               t_struct_m;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color);
int             close(int keycode, t_vars *vars);

void            texture(t_struct_m *main);
#endif