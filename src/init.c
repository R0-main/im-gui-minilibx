/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:21:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/28 13:21:46 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

t_igmlx	*igmlx_init(void *mlx)
{
	t_igmlx	*igmlx;

	igmlx = malloc(sizeof(igmlx));
	ft_bzero(igmlx, sizeof(t_igmlx));
	igmlx->mlx = mlx;
	return (igmlx);
}
