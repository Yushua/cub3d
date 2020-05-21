/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_map.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/04/22 11:37:57 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


void     ft_map_line(t_struct_m *main, char *map)//gets the zsize of the line
{
    int     x;

    x = 0;
    while (map[x] == '1' || map[x] == '0'|| map[x] == 'N' || map[x] == 'S' || map[x] == 'E' || map [x] == 'W' || map [x] == ' ')
    {
        if (map[x] == 'N' || map[x] == 'S' || map[x] == 'E' || map [x] == 'W' || map[x] == '2'|| map[x] == '3')
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
    //first check if there is anything uncommon in there, if so, skip line
    //second check if the line starts
    while (map[i] != '\0' || map[i] != '\n')//check if after the inputs, somthign that shouldn't be there is removed.
    {//check if there is somthing uncommmon in there, so not a 1, 0 n e w s. 
        while (map[i] == ' ')
            i++;
        if (i > main->place.mapE)
            main->place.mapE = i;
        if (map[i] != '1')//check for start map
            b = 1;
        else if (map[i] != '\0' || map[i] != '\n') //check for end of line
            break ;
        break ;
    }
    if (b > 0)//check if this also happens with empty lines
        return (0);
    else if (b == 0)
    {
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
}

void        ft_size_store_map(t_struct_m *main)
{
    int count;
    int fd;
    char *map;
    count = 1;
    fd = open("./srcs/maps/mape_4.cub", O_RDONLY);
    while (count > 0)
    {
        count = get_next_line(fd, &map);
        // printf("|%s|\n",map);
        get_size_map(main, map);
        // printf("x: %d y: %d\n\n", main->place.mapx, main->place.mapy);
        main->place.error = 0;
        free(map);
        printf("%d/n", main->place.mapE);
    }
    printf("%d/n", main->place.mapE);
    printf("hellox: %d y: %d E: %d\n\n", main->place.mapx, main->place.mapy, main->place.mapE);
    //make room
    
    //do this agian but now save it
    //write function if everything is in there
    //read fail needs to give an error
}
