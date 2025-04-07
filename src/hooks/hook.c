/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:13:26 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/07 14:32:17 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

void	igmlx_hook_to_window(t_igmlx *igmlx, void *win)
{
	mlx_hook(win, MotionNotify, (1L << 6),
		(int (*)())igmlx_mouse_motion_event_callback, igmlx);
	mlx_hook(win, ButtonRelease, (1L << 3),
		(int (*)())igmlx_mouse_button_released_event_callback, igmlx);
	mlx_hook(win, ButtonPress, (1L << 2),
		(int (*)())igmlx_mouse_button_pressed_event_callback, igmlx);
	_info("Hooked !");
}
