/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:05:50 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/03 09:14:59 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.h"

bool is_searched_font(t_igmlx_font *font, char *path)
{
	return (ft_strlen(path) == ft_strlen(font->path) && ft_strncmp(font->path, path, ft_strlen(path)) == 0);
}

t_igmlx_font *get_font(t_igmlx *igmlx, char *path)
{
	t_list *lst;

	lst = ft_lstget(igmlx->fonts, (bool (*)(void *, void *))is_searched_font, path);
	if (!lst)
		return (NULL);
	return ((t_igmlx_font *)lst->content);
}
