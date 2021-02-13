#include "Analyzer.hpp"
#include <memory>
#include <iostream>
#define arr_size 20

double arr[arr_size] = {};

class Wave_Solution : public SolutionInterface{
public:
  Wave_Solution(int size, double set_delta_t, double set_c)
  : delta_t(set_delta_t), c(set_c){}
  void Solve (){ std::cout << "solve" << std::endl; }
  ~Wave_Solution(){}
private:
  int size;
  double delta_t;
  double c;
};

int main(){
  //Wave_Solution *ws = new Wave_Solution(arr_size, 0.5, 0.1);
  std::shared_ptr <double> shared_arr(arr, std::default_delete<double[]>());
  /*
  Analyzer *analyzer = new Analyzer(arr_size);
  analyzer->Bind_Solver( ws );
  std::cout << "aa" << std::endl;
  analyzer->Set_Target_ptr(shared_arr);
  std::cout << "aa" << std::endl;
  analyzer->Analyze();
  std::cout << "aa" << std::endl;
  analyzer->Release_Solver();
  std::cout << "aa" << std::endl;
  delete ws;
  std::cout << "aa" << std::endl;
  delete analyzer;
  std::cout << "aa" << std::endl;
  std::cout << shared_arr.use_count() << std::endl;
  std::cout << "aa" << std::endl;
  */

  return 0;
}
