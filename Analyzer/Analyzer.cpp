#include "Analyzer.hpp"
#include <memory>
#include <iostream>

SolutionInterface::~SolutionInterface() {
  target_arr = NULL;
}

Analyzer::Analyzer (int size){
  this->size = size;
}
Analyzer::~Analyzer (){
  if(!solver) delete solver;
  target_ptr = nullptr;
}
void Analyzer::Set_Target_ptr(const std::shared_ptr<double>& set_ptr) {
  target_ptr = set_ptr;
}
void Analyzer::Bind_Solver(SolutionInterface *solver){
  this->solver = solver;
}
void Analyzer::Release_Solver(){
  solver = NULL;
}
void Analyzer::Analyze(){
  if(solver) solver->Solve();
  else std::cout << " solver object was not assignmeted.";
}
