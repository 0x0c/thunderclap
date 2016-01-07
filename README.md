# thunderclap
Fuck'n simple notification system.

## Usage
```
// get shared instance
auto t = thunderclap::thunderclap<std::string>::shared_instance();

// add observer
t->watch("notification", [](std::string x) {
	std::cout << "notification received!! : " << x << std::endl;
});

// then post notification
t->clap("notification", "param");

// remove observer
t->dispose("notification");
```
See more at `main.cpp`.