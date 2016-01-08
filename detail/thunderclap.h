#include "../thunderclap.h"
#include <algorithm>
#include <random>

namespace thunderclap
{
	template <typename T> thunderclap<T>* thunderclap<T>::shared_instance() {
		static thunderclap::thunderclap<T> shared_instance;
		return &shared_instance;
	}

	template <typename T> bool thunderclap<T>::available(std::string name) {
		bool result = false;
		if (this->table.find(name) != this->table.end()) {
			result = true;
		}

		return result;
	}

	template <typename T> void thunderclap<T>::clap(std::string name, T x) {
		if (this->available(name)) {
			auto m = this->table[name];
			for (auto it = m->begin(); it != m->end(); ++it) {
				auto f = it->second;
				f(x);
			}
		}
	}

	template <typename T> std::string thunderclap<T>::watch(std::string name, std::function<void(T x)> f) {
		std::string hash;
		static std::string chars = "abcdefghijklmnopqrstuwxyzABCDEFGHIJKLMNOPQRSTUWXYZ0123456789,./;'[]-=<>?:{}|_+";
		static std::random_device rnd;
		static std::mt19937 mt(rnd());
		static std::uniform_int_distribution<> idx(0, 32);
		for (int i = 0; i < 32; ++i) {
			hash += chars[idx(mt)];
		}
		
		if (this->available(name)) {
			auto m = this->table[name];	
			m->insert(std::make_pair(hash, f));
			this->table[name] = m;
		}
		else {
			std::map<std::string, std::function<void(T x)>> m;
			m.insert(std::make_pair(hash, f));
			this->table[name] = std::make_shared<std::map<std::string, std::function<void(T x)>>>(m);
		}

		return hash;
	}

	template <typename T> void thunderclap<T>::dispose(std::string name, std::string hash) {
		if (this->available(name)) {
			auto m = this->table[name];
			auto it = m->find(hash);
			if (it != m->end()) {
				m->erase(it);
			}
		}
	}

	template <typename T> void thunderclap<T>::dispose_all(std::string name) {
		if (this->available(name)) {
			auto m = this->table[name];
			m->clear();
		}
	}
}
