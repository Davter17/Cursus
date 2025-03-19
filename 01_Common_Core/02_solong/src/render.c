#include "../includes/so_long.h"

void render_map(t_game *game)
{
    int x, y;
    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == '1')
                mlx_pixel_put(game->mlx, game->win, x * 32, y * 32, 0xFFFFFF);
            x++;
        }
        y++;
    }
}
