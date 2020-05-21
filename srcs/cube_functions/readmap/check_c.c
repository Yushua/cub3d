#include "../cube.h"

int     check_C(t_struct_m *main, char *map, int i)
{
    int r;

    r = 0;
    if (main->Double.D_C > 0)
        return (1);
    else if (main->Double.D_C == 0)
    {
        while (map[i] != '\0' || map[i] != '\n' || map[i] != NULL)
        {
            while (map[i] == ' ')
                i++;
            if (map[i] == ',')
                i++; 
            else if (map[i] >= '0' && map[i] <= '9')
            {
                i = ft_isalnummer(i, map);
                if (r == 0)
                {
                    main->place.Ccol1 = ft_atoi_cube(map, main, i);
                    i = main->place.i;
                    main->place.i = 0;
                }
                else if (r == 1)
                {
                    main->place.Ccol2 = ft_atoi_cube(map, main, i);
                    i = main->place.i;
                    main->place.i = 0;
                }
                else if (r == 2)
                {
                    main->place.Ccol3 = ft_atoi_cube(map, main, i);
                    i = main->place.i;
                    main->place.i = 0;
                    main->Double.D_C = 1;
                }
                else if (i == -1)
                {
                    main->place.error = 10;
                    ft_error(main);
                    break ;
                }
                if (r == 2)
                {
                    if (!map[i])
                    {
                        main->place.error = 10;
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