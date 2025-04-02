/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:13:26 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/02 12:10:13 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void	hook_each_windows(t_igmlx *igmlx)
{
	t_list	*current;

	current = igmlx->wins_data;
	while (current)
	{
		mlx_hook(((t_win_data *)current->content)->win, MotionNotify, (1L<<6),//(1L << 8),
			(int (*)())mouse_motion, igmlx);
		mlx_hook(((t_win_data *)current->content)->win, ButtonRelease,
			(1L << 3), (int (*)())release_mouse, igmlx);
		mlx_hook(((t_win_data *)current->content)->win, ButtonPress, (1L << 2),
			(int (*)())press_mouse, igmlx);
		current = current->next;
	}
}

void	igmlx_hook(t_igmlx *igmlx)
{
	hook_each_windows(igmlx);
	// mlx_loop_hook(igmlx->mlx, igmlx_loop, igmlx);
	_info("Hooked !");
}
