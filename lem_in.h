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

# include "libft/libft.h"
# include <limits.h>

# define FINISHED INT_MAX

enum
{
	ROOM,
	X,
	Y
};

enum
{
	LINK_1,
	LINK_2,
	ERROR
};

enum
{
	START,
	END
};

typedef struct			s_link
{
	char				*room_1;
	char				*room_2;
}						t_link;

typedef struct			s_anthill
{
	struct s_room		*room;
	struct s_anthill	*next;
	struct s_anthill	*prev;
}						t_anthill;

typedef struct			s_dblist
{
	int					size;
	t_anthill			*end;
	t_anthill			*head;
	t_anthill			*tail;
	t_anthill			*start;
}						t_dblist;

typedef struct			s_room
{
	int					x;
	int					y;
	int					id;
	char				*name;
	int					status;
	int					inside;
	t_dblist			*links;
	int					distance;
	struct s_room		*previous;
	int					visit_status;
}						t_room;

typedef struct			s_print
{
	char				*content;
	struct s_print		*next;
}						t_print;

typedef struct			s_data
{
	int					fd;
	int					ants;
	int					check;
	int					count;
	int					i;
	int					nodes;
	int					status;
	int					num_line;
	t_dblist			*anthill;
}						t_data;

/*
** dblst_tools.c
*/

t_dblist				*create_dblist();

void					delete_dblist(t_dblist **list);

void					push_back(t_dblist *list, t_room *room);

t_anthill				*create_list(t_room *room);

/*
** reader.c
*/

t_print					*read_map(t_data *data);

void					define_line(t_data *data, char *line);

void					num_ants(t_data *data, char *line);

/*
** error_management.c
*/

void					err_massage(char *massage, int err);

/*
** parser.c
*/

void					parse_command(t_data *data, char *line);

void					parse_room(t_data *data, char *line);

void					parse_link(t_data *data, char *line);

/*
** bfs.c
*/

t_dblist				*run_algorithm(t_data data);

void					delete_list(t_anthill **list);

/*
** go_ants.c
*/

void					go_ants(t_anthill *roads, t_data *data,
		t_anthill *check, int *path);

int						*define_path(t_anthill *roads);

/*
** tools.c
*/

t_room					*dequeued(t_anthill **front);

void					enqueue(t_anthill **tmp, t_anthill **front,
		t_room *data);

void					print_road(t_data *data, t_room *room);

int						printable_path(int *numbers, t_room *room, int ants);

void					free_2d_array(char **arr);

/*
** room.c
*/

void					check_room(t_data *data, t_room *new);

void					search_room(t_data *data, char *room);

void					find_rooms_links(t_data *data, t_link link);

#endif
