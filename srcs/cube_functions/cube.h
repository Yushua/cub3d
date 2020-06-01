#ifndef CUBE_H
# define CUBE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include "../mlx/mlx.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

#define ESC 65307
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100

#define texWidth 64
#define texHeight 64

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
	int         x;
	int         y;
}               t_data;

typedef struct  s_vars {
		void    *mlx;
		void    *win;
}               t_vars;

typedef struct  s_place {
	int			x;
	int			y;
	int			w;
	int			h;
	int			col;

	int			s_width;
	int			s_height;
	int			dir;
	char		*NO;
	char		*SO;
	char		*EA;
	char		*S;
	char		*WE;

	int			i;

	int			Fcol1;
	int			Fcol2;
	int			Fcol3;
	
	int			Ccol1;
	int			Ccol2;
	int			Ccol3;

	int			error;
	int			error_c;
	int			error_n;

	int			check_double;

	char		**cubemap;

	//map size
	int			mapx;
	int			mapy;
	int			mapp;
	int			mapE;//e = for empty
	int			mapc;

	//moves_bonus
	int			crouch;
}               t_place;

typedef struct  s_Double {
	int			D_R;
	int			D_NO;
	int			D_SO;
	int			D_EA;	
	int			D_S;
	int			D_WE;

	int			D_F;
	int			D_C;
}    			t_Double;

typedef struct  s_Ray {

	double		posX;//position times 10
	double		posY;//put in double

	double		dirX;//direction
	double		dirY;

	double		planeX;
	double		planeY;


	double 		cameraX;
	double 		rayDirX;
	double 		rayDirY;
	  
	//if in the box
	int 		mapX;
	int			mapY;

	//lenght of the ray
	double		sideDistX;
	double		sideDistY;

	//lenght of ray from one x or y side to the enxt x or y side
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;

	int			stepX;
	int			stepY;

	int			hit;
	int			side;

	int			h;
	int			x;
	int			yy;
	int			lineHeight;

	int			drawStart;
	int			drawEnd;
	
	int 		texNum;
	double 		wallX;
	int 		texX;
	int			texY;

	double 		step;
	double 		texPos;
}    			t_Ray;

typedef struct  s_texture {
	unsigned int 	buffer[1200][800];
	void			*texture;
	int				*texture_adress;

	int				line_lenght;
	int				bits_per_pixel;
	int				texture_width;
	int				texture_height;
	int				endian;

}               t_texture;

typedef struct  s_sprite {

	double		spritex;
	double		spritey;
	double 		invDet;

	double		transformX;
	double		transformY;

	int			spriteScreenX;
	int			vMoveScreen;

	int 		spriteHeight;

	int			drawStartY;
	int			drawendY;
	int			drawStartX;
	int			drawendX;

	int			spriteWidth;
	int			stripe;

	double		first;
	int			second;

	int			begin;
	int			end;
}               t_sprite;

typedef struct  s_sprites {

	double		x;
	double		y;

}               t_sprites;

typedef struct  s_struct_m {
	t_data		img;
	t_vars		vars;
	t_place		place;
	t_Double	Double;
	t_Ray		Ray;
	t_texture	texture[5];
	t_sprite	sprite;
	t_sprites	*sprites;

	//sprites
	int			numSprites;//don't foget to malloc them AFTER you know the numSprites
	double 		*ZBuffer;
	int 		*spriteOrder;
	double 		*spriteDistance;
}               t_struct_m;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color);
int             wasd(int keycode, t_struct_m *main);

void            cube(t_struct_m *main);
int 	        background(t_struct_m *main);

void            readmap(t_struct_m *main);
void     		read_string(t_struct_m *main, char *map);
void     		ft_check(t_struct_m *main, char *map);

int     		check_R(t_struct_m *main, char *map, int i);
int     		check_NO(t_struct_m *main, char *map, int i);
int     		check_SO(t_struct_m *main, char *map, int i);
int     		check_S(t_struct_m *main, char *map, int i);
int     		check_WE(t_struct_m *main, char *map, int i);
int     		check_EA(t_struct_m *main, char *map, int i);
int     		check_F(t_struct_m *main, char *map, int i);
int     		check_C(t_struct_m *main, char *map, int i);
void			set_value(t_struct_m *main);

void       		ft_error(t_struct_m *main);

//read the map

void        	ft_size_store_map(t_struct_m *main);
int     		get_size_map(t_struct_m *main, char *map);
void     		ft_map_line(t_struct_m *main, char *map);
int     		ft_check_news(t_struct_m *main, char *map);
void			set_location(t_struct_m *main);

//functions

int				ft_atoi_cube(char *str, t_struct_m *main, int i);
int				ft_isalnummer(int i, char *str);
int				ft_strlenght(char *s);
int				ft_strleng(char *str, int i);
char			*ft_cp_string(char *str, int i, int lenght);
void 			ft_putchar(char *str);
void 			ft_putstr(char *str);
void			space_cubemap(t_struct_m *main);
// int				ft_strlen_cube(const char *s);

//raycasting

int 	        render_next_frame(t_struct_m *main);
int             wasd_2(int keycode, t_struct_m *main);
void    		verLine(int x, int  drawStart, int  drawEnd, int col, t_struct_m *main);
int				create_trgb(int r, int g, int b);

void			printmap(t_struct_m *main);
int 			render_next_frame_structure(t_struct_m *main);
void    		verLine_texture(int x, t_struct_m *main);
void        	set_value_texture(t_struct_m *main);
void    		verLine_structure(t_struct_m *main);

int         	render_next_frame_sprites(t_struct_m *main);
int        		render_next_frame_sprites_copy(t_struct_m *main);

void			spritesnumb(t_struct_m *main);
void        	swap(t_struct_m *main , int j);
void        	bubble_sort(t_struct_m *main);
#endif