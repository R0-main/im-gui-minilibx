# im-gui-minilibx

An immediate-mode style graphical user interface toolkit built on top of the
[MiniLibX](https://github.com/42Paris/minilibx-linux) rendering loop. The
library provides higher level widgets, text rendering utilities, and image
helpers that plug directly into an existing MiniLibX project.

## Features

- **Window integration helpers** – initialize the GUI runtime once and attach
  it to any MiniLibX window to receive mouse motion and button events.
- **Panel container component** – create hierarchical panels, change their
  background, and render the entire tree with a single call.
- **Interactive buttons** – allocate buttons with sensible defaults, register
  callback hooks, and let the renderer update their visuals based on component
  state.
- **Bitmap font loading and printing** – load `.xpm` bitmap fonts and blit text
  onto any MiniLibX image buffer, complete with color filtering and glyph
  spacing controls.
- **Rendering utilities** – copy image regions, ignore fully transparent pixels,
  and keep component states up to date before presenting the frame.
- **Structured logging** – color-coded log helpers make it easy to inspect what
  the GUI runtime is doing.

## Repository layout

```
├── includes/        # Public and internal headers
├── src/             # Library sources grouped by feature
├── fonts/           # Sample bitmap fonts used by the tests
├── pngs/            # Image fixtures for alpha-image experiments
├── tests/           # Example program that drives the library
└── Makefile         # Builds the static library and optional demo binary
```

## Getting started

### Prerequisites

- A Linux environment with X11 development headers (MiniLibX requirements).
- `clang`, `make`, and standard build tooling.
- Network access to fetch `minilibx-linux` and `ft_libc` the first time `make`
  is run. If you do not have SSH access for `git@github.com:R0-main/ft_libc`,
  update the remote in the `Makefile` to use HTTPS before building.

### Build the static library

```bash
make
```

The command compiles `im-gui-minilibx.a` and automatically fetches its
dependencies when they are missing.

### Build and run the demo program

```bash
make tests
./tests.out
```

`tests.out` lives in the project root and opens a window that demonstrates text
rendering and event hooks.

## Usage examples

### Initialize the GUI runtime

```c
#include "mlx.h"
#include "igmlx.h"

int main(void)
{
    void    *mlx;
    void    *win;
    t_igmlx *gui;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "im-gui-minilibx");
    gui = igmlx_init(mlx);
    igmlx_hook_to_window(gui, win);
    // ... set up your event loop here ...
    igmlx_destroy(gui);
    mlx_destroy_window(mlx, win);
    return (0);
}
```

The runtime stores the `mlx` handle internally and installs motion and button
hooks on the target window so widgets receive input.

### Create a panel and add a button

```c
#include "igmlx.h"

static void on_press(void *ctx)
{
    int *counter = ctx;
    (*counter)++;
}

void build_ui(t_igmlx *gui, void *win)
{
    static int                     counter = 0;
    t_igmlx_panel                  *panel;
    t_igmlx_button_component       *btn;

    panel = igmlx_create_panel(gui);
    panel->base.pos = (t_uvec_2){40, 40};
    panel->dragable = true;
    btn = panel->add_button(panel);
    btn->base.pos = (t_uvec_2){24, 24};
    btn->press = on_press;
    btn->data = &counter;
    btn->base.states[IGMLX_STATE_DEFAULT].backgroud_color = 0x0066CCFF;
    btn->base.states[IGMLX_STATE_HOVERED].backgroud_color = 0x0088FFFF;
    panel->pre_render(panel);
    panel->render_on_window(panel, win);
}
```

Panels act as containers for child components. When you are ready to draw, call
`pre_render` once to bake the component images and `render_on_window` each frame
to push the panel tree onto the MiniLibX window.

### Draw text into an off-screen buffer

```c
#include "igmlx.h"

void draw_overlay(t_igmlx *gui, void *mlx, void *win)
{
    t_img *buffer;

    igmlx_load_font(gui, "fonts/default.xpm",
        (t_igmlx_font_params){.color = 0x00FF00FF,
                              .size_multiplier = 1,
                              .inner_offset = (t_uvec_2){24, 0}});
    buffer = mlx_new_image(mlx, 550, 100);
    igmlx_put_str_to_buffer(gui, "Coins: 100", "fonts/default.xpm", buffer,
        (t_uvec_2){32, 24});
    mlx_put_image_to_window(mlx, win, buffer, 0, 0);
    mlx_destroy_image(mlx, buffer);
}
```

Fonts are cached by path, recolored when loaded, and each glyph is blitted into
place with transparency preserved so the overlay respects existing pixels.

## Additional resources

- Inspect `tests/main.c` for a full example that wires the GUI into a running
  MiniLibX loop, handles cleanup, and demonstrates text rendering inside the
  loop hook.
- The `src` directory is organized by feature; browsing those files is a good
  way to learn how panels, buttons, fonts, and image helpers are implemented.
