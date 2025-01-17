/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 00:44:16 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/29 00:47:03 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

typedef struct s_img
{
    void	*mlx_img;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
}	t_img;


int image_overlap(t_img base,t_img overlap,int x,int y)
{
	
}