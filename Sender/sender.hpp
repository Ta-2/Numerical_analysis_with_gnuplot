#ifndef SND_HPP
#define SND_HPP
#include <memory>
#include <string>
#include <string>

class Sender{
public:
  explicit Sender (const std::shared_ptr<double>&);
  ~Sender ();
  void Set_Target_ptr (const std::shared_ptr<double>&);
  bool SuccessGnuplot();
  void SendData ();
  void SetXrange (int, int);
  void SetYrange (int, int);
private:
  bool StartGnuplot();
  FILE *gnuplot;
  int StartX, EndX;
  int StartY, EndY;
  std::shared_ptr<double> target_ptr;
};

#endif
