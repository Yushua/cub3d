#include "../cube.h"

int     check_S(t_struct_m *main, char *map, int i)
{
    int     r;

    r = 0;
    if (main->Double.D_S > 0)
        return (1);
    else if (main->Double.D_S == 0)
    {
        main->Double.D_S = 1;
        i++;
        while (map[i] == ' ')
            i++;
        if (map[i] != ' ')
        {
            r = ft_strleng(map, i);
            main->place.S = ft_substr(map, i, r);
            i = i + r;
        }
        if (map[i] != '\0')
        {
            main->place.error = 4;
            ft_error(main);    
        }
    }
    return (0);
}