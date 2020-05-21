#include "../cube.h"

int     check_WE(t_struct_m *main, char *map, int i)
{
    int     r;

    r = 0;
    if (main->Double.D_WE > 0)
        return (1);
    else if (main->Double.D_WE == 0)
    {
        if (map[i] != 'E')
        {
            main->place.error = 7;
            ft_error(main);
            return (0);      
        }
        main->Double.D_WE = 1;
        i++;
        while (map[i] == ' ')
            i++;
        if (map[i] != ' ')
        {
            r = ft_strleng(map, i);
            main->place.WE = ft_substr(map, i, r);
            i = i + r;
        }
        if (map[i] != '\0')
        {
            main->place.error = 5;
            ft_error(main);    
        }
    }
    return (0);
}