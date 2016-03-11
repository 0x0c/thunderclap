//
//  thunderclap.h
//  thunderclap
//
//  Created by Akira Matsuda on 3/10/16.
//
//

#pragma once

#include <vector>
#include <string>
#include <map>
#include <memory>
#include <functional>

namespace thunderclap {
	template <typename T> class thunderclap
	{
	protected:
		std::map<std::string, std::shared_ptr<std::map<std::string, std::function<void(T x)>>>> table;
		bool available(std::string name);
	public:
		static thunderclap<T>* shared_instance();
		void clap(std::string name, T x);
		std::string watch(std::string name, std::function<void(T x)> f);
		void dispose(std::string name, std::string hash);
		void dispose_all(std::string name);
	};
}

#include "detail/thunderclap.h"
