#include "../thunderclap.h"

namespace thunderclap
{
	template <typename T> thunderclap<T>* thunderclap<T>::shared_instance() {
		static thunderclap::thunderclap<T> shared_instance;
		return &shared_instance;
	}

	template <typename T> void thunderclap<T>::clap(std::string name, T x) {
		if (this->table.find(name) != this->table.end()) {
			auto f = this->table[name];
			f(x);
		}
	}

	template <typename T> void thunderclap<T>::watch(std::string name, std::function<void(T x)> f) {
		this->table[name] = f;
	}

	template <typename T> void thunderclap<T>::dispose(std::string name) {
		this->table.erase(name);
	}
}
