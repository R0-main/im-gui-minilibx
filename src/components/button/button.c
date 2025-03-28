/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:45:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/28 16:15:19 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

t_igmlx_button_component *create_button(t_igmlx *igmlx, void *win)
{
	t_igmlx_button_component *button;

	button = malloc(sizeof(t_igmlx_button_component));
	if (!button)
		return (NULL);
	ft_bzero(button, sizeof(t_igmlx_button_component));
	*button = IGMLX_BUTTON_DEFAULT;
	button->base.win = win;
	add_to_window_data(igmlx, win, button);
	return (button);
}
