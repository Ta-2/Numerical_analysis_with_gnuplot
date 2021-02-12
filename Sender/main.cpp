#include "sender.hpp"
#include <memory>
#include <iostream>
#include <math.h>
#define arr_size 10
#define PI 3.14159265359

void func (double* arr){
  for(int i = 0; i < arr_size; i++){
    *(arr + i) = sin(2*PI*i/arr_size);
  }
}
double arr[arr_size] = {};

int main (){
  func(arr);
  std::shared_ptr <double> shared_arr(arr, std::default_delete<double[]>());
  Sender sender(shared_arr, arr_size);
  if (!sender.SuccessGnuplot()) return 1;
  sender.SetXrange(0, 15);
  sender.SetYrange(-1, 1);
  sender.SendData();

  std::cin.get();
  return 0;
}
