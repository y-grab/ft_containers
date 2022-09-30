#ifndef TESTS_HPP
# define TESTS_HPP

# include <vector>
# include <map>
# include <stack>
# include <iostream>
# include "vector.hpp"
# include "map.hpp"
# include "stack.hpp"

# define RESET "\e[0m"
# define GREEN "\e[92m"
# define RED "\e[91m"
# define BLUE "\e[94m"
# define BOLD "\e[1m"

# define OK "OK"
# define KO "KO"

void	test_vector(void);
void	test_map(void);
void	test_stack(void);

inline void print_header(std::string str)
{
	std::cout << BLUE << "*** " << str << " ***" << RESET << std::endl;
};

template <typename T>
inline void check(std::string name, T a, T b)
{
	if (a == b)
		std::cout << name << ": " << BOLD << GREEN << OK << RESET << std::endl;
	else
		std::cout << name << ": " << BOLD << RED << KO << RESET << std::endl;
};

inline void check(std::string name, bool is_true)
{
	if (is_true)
		std::cout << name << ": " << BOLD << GREEN << OK << RESET << std::endl;
	else
		std::cout << name << ": " << BOLD << RED << KO << RESET << std::endl;
};

template <typename T>
bool operator==(ft::vector<T> &a, std::vector<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return (false);
	}
	return (true);
};

template <typename T, typename S>
bool operator==(ft::map<T, S> &a, std::map<T, S> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::map<T, S>::iterator it = a.begin();
	typename std::map<T, S>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (it->first != it2->first || it->second != it2->second)
			return (false);
		++it;
		++it2;
	}
	return (true);
};

#endif