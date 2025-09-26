#pragma once

# include <iostream>
# include <vector>
# include <limits>
# include <algorithm> // for sort

class Span
{
	private:

		std::vector<int> _element;
		unsigned int _capacity;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();
		void addNumber(long number);
		// handle multiple inserts for all kind of container
		template <typename Iterator>
		void addNumber(Iterator begin, Iterator end)
		{
			unsigned int range_size = static_cast<unsigned int>(std::distance(begin, end));
			if (_element.size() + range_size > _capacity)
				throw OverMaxCapacity();
			_element.insert(_element.end(), begin, end);
		}
		int shortestSpan() const;
		int longestSpan() const;
		void addRandomNumbers(int amount);
		void printSpan() const;
		void sortPrintSpan() const;
		class OverMaxCapacity : public std::exception
		{
		public:
			const char* what() const throw();
		};
		class NoSpanPossible : public std::exception
		{
		public:
			const char* what() const throw();
		};
};
