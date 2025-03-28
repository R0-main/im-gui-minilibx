/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:13:26 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/28 15:31:25 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void		igmlx_hook(t_igmlx *igmlx)
{
	_log(IGMLX_LOG_INFO, "Hooking...");
	(void)igmlx;
	// mlx_loop_hook(igmlx->mlx, igmlx_loop, igmlx);
	_log(IGMLX_LOG_INFO, "Hooked !");
}
