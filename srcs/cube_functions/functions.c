#include "cube.h"

void        set_value_texture(t_struct_m *main)
{
	ft_putstr(main->place.NO);
	ft_putstr("NO");
    main->texture[0].texture = mlx_xpm_file_to_image(main->vars.mlx, main->place.NO, &main->texture[0].texture_width, &main->texture[0].texture_height);
	ft_putstr(main->place.SO);
	ft_putstr("SO");
    main->texture[1].texture = mlx_xpm_file_to_image(main->vars.mlx, main->place.SO, &main->texture[1].texture_width, &main->texture[1].texture_height);
	ft_putstr(main->place.WE);
	ft_putstr("WE");
    main->texture[2].texture = mlx_xpm_file_to_image(main->vars.mlx, main->place.WE, &main->texture[2].texture_width, &main->texture[2].texture_height);
    ft_putstr(main->place.WE);
	ft_putstr("EA");
	main->texture[3].texture = mlx_xpm_file_to_image(main->vars.mlx, main->place.EA, &main->texture[3].texture_width, &main->texture[3].texture_height);
    ft_putstr(main->place.S);
	ft_putstr("S");
	main->texture[4].texture = mlx_xpm_file_to_image(main->vars.mlx, main->place.S, &main->texture[4].texture_width, &main->texture[4].texture_height);
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
	write(1, "\n", 1);
	write(1, str, i);
	write(1, "\n", 1);
}

void		printmap(t_struct_m *main)
{
	int	y = 0;

	printf("\n");
	while (y != 18)
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
