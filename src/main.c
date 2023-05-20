/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:22:09 by ealbayra          #+#    #+#             */
/*   Updated: 2023/05/18 16:37:20 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
		start_game(av[1]); // .so_long ve map'in cagirilmasi
	return (0);
}