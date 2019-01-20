#include <iostream>

void f()
{
  std::cout << "function called" << std::endl;
}

int main ( int argc, char *argv[] )
{
  (void)argv;

  if ( 0 )
    std::cout << "Not covered." << std::endl;

  if ( argc > 10 )
  {
    f();
  }

  std::cout << "Sample text." << std::endl;

  return 0;
}
