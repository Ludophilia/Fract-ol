/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:10:23 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/21 14:55:42 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H

# define HOOKS_H

# include "mlx_common.h"
# include "scenemgr.h"

int		test_mouse_hook(int button, int x, int y, void *params);
int		test_key_hook(int keycode, void *params);
int		test_loop_hook(void *params);

#endif