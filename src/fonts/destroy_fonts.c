/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_fonts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:57:27 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/28 13:42:26 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

static void free_font(t_igmlx *igmlx, t_igmlx_font *font)
{
	char c;

	c = 0;
	while (c < CHAR_MAX)
		mlx_destroy_image(igmlx, font->letters[(int)c++]);
	free(font);
}

void igmlx_destroy_fonts_list(t_igmlx *igmlx, t_list **fonts)
{
	t_list	*current;
	t_list	*tmp;

	if (!fonts)
		return ;
	current = *fonts;
	while (current)
	{
		tmp = current->next;
		if (current->content)
			free_font(igmlx, current->content);
		free(current);
		current = tmp;
	}
}
