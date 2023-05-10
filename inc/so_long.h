#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

# define PIXEL 64

typedef struct s_game
{
    void *mlx;
    void *mlx_win;

    void *cuphead_sprite;

    int player_x;
    int player_y;
    
    int map_height;
    int map_width;
    
    char **map;

    int exit;
    int ply;
    int coins;

}   t_game;

//GAME
void    start_game(char *map_name);

//INPUT
int     key_down(int keycode, t_game *game);

//DRAW
int     render(t_game *game);

//MAP
char	**map_constractor(t_game *game, int fd);
int     map_validation(t_game *sl);

//UTILS
int	    ft_strlen(char *str);
void	ft_reset(char *buffer);
void	find_player(t_game *game);

#endif