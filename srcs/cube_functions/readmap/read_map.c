#include "../cube.h"

void     ft_check(t_struct_m *main, char *map)
{
    int     i;
    int     l;

    l = 0;
    i = 0;

    while (map[i] != '\0' || map[i] != '\n')
    {
        while (map[i] == ' ')
            i++;
        if (map[i] == 'R')
        {
            i++;
            main->place.check_double = check_R(main, map, i);
            break ;
        }
        else if (map[i] == 'N')
        {
            i++;
            main->place.check_double = check_NO(main, map, i);
            break ;
        }
        else if (map[i] == 'W')
        {
            i++;
            main->place.check_double = check_WE(main, map, i);
            break ;
        }
        else if (map[i] == 'S')
        {
            i++;
            if (map[i] == 'O')
            {
                main->place.check_double = check_SO(main, map, i);
                break ;
            }
            else if (map[i] == ' ')
            {
                main->place.check_double = check_S(main, map, i);
                break ;
            }           
        }
        else if (map[i] == 'E')
        {
            i++;
            main->place.check_double = check_EA(main, map, i);
            break ;
        }
        else if (map[i] == 'F')
        {
            i++;
            main->place.check_double = check_F(main, map, i);
            break ;
        }
        else if (map[i] == 'C')
        {
            i++;
            main->place.check_double = check_C(main, map, i);
            break ;
        }
    }
}

void     read_string(t_struct_m *main, char *map)
{
    if (main->Double.D_R == 1 && main->Double.D_NO == 1 && main->Double.D_SO == 1 && main->Double.D_EA == 1 &&
        main->Double.D_S == 1 && main->Double.D_WE == 1 && main->Double.D_F == 1 && main->Double.D_C == 1)
    {
        printf("read map\n");
    }
    else
    {
        if (main->place.check_double == 0)
            ft_check(main, map);
        else if (main->place.check_double == 1)
        {
            main->place.error = 1;
            ft_error(main);
            main->place.check_double = 0;
        }
    }
    
}

void        readmap(t_struct_m *main)
{
    int count;
    int fd;
    char *map;
    count = 1;
    fd = open("./srcs/maps/mape_5.cub", O_RDONLY);
    while (count > 0)
    {
        count = get_next_line(fd, &map);
        printf("R: %d NO: %d SO: %d EA: %d S: %d WE: %d F: %d C: %d\n",
                main->Double.D_R, main->Double.D_NO, main->Double.D_SO, main->Double.D_EA,
                main->Double.D_S, main->Double.D_WE, main->Double.D_F, main->Double.D_C);
        printf("%d | %s\n", count, map);
        read_string(main, map);
        printf("--new--\n\n");
        main->place.error = 0;
        free(map);
    }
    //write function if everything is in there
    //read fail needs to give an error
}
