/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:03:54 by rguigneb          #+#    #+#             */
/*   Updated: 2025/04/08 15:16:28 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include "colors.h"
# include "ft_fprintf.h"
# include "igmlx.h"
# include "libft.h"
# include "limits.h"
# include "timer.h"

# define IGMLX_LOG_PREFIX "IGMLX"

# define IGMLX_BUTTON_DEFAULT                                                 \
	(t_igmlx_button_component)                                               \
	{                                                                        \
		(t_igmlx_component){IGMLX_COMPONENT_BUTTON,                          \
							false,                                           \
							(t_uvec_2){50, 50},                              \
							(t_uvec_2){50, 50},                              \
							(t_timer){500, (t_time){0}, (t_time){0}, false}, \
							IGMLX_STATE_DEFAULT,                             \
							IGMLX_STATE_DEFAULT,                             \
							{                                                \
								{                                            \
									(t_color)0xFFFFFF,                       \
									(t_color)0xFF00FF,                       \
									1,                                       \
									1,                                       \
									{0, 0, 0, 0},                            \
									NULL,                                    \
								},                                           \
								{                                            \
									(t_color)0xFFFFFF,                       \
									(t_color)0xFF00FF,                       \
									1,                                       \
									1,                                       \
									{0, 0, 0, 0},                            \
									NULL,                                    \
								},                                           \
								{                                            \
									(t_color)0xFFFFFF,                       \
									(t_color)0xFF00FF,                       \
									1,                                       \
									1,                                       \
									{0, 0, 0, 0},                            \
									NULL,                                    \
								},                                           \
							},                                               \
							NULL},                                           \
			150, NULL, NULL, NULL, NULL, NULL                                \
	}

typedef unsigned int			t_color;

typedef struct s_uvec_2
{
	unsigned int				x;
	unsigned int				y;
}								t_uvec_2;

typedef struct s_rectangle
{
	t_uvec_2					pos;
	t_uvec_2					length;
	int							area;
}								t_rectangle;

typedef enum e_igmlx_state
{
	IGMLX_STATE_DEFAULT,
	IGMLX_STATE_HOVERED,
	IGMLX_STATE_PRESSED,

	IGMLX_STATE_COUNT
}								t_e_igmlx_state;

typedef enum e_igmlx_corner
{
	IGMLX_CORNER_TOP_LEFT,
	IGMLX_CORNER_BOTTOM_LEFT,
	IGMLX_CORNER_TOP_RIGHT,
	IGMLX_CORNER_BOTTOM_RIGHT,

	IGMLX_CORNER_COUNT
}								t_e_igmlx_corner;

typedef enum e_igmlx_log_level
{
	IGMLX_LOG_DEBUG,
	IGMLX_LOG_INFO,
	IGMLX_LOG_WARNING,
	IGMLX_LOG_ERROR
}								t_e_igmlx_log_level;

typedef enum e_igmlx_component_type
{
	IGMLX_COMPONENT_PANEL,
	IGMLX_COMPONENT_BUTTON,
}								t_e_igmlx_component_type;

typedef struct s_img_block
{
	t_img						*img;
	t_uvec_2					offset;
}								t_img_block;

typedef struct s_alpha_img
{
	t_list						*blocks;
}								t_alpha_img;

typedef struct s_igmlx_font
{
	t_alpha_img					*letters[CHAR_MAX];
	char						*path;
	t_color						color;
	unsigned int				size_mutliplier;
	t_uvec_2					length;
	t_uvec_2					inner_offset;
}								t_igmlx_font;

typedef struct s_igmlx_font_params
{
	t_color						color;
	unsigned int				size_multiplier;
	t_uvec_2					inner_offset;
}								t_igmlx_font_params;

typedef struct s_igmlx_component_state
{
	t_color						backgroud_color;
	t_color						text_color;
	int							size_mutliplier;
	int							opacity;
	unsigned int				borders_radius[IGMLX_CORNER_COUNT];
	t_img						*render;
}								t_igmlx_component_state;

typedef struct s_igmlx_component
{
	t_e_igmlx_component_type	type;
	bool						rendered;
	t_uvec_2					collision_box;
	t_uvec_2					pos;
	t_timer						last_change_state_timer;
	t_e_igmlx_state				last_state;
	t_e_igmlx_state				state;
	t_igmlx_component_state		states[IGMLX_STATE_COUNT];
	t_igmlx_panel				*parent;
}								t_igmlx_component;

typedef struct s_igmlx_default_component
{
	t_igmlx_component			base;
}								t_igmlx_default_component;

typedef struct s_igmlx_button_component
{
	t_igmlx_component			base;
	int							delay;
	void						*data;
	void						(*press)(void *);
	void						(*touch)(void *);
	void						(*leave)(void *);
	void						(*hover)(void *);
}								t_igmlx_button_component;

typedef struct s_win_data
{
	void						*win;
	t_list						*components;
}								t_win_data;

typedef struct s_igmlx_callback_function
{
	void						(*func)(void *);
	void						*data;
}								t_igmlx_callback_function;

typedef struct s_igmlx_panel
{
	t_igmlx_component			base;
	void						(*pre_render)(struct s_igmlx_panel *);
	void						(*set_background)(struct s_igmlx_panel *,
								t_color color);
	t_igmlx_button_component	*(*add_button)(struct s_igmlx_panel *);
	void						(*destroy)(struct s_igmlx_panel *, t_igmlx *);
	void						(*render_on_window)(struct s_igmlx_panel *,
								void *);
	void						(*render_on_buffer)(struct s_igmlx_panel *,
								t_img *);
	unsigned int				background_opacity;
	bool						dragable;
	t_igmlx_callback_function	on_close_callback;
	t_igmlx_callback_function	on_reduce_callback;
	t_list						*childs;
	t_igmlx						*igmlx;
}								t_igmlx_panel;

typedef struct s_igmlx
{
	void						*mlx;
	t_list						*panels;
	t_list						*fonts;
	t_uvec_2					mouse_pos;
	t_uvec_2					last_mouse_pos;
	t_igmlx_default_component	*drag_component;
	t_igmlx_default_component	*last_hovered_component;
}								t_igmlx;

int								igmlx_loop(t_igmlx *igmlx);

void							_log(t_e_igmlx_log_level level,
									const char *msg);

t_win_data						*get_window_data(t_igmlx *igmlx, void *win);
bool							add_to_window_data(t_igmlx *igmlx, void *win,
									void *component);

// COMPONENTS
void							init_component_states_images(t_igmlx *igmlx,
									t_igmlx_default_component *component);
t_igmlx_component_state			get_component_state(t_igmlx_default_component *component);
t_img							*get_component_image(t_igmlx_default_component *component);

int								igmlx_mouse_motion_event_callback(int x, int y,
									t_igmlx *igmlx);
int								igmlx_mouse_button_released_event_callback(int key,
									int x, int y, t_igmlx *igmlx);
int								igmlx_mouse_button_pressed_event_callback(int key,
									int x, int y, t_igmlx *igmlx);

void							igmlx_destroy(t_igmlx *igmlx);
t_igmlx_default_component		*get_win_component_at(t_igmlx *igmlx, void *win,
									t_uvec_2 coords);

t_igmlx_default_component		*get_component_at(t_igmlx *igmlx,
									t_uvec_2 coords);
// FONTS
void							igmlx_destroy_fonts_list(t_igmlx *igmlx,
									t_list **fonts);

t_igmlx_font					*get_font(t_igmlx *igmlx, char *path);

t_alpha_img						*transform_img_to_alpha_img(t_igmlx *igmlx,
									t_img *img);

// UTILS

void							igmlx_set_to_null(t_img *origin,
									t_uvec_2 origin_pos, t_uvec_2 length);
t_color							get_pixel_color(t_img *img, t_uvec_2 pos);
t_color							*get_pixel(t_img *img, t_uvec_2 pos);
void							igmlx_copy_to_dest(t_img *origin,
									t_uvec_2 origin_pos, t_uvec_2 length,
									t_img *dest, t_uvec_2 dest_pos);
void							*balloc(size_t size);
bool							is_inside_rectangle(t_uvec_2 p1, t_uvec_2 p2,
									t_uvec_2 target);
t_rectangle						get_largest_rectangle_available_img(t_img *img);

void							igmlx_change_panel_background_color(t_igmlx_panel *panel,
									t_color color);

void							igmlx_panel_render_on_window(t_igmlx_panel *panel,
									void *win);

void							igmlx_render_window_components(t_igmlx *igmlx,
									void *win);
void							igmlx_render_component(t_igmlx *igmlx,
									void *win,
									t_igmlx_default_component *component);
void							igmlx_destroy_panel(t_igmlx_panel *panel,
									t_igmlx *igmlx);
void							igmlx_set_component_state(t_igmlx_default_component *component,
									t_e_igmlx_state new_state);
t_igmlx_button_component		*igmlx_create_button_component(t_igmlx_panel *parent);
t_igmlx_button_component		*igmlx_panel_add_button_component(t_igmlx_panel *parent);
void							igmlx_panel_pre_render(t_igmlx_panel *panel);
void							igmlx_panel_add_component(t_igmlx_panel *parent,
									t_igmlx_component *component);

void							igmlx_free_component(t_igmlx *igmlx,
									t_igmlx_default_component *component);
									void	igmlx_render_panel_components_to_window(t_igmlx_panel *panel, void *win);
// PNG
int								igmlx_open_png_file(const char *path);

#endif
