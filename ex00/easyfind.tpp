
// Why typename is required
//
// Inside a template, the compiler doesn’t know if T::iterator is:
//
// A type (like std::vector<int>::iterator)
//
// A static member variable or function

template <typename T>
typename T::iterator easyfind(T &con, int val)
{
	typename T::iterator it = std::find(con.begin(), con.end(), val);
	if (it == con.end())
		throw NotFoundException();
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &con, int val)
{
	typename T::const_iterator it = std::find(con.begin(), con.end(), val);
	if (it == con.end())
		throw NotFoundException();
	return it;
}

const char * NotFoundException::what() const throw()
{
	return (" not found");
}

