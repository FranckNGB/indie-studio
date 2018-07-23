/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_PARAMS_HPP
#define BOMBERMAN_PARAMS_HPP

class Params {
public:
	Params(int ac, char *av[]);
	~Params() = default;
	bool	parse();
	bool	getVerbose() const;
	bool	getFullscreen() const;
	bool	getVsync() const;
	int	getIndex();
	std::pair<size_t, size_t>	getResolution() const;
private:
	void	displayHelp() const;
	bool	argsExist(const char *arg) const;
	bool	checkParams(char **arg) const;

private:
	bool	_verbose;
	bool	_vsync;
	bool	_fullscreen;
	char	**_av;
	int	_nbArgs;
	size_t	_width;
	size_t	_height;
};

#endif //BOMBERMAN_PARAMS_HPP
