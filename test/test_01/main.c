#include<iostream>

#include "three_momentum_simple.h"

using std::cout;
int main()
{
  pion_basemom_container pion_mom;
  for(int i=0; i<8; i++)  
  {
    cout << pion_mom[i] << '\n';
  }
  basemom p1 = pion_mom(2);
  basemom p2 = pion_mom(5);
  basemom p3 = p1 + p2;
  cout << p3.file_str() << '\n';
  cout << (-p3).file_str() << "\n";
  cout << p3.nzero() << "\n";
  int code=0;
  pidx_to_code(code,1,6,3,3);
  cout << code << '\n';
  int a,b,c,d;
  code_to_pidx(code,a,b,c,d);
  cout << a <<' '<<b<<' '<<c<<' '<<d<<'\n';
  return 1;
}
