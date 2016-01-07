#include <iostream>
#include "thunderclap.h"

int main(int argc, char const *argv[])
{
  auto t = thunderclap::thunderclap<std::string>::shared_instance();
  t->watch("notification", [](std::string x) {
    std::cout << "notification received!! : " << x << std::endl;
  });

  t->clap("notification", "param");
  t->dispose("notification");
  t->clap("notification", "param2");

  return 0;
}
