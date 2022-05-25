#include "../include/cub3d.h"

char	**map_reader(char *path) // считываем карту
{
	int		fd;
	char	*temp;
	char	*map_holder;
	char	*line;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_holder = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = map_holder;
		map_holder = ft_strjoin(temp, line);
		free(line);
		free(temp);
	}
	map = ft_split(map_holder, '\n');
	free(map_holder);
	close(fd);
	return (map);
}