/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookmgr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:10:23 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/21 18:45:50 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H

# define HOOKS_H

# define ESC_KEY 65307 
# define FORE_COLOR 0xffffff

# include "mlx_common.h"
# include "scenemgr.h"

int		test_mouse_hook(int button, int x, int y, void *params);
int		test_key_hook(int keycode, void *params);
int		test_loop_hook(void);

#endif