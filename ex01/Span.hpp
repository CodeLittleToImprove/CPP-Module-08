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
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void printSpan() const;
		void sortPrintSpan() const;
		int shortestSpan() const;
		int longestSpan() const;
		class OverMaxCapacity : public std::exception
		{
		public:
			const char *what() const throw();
		};
		class NoSpanPossible : public std::exception
		{
		public:
			const char *what() const throw();
		};
};
