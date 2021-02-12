#include "sender.hpp"
#include <stdio.h>
#include <string>
#include <memory>
#include <iostream>

Sender::Sender (const std::shared_ptr<double>& set_ptr){
  Set_Target_ptr(set_ptr);
  StartX = 0; EndX = 1; StartY = 0; EndY = 0;
  if(!StartGnuplot()){
    std::cout << "failed to start gnuplot." << std::endl;
  }
}
Sender::~Sender (){
  if (!gnuplot){
  fflush(gnuplot);
  fclose(gnuplot);
  }
}
bool Sender::SuccessGnuplot(){ return gnuplot ? true : false; }
void Sender::SetXrange (int StartX, int EndX){
  this->StartX = StartX; this->EndX = EndX;
  fprintf(gnuplot, "se xrange [%d:%d]\n", StartX, EndX);
}
void Sender::SetYrange (int StartY, int EndY){
  this->StartY = StartY; this->EndY = EndY;
  fprintf(gnuplot, "se yrange [%d:%d]\n", StartY, EndY);
}
void Sender::Set_Target_ptr (const std::shared_ptr<double>& set_ptr){
  target_ptr = set_ptr;
}
bool Sender::StartGnuplot (){
  if((gnuplot = popen("gnuplot", "w")) == NULL) return false;
  else return true;
}
void Sender::SendData (){
  fprintf(gnuplot, "plot sin(x)\n");
  fflush(gnuplot);
}
