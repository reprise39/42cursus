/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:32:53 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/16 00:33:20 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_collectible(t_map *map, int y, int x)
{
	map->collectible_count_current++;
	map->contents[map->player_y][map->player_x].floor_type = EMPTY;
}

void	goal(t_data *data)
{
	data->state = GAME_CLEARED;
	ft_printf("Congratulation!! You clear the game! Please close window\n");
	return ;
}
