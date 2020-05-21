        while (map[i] != '\0' || map[i] != '\n')//check if after the inputs, somthign that shouldn't be there is removed.
        {//check if there is somthing uncommmon in there, so not a 1, 0 n e w s. 
            while (map[i] == ' ')
                i++;
            if (map[i] == 'N' || map[i] == 'S' || map[i] == 'E' || map [i] == 'W')
            {

                b = ft_check_news(main, map);
                break ;
            }
            // else if (map[i] == '\0' || map[i] == '\n')
            //     break ;
            else if (map[i] != '1' || map[i] != '0')//symbols allowed in map
            {
                printf("c: [%c]\n", map[i]);
                b = 1;
                break ;
            }
            i++;
        }