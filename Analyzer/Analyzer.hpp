#ifndef ALZ_HPP
#define ALZ_HPP

#include <memory>

class SolutionInterface {
public:
  virtual void Solve() = 0;
  virtual ~SolutionInterface();
  double *target_arr;
};

class Analyzer {
public:
  explicit Analyzer (int);
  ~Analyzer ();
  void Set_Target_ptr (const std::shared_ptr<double>&);
  void Bind_Solver(SolutionInterface *);
  void Release_Solver();
  void Analyze ();
private:
  int size;
  SolutionInterface *solver;
  std::shared_ptr<double> target_ptr;
};

#endif
