
#include "Span.hpp"

// Default constructor
Span::Span():
	_capacity(0)
{
	_element.reserve(_capacity);
}

// Parameterized constructor
Span::Span(unsigned int N)
	:_capacity(N)
{
	_element.reserve(_capacity);
}

// Copy constructor
Span::Span(const Span &other):
	_element(other._element), _capacity(other._capacity)
{
	_element.reserve(other._capacity); // without this the capacity would be different from the new object
}

// Copy Assignment operator overload
Span &Span::operator=(const Span &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_element = other._element;
		_capacity = other._capacity;
		_element.reserve(other._capacity); // without this the capacity would be different from the new object
	}
	return (*this);
}

// Destructor
Span::~Span(void)
{
	// std::cout << "Destructor called" << std::endl;
}

const char *Span::OverMaxCapacity::what() const throw()
{
	return ("\033[1;31m Over max capacity \033[0m");
}

const char *Span::NoSpanPossible::what() const throw()
{
	return ("\033[1;31m Not enough elements for building a span \033[0m");
}

void Span::addNumber(long number)
{
	if (_element.size() < _capacity)
	{
		if (static_cast<int>(number) >= std::numeric_limits<int>::max()
		|| static_cast<int>(number) < std::numeric_limits<int>::min())
			throw std::out_of_range("Number out of range");
		_element.push_back(number);
	}
	else
		throw OverMaxCapacity();
}

int Span::shortestSpan() const
{
	if (_element.size() < 2)
		throw NoSpanPossible();
	std::vector<int> temp(_element);
	std::sort(temp.begin(), temp.end());
	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 0; i < temp.size() - 1; ++i)
	{
		int diff = temp[i + 1] - temp[i];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (_element.size() < 2)
		throw NoSpanPossible();
	std::vector<int> temp(_element);
	std::sort(temp.begin(), temp.end());
	int longest;
	longest = *temp.rbegin() - *temp.begin();

	return longest;
}

void Span::addRandomNumbers(int amount)
{
	std::vector<int> temp(amount);
	for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); ++it)
	{
		*it = std::rand();
	}
	addNumber(temp.begin(), temp.end());
}

void Span::printSpan() const
{
	if (_element.size() == 0)
	{
		std::cout << "empty span" << std::endl;
		std::cout << "\033[34mcapacity = \033[0m";
		std::cout << _element.capacity() << std::endl;
		std::cout << "\033[34msize = \033[0m";
		std::cout << _element.size() << std::endl;
		return;
	}
	for (std::vector<int>::const_iterator it = _element.begin();
		it != _element.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "\033[34mcapacity = \033[0m";
	std::cout << _element.capacity() << std::endl;
	std::cout << "\033[34msize = \033[0m";
	std::cout << _element.size() << std::endl;
}

void Span::sortPrintSpan() const
{
	if (_element.size() == 0)
	{
		std::cout << "empty span" << std::endl;
		std::cout << "\033[34mcapacity = \033[0m";
		std::cout << _element.capacity() << std::endl;
		std::cout << "\033[34msize = \033[0m";
		std::cout << _element.size() << std::endl;
		return;
	}
	std::vector<int> temp(_element);
	std::sort(temp.begin(), temp.end());
	for (std::vector<int>::const_iterator it = temp.begin();
		it != temp.end(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;
	std::cout << "\033[34mcapacity = \033[0m";
	std::cout << _element.capacity() << std::endl;
	std::cout << "\033[34msize = \033[0m";
	std::cout << _element.size() << std::endl;
}