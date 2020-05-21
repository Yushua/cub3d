#include "../cube.h"

void     ft_map_line(t_struct_m *main, char *map)//gets the zsize of the line
{
    int     x;

    x = 0;
    while (map[x] == '1' || map[x] == '0'|| map[x] == 'N' || map[x] == 'S' || map[x] == 'E' || map [x] == 'W' || map [x] == ' ')
    {
        if (map[x] == 'N' || map[x] == 'S' || map[x] == 'E' || map [x] == 'W')
            main->place.mapp++;
        x++;
    }
    if (x > main->place.mapx)
        main->place.mapx = x;
    main->place.mapy++;
}

int     ft_check_news(t_struct_m *main, char *map)
{
    int     x;

    x = 0;
    while (map[x] != '\0' || map[x] != '\n' || map[x] != NULL)
    {
        if (map[x] == '/' || map[x] == ',')
        {
            return (1);
        }
        x++;
    }
    return (0);
}

int     get_size_map(t_struct_m *main, char *map)
{
    int     x;
    int     i;
    int     b;

    x = 0;
    i = 0;
    b = 0;

    while (map[i] != '\0' || map[i] != '\n')
    {
        while (map[i] == ' ')
            i++;
        if (map[i] != '1')
            b = 1;
        else if (map[i] != '\0' || map[i] != '\n')
            break ;
        break ;
    }
    if (b > 0)
        return (0);
    else if (b == 0)
    {
        main->place.mapp = 0;
        while(map[x] != '\0' || map[x] != '\n')
        {
            if (map[x] == ' ')
                x++;
            if (main->place.mapE == 0 || i < main->place.mapE)
                main->place.mapE = i;
            if (map[x] == '1' && main->place.mapp == 0)
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
}

void        ft_size_store_map(t_struct_m *main)
{
    int count;
    int fd;
    char *map;
    count = 1;
    fd = open("./srcs/maps/mape_5.cub", O_RDONLY);
    while (count > 0)
    {
        count = get_next_line(fd, &map);
        get_size_map(main, map);
        free(map);
    }
    space_cubemap(main);
}
