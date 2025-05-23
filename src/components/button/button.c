/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:45:44 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/07 15:13:28 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

t_igmlx_button_component *igmlx_create_button_component(t_igmlx_panel *parent)
{
	t_igmlx_button_component	*button;

	button = malloc(sizeof(t_igmlx_button_component));
	if (!button)
		return (NULL);
	ft_bzero(button, sizeof(t_igmlx_button_component));
	*button = IGMLX_BUTTON_DEFAULT;
	button->base.parent = parent;
	return (button);
}
