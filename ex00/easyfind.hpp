#pragma once

# include <algorithm> // for std::find
# include <exception>

template <typename T>
typename T::iterator easyfind (T &con, int val);

template <typename T>
typename T::const_iterator easyfind(const T &con, int val);

class NotFoundException : public std::exception
{
	public:
		const char *what () const throw();
};

#include "easyfind.tpp"
