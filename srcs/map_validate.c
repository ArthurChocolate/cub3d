#include "../include/cub3d.h"

int	symbol_checker(char **map) // проверяет карту на наличие ошибочных символов
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
				&& map[i][j] != 'W' && map[i][j] != '\t')
			{
				printf("%s\n", "Map symbol error");
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	str_is_only_one(char *str)
{
	while (*str)
	{
		if (*str != '1')
			return (1);
		str++;
	}
	return (0);
}

//TODO: не работает с пробелами
int	upper_lower_check(char **map) // проверка верхних/нижних границ 
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	i--;
	if (str_is_only_one(map[i]))
	{
		printf("%s\n", "Map edge error");
		exit(1);
	}
	if (str_is_only_one(map[0]))
	{
		printf("%s\n", "Map edge error");
		exit(1);
	}
	return (0);
}

//TODO: пропускать пробелы/табы в конце
int	edge_checker(char **map) // проверяет боковые границы на 1 пропуская пробелы/табы в начале
{
	int	i;
	int	j;
	int	last;

	i = 0;
	while (map[i])
	{
		j = 0;
		last = ft_strlen(map[i]) - 1;
		while (map[i][j])
		{
			while (map[i][j] == ' ' || map[i][j] == '\t')
				j++;
			if (map[i][j] != '1' || map[i][last] != '1')
			{
				printf("%s\n", "Map edge error");
				exit(1);
			}
			j = 0;
			break ;
		}
		i++;
	}
	return (0);
}

int	player_checker(char **map) // проверяет кол-во игроков на карте
{
	int	p;
	int	i;
	int	j;

	i = 0;
	p = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
	{
		printf("%s\n", "Player error");
		exit(1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	char	**map;

	(void)argc;
	map = map_reader(argv[1]);
	symbol_checker(map);
	upper_lower_check(map);
	edge_checker(map);
	player_checker(map);
}