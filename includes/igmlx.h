/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   igmlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:03:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/28 13:58:54 by rguigneb         ###   ########.fr       */
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
typedef struct s_uvec_2					t_uvec_2;
typedef unsigned int					t_color;
typedef struct s_igmlx_button_component	t_igmlx_button_component;
typedef struct s_igmlx_font_params		t_igmlx_font_params;
typedef struct s_list					t_list;
typedef struct s_alpha_img				t_alpha_img;
typedef struct s_igmlx_panel			t_igmlx_panel;

t_igmlx									*igmlx_init(void *mlx);
void									igmlx_destroy(t_igmlx *igmlx);
int										igmlx_render(t_igmlx *igmlx, void *win);
void									igmlx_hook_to_window(t_igmlx *igmlx,
											void *win);
t_igmlx_button_component				*create_button(t_igmlx *igmlx,
											void *win);
void									pre_render_components(t_igmlx *igmlx);
void									igmlx_load_font(t_igmlx *igmlx,
											char *path,
											t_igmlx_font_params params);

void									igmlx_put_str_to_buffer(t_igmlx *igmlx,
											char *str, char *font_name,
											t_img *buffer, t_uvec_2 pos);

void									igmlx_free_alpha(t_igmlx *igmlx,
											t_alpha_img *alpha);
void									igmlx_put_alpha_to_window(t_igmlx *igmlx,
											void *win, t_alpha_img *alpha,
											t_uvec_2 pos);
t_color									igmlx_melt_colors(t_color input,
											t_color filter);
void									igmlx_apply_color_filter(t_img *img,
											t_color filter);

void									igmlx_copy_to_dest_ignore_null(t_img *origin,
											t_uvec_2 origin_pos,
											t_uvec_2 length, t_img *dest,
											t_uvec_2 dest_pos);
t_img									*igmlx_upscale_img(t_igmlx *igmlx,
											t_img *img, unsigned int factor);

t_alpha_img								*igmlx_png_to_alpha_image(t_igmlx *igmlx,
											const char *path);

void									_info(const char *msg);

void									_debug(const char *msg);

void									_warning(const char *msg);

void									_error(const char *msg);

t_igmlx_panel							*igmlx_create_panel(t_igmlx *igmlx);
#endif
