/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:30:01 by steh              #+#    #+#             */
/*   Updated: 2022/12/22 22:51:15 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include "../inc/cube3d.h"

/**
 * @brief Get the wall texture based on the orientation
 * and return it
 * 
 * @param scene 
 * @param orientation 
 * @return t_texture 
 */
t_texture	get_wall_texture(t_scene *scene, char orientation)
{
	if (orientation == 'N')
		return (scene->no_tex);
	else if (orientation == 'S')
		return (scene->so_tex);
	else if (orientation == 'E')
		return (scene->ea_tex);
	else if (orientation == 'D')
		return (scene->do_tex);
	else
		return (scene->we_tex);
}
