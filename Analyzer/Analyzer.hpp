#ifndef ALZ_HPP
#define ALZ_HPP

#include <memory>

class SolutionInterface {
public:
  virtual void Solve(double *) = 0;
  virtual ~SolutionInterface();
};

class Analyzer {
public:
  explicit Analyzer (int);
  ~Analyzer ();
  void Set_Target_ptr (double *);
  void Bind_Solver(SolutionInterface *);
  void Release_Solver();
  void Analyze ();
private:
  int size;
  SolutionInterface *solver;
  double *target_ptr;
};

#endif
