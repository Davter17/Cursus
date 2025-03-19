
#include "../includes/so_long.h"

/*
int main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_printf("Error: El programa requiere de un único argumento\n"), 1);
	if (check_map(argv[1]) == 0)
		return (1);
	return (0);
}
*/

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        error_exit("Uso: ./so_long mapa.ber\n");

    parse_map(&game, argv[1]);

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, 640, 480, "so_long");
    render_map(&game);

    mlx_loop(game.mlx);
    return (0);
}
