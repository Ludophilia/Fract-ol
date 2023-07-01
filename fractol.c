/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:15:53 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/01 17:00:54 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	main(int argc, char **argv)
{
	ft_dprintf(1,
		"Welcome to %s!\n\tYou added %i arguments.\n",
		*argv,
		argc - 1
	);
}
