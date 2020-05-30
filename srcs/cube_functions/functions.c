#include "cube.h"

void		spritesnumb(t_struct_m *main)
{
	int	y = 0;
	int	x = 0;
	while (y <= main->Ray.yy)
	{
		while (main->place.cubemap[y][x])
		{
			// ft_putstr("hello");
			if (main->place.cubemap[y][x] == '2')//place with the where yu look
			{
				main->numSprites++;
			}
			x++;
		}
		y++;
		x = 0;
	}
	main->sprites = ft_calloc(main->numSprites, sizeof(t_sprites));
    main->ZBuffer = ft_calloc(main->place.s_width, sizeof(double));
    main->spriteDistance = ft_calloc(main->numSprites, sizeof(double));
    main->spriteOrder = ft_calloc(main->numSprites, sizeof(int));
	y = 0;
	x = 0;
	int numsprites = 0;
	while (y <= main->Ray.yy)
	{
		while (main->place.cubemap[y][x] != '\0')
		{
			if (main->place.cubemap[y][x] == '2')
			{
				main->sprites[numsprites].x = (double)x + 0.5;
				main->sprites[numsprites].y = (double)y + 0.5;
				printf("[spritenumb = [%d] x == [%f] y == [%f]]\n", numsprites, main->sprites[numsprites].x, main->sprites[numsprites].y);
				numsprites++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void  swap(t_struct_m *main , int j)
{
    int     temp_order;
    double  temp_dist;
    
    temp_dist = (main->spriteDistance)[j];
    temp_order = (main->spriteOrder)[j];
    (main->spriteDistance)[j] = (main->spriteDistance)[j + 1];
    (main->spriteDistance)[j + 1] = temp_dist;
    (main->spriteOrder)[j] = (main->spriteOrder)[j + 1];
    (main->spriteOrder)[j + 1] = temp_order;
}

void        bubble_sort(t_struct_m *main)
{
    int     swapped;
    int     i;
    int     j;
    swapped = 1;
    i = 0;
    j = 0;
    while (main->numSprites - i > 1 && swapped == 1)
    {
        swapped = 0;
        j = 0;
        while (j < main->numSprites - i - 1)
        {
            if ((main->spriteDistance)[j] < (main->spriteDistance)[j + 1])
            {
                swap(main, j);
                swapped = 1;
            }
            // if ((main->ray.dir_y > 0 && main->ray.plane_y < 0 && main->ray.dir_x < 0 && main->ray.plane_x > 0) || (main->ray.dir_y > 0 && main->ray.plane_y > 0 && main->ray.dir_x < 0 && main->ray.plane_x > 0))
            // {
            //  if ((main->spriteDistance)[j] > (main->spriteDistance)[j + 1])
            // {
            //  swap(main, j);
            //  swapped = 1;
            // }
            // }
            j++;
        }
        i++;
    }
}

void        set_value_texture(t_struct_m *main)
{
    int i = 0;
	// int	x = 0;
	// int	y = 0;
	// main->texture = malloc(5 * sizeof (t_texture));
	// while (y <= 5)
	// {
	// 	main->texture->buffer[y] = malloc(main->place.s_width * sizeof(unsigned int));
	// 	while (i <= main->place.s_width)
	// 	{
	// 		main->texture->buffer[y][i] = malloc(main->place.s_height * sizeof(unsigned int));
	// 		i++;
	// 	}
	// 	y++;
	// }

    ft_putstr(main->place.NO);
    ft_putstr("NO");
	// if (mlx_xpm_file_to_image(main->vars.mlx, "./textures/wall_2.xm", &(main->texture[0].texture_width), &(main->texture[0].texture_height)) == NULL)
	// 	ft_putstr("hello");
	// int len = ft_strlen("greystone.xpm");
	// char *str = (char *)malloc((len + 1) * sizeof(char));
	int fd = open("srcs/cube_functions/textures/greenlight.xpm", O_RDONLY);//use to chekc if file is valid
	printf("fd == %d\n", fd);
    main->texture[0].texture = mlx_xpm_file_to_image(main->vars.mlx, "srcs/cube_functions/textures/wall_1.xpm", &(main->texture[0].texture_width), &(main->texture[0].texture_height));
	printf("NO width == [%d] height == [%d]\n",main->texture[0].texture_width, main->texture[0].texture_height);
    i++;
    ft_putstr(main->place.SO);
    ft_putstr("SO");
    main->texture[1].texture = mlx_xpm_file_to_image(main->vars.mlx, "srcs/cube_functions/textures/wall_4.xpm", &(main->texture[1].texture_width), &(main->texture[1].texture_height));
    printf("width == [%d] height == [%d]\n",main->texture[1].texture_width, main->texture[1].texture_height);
    i++;
    ft_putstr(main->place.WE);
    ft_putstr("WE");
    main->texture[2].texture = mlx_xpm_file_to_image(main->vars.mlx, "srcs/cube_functions/textures/wall_2.xpm", &(main->texture[2].texture_width), &(main->texture[2].texture_height));
    printf("width == [%d] height == [%d]\n",main->texture[2].texture_width, main->texture[2].texture_height);
    i++;
    ft_putstr(main->place.WE);
    ft_putstr("EA");
    main->texture[3].texture = mlx_xpm_file_to_image(main->vars.mlx, "srcs/cube_functions/textures/wall_3.xpm", &(main->texture[3].texture_width), &(main->texture[3].texture_height));
    printf("width == [%d] height == [%d]\n",main->texture[3].texture_width, main->texture[3].texture_height);
    i++;
    ft_putstr(main->place.S);
    ft_putstr("S");
    main->texture[4].texture = mlx_xpm_file_to_image(main->vars.mlx, "srcs/cube_functions/textures/greystone.xpm", &main->texture[4].texture_width, &main->texture[4].texture_height);
    printf("width == [%d] height == [%d]\n",main->texture[4].texture_width, main->texture[4].texture_height);
	if (main->texture[0].texture == NULL || main->texture[1].texture == NULL || main->texture[2].texture == NULL || main->texture[3].texture == NULL || main->texture[4].texture == NULL)
	{
		main->place.error_c == 14;
		ft_error(main);
	}
    main->texture[0].texture_adress = (int *)(mlx_get_data_addr(main->texture[0].texture, &main->texture[0].bits_per_pixel, &main->texture[0].line_lenght, &main->texture[0].endian));
    main->texture[1].texture_adress = (int *)(mlx_get_data_addr(main->texture[1].texture, &main->texture[1].bits_per_pixel, &main->texture[1].line_lenght, &main->texture[1].endian));
    main->texture[2].texture_adress = (int *)(mlx_get_data_addr(main->texture[2].texture, &main->texture[2].bits_per_pixel, &main->texture[2].line_lenght, &main->texture[2].endian));
    main->texture[3].texture_adress = (int *)(mlx_get_data_addr(main->texture[3].texture, &main->texture[3].bits_per_pixel, &main->texture[3].line_lenght, &main->texture[3].endian));
    main->texture[4].texture_adress = (int *)(mlx_get_data_addr(main->texture[4].texture, &main->texture[4].bits_per_pixel, &main->texture[4].line_lenght, &main->texture[4].endian));
}

int		ft_atoi_cube(char *str, t_struct_m *main, int i)
{
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
    main->place.i = i;
	return (res);
}

int	ft_isalnummer(int i, char *str)	//check if everything is a number
{
	int y;

	y = i;
	while (str[i] != '\n' || str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			return (y);
		}
		else
			return (-1);
	}
}

int	ft_strlenght(char *s)
{
	int i;

	i = 0;
	while (s[i] != ' ')
		i += 1;
	return (i);
}

int			ft_strleng(char *str, int i)
{
	int		r;

	r = 0;
	while (str[i])
	{
		r++;
		i++;
	}
	return (r);
}

char		*ft_cp_string(char *str, int i, int lenght)
{
	int 	j;
	char 	*copy;

	j = 0;
	copy = NULL;
	copy = (char *)malloc((lenght + 1) * sizeof(char));
	//don't forget error check
	printf("[copy] [str]\n");
	while (j < lenght)
	{
		printf("[%c] [%c] [%d]\n", copy[j], str[i], j);
		copy[j] = str[i];
		j++;
		i++;
	}
	copy[j] == '\0';
	return (copy);
}

void ft_putstr(char *str)
{
	int i;

	i = ft_strlen(str);
	write(1, str, i);
	write(1, "\n", 1);
}

void		printmap(t_struct_m *main)
{
	int	y = 0;

	printf("\n");
	while (y <= main->Ray.yy)
	{
		printf("[%s]\n", main->place.cubemap[y]);
		y++;
	}
	printf("end\n");
}

int		create_trgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}
