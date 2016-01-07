#pragma once
#include <string>
#include <map>
#include <functional>

namespace thunderclap {
	template <typename T> class thunderclap
	{
	protected:
		std::map<std::string, std::function<void(T x)>> table;
	public:
		static thunderclap<T>* shared_instance();
		void clap(std::string name, T x);
		void watch(std::string name, std::function<void(T x)> f);
		void dispose(std::string name);
	};
}

#include "detail/thunderclap.h"
