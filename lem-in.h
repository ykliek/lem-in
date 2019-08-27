/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:47:32 by ykliek            #+#    #+#             */
/*   Updated: 2019/08/13 13:47:33 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft/libft.h"

#include <stdio.h> // TODO: delete

/*
 * TODO:
 * 		1. Make all structure clear and comfortable to use;
 * 		2. Organize two dimensional structure with end and start and all necessary information
 */

typedef struct			s_node
{

}						t_node;

typedef struct			s_room
{
	char	*name; // TODO: don't forget to clear memory
	int		x;
	int		y;
}						t_room;

typedef struct			s_anthill
{
	t_node				*node;
	struct s_anthill	*next;
	struct s_anthill	*prev;
}						t_anthill;

typedef struct			s_dblist
{
	int 		size;
	t_anthill	*head;
	t_anthill	*tail;
}						t_dblist;

/*
 * lst_tools.c
 */

t_dblist				*create_dblist();

void					delete_dblist(t_dblist **list);

void					push_front(t_dblist *list, t_node *node);

void					push_back(t_dblist *list, t_node *node);

t_anthill				*get_node(t_dblist *list, int i);

#endif
