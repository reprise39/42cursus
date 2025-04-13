/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 06:02:40 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/14 06:16:16 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map.h"
#include "libft.h"

void free_map(t_map *map)
{
    int i;

    if (!map)
        return;

    if (map->contents)
    {
        i = 0;
        while (i < map->map_height)
        {
            if (map->contents[i])
                free(map->contents[i]);
            i++;
        }
        free(map->contents);
    }
    free(map);
}

