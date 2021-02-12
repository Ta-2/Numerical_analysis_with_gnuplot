#include "sender.hpp"
#include <memory>
#include <iostream>
#define arr_size 10

double arr[arr_size] = {};

int main (){
  std::shared_ptr <double> shared_arr(arr, std::default_delete<double[]>());
  Sender sender(shared_arr);
  if (!sender.SuccessGnuplot()) return 1;
  sender.SetXrange(0, 15);
  sender.SetYrange(-1, 1);
  sender.SendData();

  //std::cin.get();
  return 0;
}
