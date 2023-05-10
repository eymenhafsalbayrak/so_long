#include "so_long.h"

void    start_game(char *map_name)
{
    t_game *game;
    int fd;

    game = (t_game *) malloc(sizeof(t_game));
    game->coins = 0;
    game->exit = 0;
    game->ply = 0;
    fd = open(map_name, O_RDONLY);
    game->map = map_constractor(game, fd);
    close(fd);
    if (map_validation(game))
    {
        free(game);
        exit(1);
    }
    game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->map_width * PIXEL, game->map_height * PIXEL, "so_long");
    int tmp;
    game->cuphead_sprite = mlx_xpm_file_to_image(game->mlx, "./res/cuphead.xpm", &tmp, &tmp);
    find_player(game);
    mlx_hook(game->mlx_win, 2, 1L<<0, key_down, game);
    mlx_loop_hook(game->mlx, render, game);
    mlx_loop(game->mlx);
}