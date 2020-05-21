#include "../cube.h"

int     check_R(t_struct_m *main, char *map, int i)
{
    int r;

    r = 0;
    if (main->Double.D_R > 0)
        return (1);
    else if (main->Double.D_R == 0)
    {
        while (map[i] != '\0' || map[i] != '\n' || map[i] != NULL)
        {
            while (map[i] == ' ')
                i++;
            if (map[i] >= '1' && map[i] <= '9')
            {
                i = ft_isalnummer(i, map);
                if (r == 0)
                {
                    main->place.s_height = ft_atoi_cube(map, main, i);
                    i = main->place.i;
                    main->place.i = 0;
                }
                else if (r == 1)
                {
                    main->place.s_width = ft_atoi_cube(map, main, i);
                    i = main->place.i;
                    main->place.i = 0;
                    main->Double.D_R = 1;
                }
                else if (i == -1)
                {
                    printf("error i\n");
                    main->place.error = 3;
                    ft_error(main);
                    break ;
                }
                if (r == 1)
                {
                    if (!map[i])
                    {
                        main->place.error = 3;
                        printf("error r\n");
                        ft_error(main);
                        break ;
                    }
                    else
                        break ;
                }
                r++;
            }
        }
    }
    return (0);
}