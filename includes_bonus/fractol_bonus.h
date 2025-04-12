/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:38:52 by jgermany          #+#    #+#             */
/*   Updated: 2025/04/12 17:04:52 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H

# define FRACTOL_BONUS_H

# include "../includes/fractol.h"

# define SHIFT_FACTOR 0.05
# define SHIFT_LEFT 0x10
# define SHIFT_RIGHT 0x20
# define SHIFT_UP 0x30
# define SHIFT_DOWN 0x40

# define PALETTE_SIZE 4

# define SHIP 2

typedef struct s_inp
{
	int	fract;
	double	zcons[2];
	char	*zconsrw[2];
}	t_inp;

int		clib_get_args(int argc, char **argv, t_fra *fra);

int		hookb_key_event_manage(int keycode, t_ui *ui);
int		hookb_mouse_event_manage(int button, int x, int y, t_pln *pln);

void	uib_events_register(t_ui *ui);
int		uib_init(t_ui *ui);

// 12/04
int		color_palettes_build(int colors_per_gradient, t_core *core);
void	color_palettes_shift(int straight, t_pal *palette);

int		plot_colorize_coords(double x, double y, t_core *core);

void	view_change_comp_plane_zoom_level(int zoom_in, double x, double y,
		t_pln *com_pln);
void	view_shit_comp_plane(uchar shift_direction, t_pln *com_pln);

#endif
