#pragma once

template <typename T> T min(T x, T y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

template <typename T> T max(T x, T y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

template <typename T> void swap(T &x, T &y)
{
	T tmp;

	tmp = x;
	x = y;
	y = tmp;
}