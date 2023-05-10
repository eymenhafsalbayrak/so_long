#include "so_long.h"

int render(t_game *game)
{
    (void ) game;

    mlx_clear_window(game->mlx, game->mlx_win);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->cuphead_sprite, game->player_x * PIXEL, game->player_y * PIXEL);
    return (0);
}