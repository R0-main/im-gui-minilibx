/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:21:41 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/03 08:56:38 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

t_igmlx	*igmlx_init(void *mlx)
{
	t_igmlx	*igmlx;

	igmlx = balloc(sizeof(t_igmlx));
	if (!igmlx)
		return (NULL);
	igmlx->mlx = mlx;
	return (igmlx);
}
