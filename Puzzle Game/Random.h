#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <chrono>

namespace Random
{
	
	inline std::mt19937 generate()
	{
		std::random_device rd{};
		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>
				(std::chrono::steady_clock::now().time_since_epoch().count()),
				rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		return std::mt19937{ ss };
	}

	inline std::mt19937 mt{ generate() };

	inline int get(int min, int max)
	{
		return std::uniform_int_distribution{min, max}(mt);
	}

	template <typename T>
	inline T get(T min, T max)
	{
		return std::uniform_int_distribution<T>{min, max}(mt);
	}

	template <typename R, typename S, typename T>
	inline R get(S min, T max)
	{
		return get<R>(static_cast<R>(min), static_cast<R>(max));
	}
}

#endif // !RANDOM_H