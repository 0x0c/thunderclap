#include <iostream>
#include "thunderclap.h"

int main(int argc, char const *argv[])
{
  auto t = thunderclap::thunderclap<std::string>::shared_instance();
  auto idx = t->watch("notification", [](std::string x) {
    std::cout << "notification received1 : " << x << std::endl;
  });
  auto idx2 = t->watch("notification", [](std::string x) {
    std::cout << "notification received2 : " << x << std::endl;
  });

  t->clap("notification", "param");
  t->dispose("notification", idx);
  t->clap("notification", "param2");
  t->dispose("notification", idx2);
  t->clap("notification", "param3");

  return 0;
}
