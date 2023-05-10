#include "so_long.h"

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2


int key_down(int keycode, t_game *game)
{
    (void )game;
    if (keycode == 53)
    {
        mlx_destroy_image(game->mlx, game->cuphead_sprite);
        mlx_destroy_window(game->mlx, game->mlx_win);
        free(game);
        exit(0);
    }
    else if (keycode == KEY_W)
    {
        game->player_y--;
    }
    else if (keycode == KEY_S)
    {
        game->player_y++;
    }
    else if (keycode == KEY_A)
    {
        game->player_x--;
    }
    else if (keycode == KEY_D)
    {
        game->player_x++;
    }
    return (0);
}