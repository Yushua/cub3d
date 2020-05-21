#include "../cube.h"

static int     get_x_map(t_struct_m *main, char *map)
{
    int     x;
    int     i;
    int     b;

    x = 0;
    i = 0;
    b = 0;
    while (map[i] == ' ')
        i++;
    if (map[i] != '1')//check for start map
        b = 1;
    if (b > 0)//check if this also happens with empty lines
        return (0);
    else if (b == 0)
    {
        if (main->place.mapc == -1)
            main->place.mapc = 0;
        main->place.mapp = 0;
        while(map[x] != '\0' || map[x] != '\n')
        {
            if (map[x] == ' ')
                x++;
            else if (map[x] == '1' && main->place.mapp == 0)//check for a 1 in the loop
            {
                if (main->place.mapp == 0)
                    main->place.mapp = 1;
                ft_map_line(main, map);
                break ;
            }
            else if (map[x] == '1' && main->place.mapp == 1)
            {
                ft_map_line(main, map);
                break ;
            }  
        }
    }
    if (main->place.mapp > 2)
    {
        main->place.error = 11;
        ft_error(main);  
    }
    return (0);
}

static void     **ft_substr_save(char const *s, t_struct_m *main, int y)
{
	char	**substring;
	size_t	i;
	size_t	length;
    unsigned int start;
    size_t len;

    len = main->place.mapx;
	if (!s)
		return (0);
	main->place.cubemap[y] = NULL;
	main->place.cubemap[y] = (char *)malloc((len + 1) * sizeof(char));
	if (!main->place.cubemap[y])
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		main->place.cubemap[y][i] = (char)s[i];
		i++;
	}
	main->place.cubemap[y][i] = '\0';
}

static void        get_cubemap_x(t_struct_m *main)
{
    int count;
    int fd;
    char *map;
    count = 1;
    fd = open("./srcs/maps/mape_5.cub", O_RDONLY);
    int     y;
    main->place.mapx = 0;
    y = 0;
    while (count > 0)
    {
        count = get_next_line(fd, &map);
        get_x_map(main, map);
        if (main->place.mapc == 0)
        {
            printf("begin malloc\n");
            // main->place.mapx = main->place.mapx - main->place.mapE;//to many emty lines added
            printf("x: %d E: %d\n", main->place.mapx, main->place.mapE);
            ft_substr_save(map, main, y);
            printf("line == [%s]\n", main->place.cubemap[y]);
            y++;
        }
        printf("\n");
        free(map);
    }
}

void		space_cubemap(t_struct_m *main)
{
    int     y;
    int     x;
    int     b;
    int     i;

    i = 0;
    y = main->place.mapy;
    x = main->place.mapx;
    b = main->place.mapE;
    main->place.cubemap = (char**)malloc(sizeof(char*) * (main->place.mapy + 1));
	if (!main->place.cubemap)
    {
		main->place.error = 13;
        ft_error(main);       
    }
    get_cubemap_x(main);
}