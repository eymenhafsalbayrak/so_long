#include "so_long.h"

void load_sprite(t_game *game)
{
    int tmpX;
    int tmpY;
    
    game->cuphead_sprite = mlx_xpm_file_to_image(game->mlx, "./res/cuphead.xpm", &tmpX, &tmpY); // xmp convert to img, yukledigin img'in height ve width'i atiyor
    game->wall_sprite = mlx_xpm_file_to_image(game->mlx, "./res/wall.xpm", &tmpX, &tmpY);
    game->floor_sprite = mlx_xpm_file_to_image(game->mlx, "./res/floor.xpm", &tmpX, &tmpY);
    game->coin_sprite = mlx_xpm_file_to_image(game->mlx, "./res/coin.xpm", &tmpX, &tmpY);
    game->exit_sprite = mlx_xpm_file_to_image(game->mlx, "./res/exit.xpm", &tmpX, &tmpY);
}

static int	filename_check(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'r' && str[i - 1] == 'e'
		&& str[i - 2] == 'b' && str[i - 3] == '.')
		return (1);
	return (0);
}

void start_game(char *map_name)
{
    t_game *game; // game adli bir pointer struct
    int fd;       // fd dosyasi

    
    if (!filename_check(map_name))
        return ;
    game = (t_game *)malloc(sizeof(t_game)); // struct'a malloc ile yer acilmasi
    game->coins = 0;                         // sifirlanmayinca gormuyor
    game->exit = 0;
    game->ply = 0;
    game->moves = 0;
    fd = open(map_name, O_RDONLY);         // fd ile hangi map ise okunuyor
    game->map = map_constractor(game, fd); // iki boyutlu map adli degiskene map'i okuyup atiyor // after we read map
    close(fd);
    if (map_validation(game)) // map dogrulama bak bakalim duzgun mu
    {
        write(1, "ERROR\n", 6);
        free(game);
        exit(1);
    }
    game->mlx = mlx_init();                                                                                  // mlx kutuphanesine erisebilme
    game->mlx_win = mlx_new_window(game->mlx, game->map_width * PIXEL, game->map_height * PIXEL, "so_long"); // map'in pixellerle bastirilmasi
    load_sprite(game);
    find_player(game);                                                                        // player'in yeri bulundu
    mlx_hook(game->mlx_win, 2, 1L << 0, key_down, game);                                      // ASK HIM
    mlx_hook(game->mlx_win, 17, 0L << 0, game_exit, game);
    mlx_loop_hook(game->mlx, render, game);                                                   // ASK HIM
    mlx_loop(game->mlx);                                                                      // window'un acik kalmasi
}