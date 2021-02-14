#include "Analyzer.hpp"
#include <memory>
#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>
#include <windows.h>
#define arr_size 20
#define PI 3.14159265359f

double arr[arr_size] = {};
double initial_arr[arr_size] = {};
double speed_arr[arr_size] = {};
FILE *fp;

class Wave_Solution : public SolutionInterface{
public:
  Wave_Solution(int set_size, double set_delta_t, double set_delta_x, double set_c, double* set_initial_datas, double *set_speed_datas)
  : size(set_size-1), delta_t(set_delta_t), delta_x(set_delta_x), c(set_c){
    lambda = (c*delta_t/delta_x)*(c*delta_t/delta_x);
    now_datas = new double[set_size];
    old_datas = new double[set_size];
    memcpy(old_datas, initial_arr, set_size*sizeof(double));
    for(int i = 0; i <= size; i++){
      if (i == 0){
        now_datas[0] = old_datas[0] + delta_t*set_speed_datas[0] + lambda*(old_datas[1] - old_datas[0]);
      } else if(i == size){
        now_datas[size] = old_datas[size] + delta_t*set_speed_datas[size] + lambda*(old_datas[size-1] - old_datas[size]);
      } else{
        now_datas[i] = old_datas[i] + delta_t*set_speed_datas[i] + lambda*(old_datas[i-1] - 2*old_datas[i] + old_datas[i+1])/2;
      }
    }
  }
  void Solve (double *target_ptr){
    for(int i = 0; i <= size; i++){
      if (i == 0){
        target_ptr[0] = 2*now_datas[0] - old_datas[0] + 2*lambda*(now_datas[1] - now_datas[0]);
      } else if(i == size){
        target_ptr[size] = 2*now_datas[size] - old_datas[size] + 2*lambda*(now_datas[size-1] - now_datas[size]);
      } else{
        target_ptr[i] = 2*now_datas[i] - old_datas[i] + 2*lambda*(now_datas[i-1] - 2*now_datas[i] + now_datas[i+1]);
      }
    }
    memcpy(old_datas, now_datas, (size+1)*sizeof(double));
    memcpy(now_datas, target_ptr, (size+1)*sizeof(double));
    //for (int i = 0; i <= size; i++) printf("%4.3f, ", target_ptr[i]);
    //printf("\n");

    fputs("plot '-' with lines\n", fp);
    for (int i = 0; i <= size; i++) fprintf(fp, "%d, %lf\n", i, target_ptr[i]);
    fputs("e\n", fp);
  }
  ~Wave_Solution(){}
private:
  double *old_datas, *now_datas;
  const int size;
  double delta_t, delta_x, c, lambda;
};

void initial_setting(double *arr){
  for(int i = 0; i < arr_size; i++){
    arr[i] = i*(arr_size-1 - i)*sin(2*i*PI/arr_size)/(arr_size/2)/(arr_size/2);
  }
}

int main(){
  int count = 0, limit = 2000;
  fp = fopen("result.txt", "w");
  fprintf(fp, "se xrange [0:%d]\n", arr_size);
  fprintf(fp, "se yrange [-1:1]\n");

  initial_setting(initial_arr);
  //initial_setting(speed_arr);

  Wave_Solution *ws = new Wave_Solution(arr_size, 0.1, 0.5, 0.1, initial_arr, speed_arr);
  Analyzer *analyzer = new Analyzer(arr_size);
  analyzer->Bind_Solver( ws );
  analyzer->Set_Target_ptr(arr);
  while(!kbhit() && count < limit){
    analyzer->Analyze();
    count++;
  }

  fclose(fp);

  return 0;
}
