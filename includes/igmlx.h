/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   igmlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:03:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/03/31 11:23:00 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGMLX_H
# define IGMLX_H

# include "mlx.h"
# include "mlx_int.h"
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_mlx
{
	void								*instance;
	void								*window;
}										t_mlx;

typedef struct s_igmlx					t_igmlx;
typedef struct s_igmlx_button_component	t_igmlx_button_component;

t_igmlx									*igmlx_init(void *mlx);
void									igmlx_destroy(t_igmlx *igmlx);
int										igmlx_render(t_igmlx *igmlx, void *win);
void									igmlx_hook(t_igmlx *igmlx);
t_igmlx_button_component				*create_button(t_igmlx *igmlx,
											void *win);
void									pre_render_components(t_igmlx *igmlx);

#endif
