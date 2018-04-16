#ifndef _THREE_MOMENTUM_SIMPLE_H
#define _THREE_MOMENTUM_SIMPLE_H

#include<string>
#include<iostream>
#include<sstream>
#include<cassert>
#include<cstdlib>
#include<array>

class basemom
{
  int p[3];

public:

  basemom()
  {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
  }

  explicit basemom(int same_value)
  {
    p[0] = same_value;
    p[1] = same_value;
    p[2] = same_value;
  }

  basemom(int x, int y, int z)
  {
    p[0] = x;
    p[1] = y;
    p[2] = z;
  }

//  basemom(int x[3])  
//  {
//    memcpy(p, x, 3*sizeof(int));
//  }

  int &operator()(int x)
  {
    assert(x >= 0 && x < 3);
    return p[x];
  }
  
  int &operator[](int x)
  {
    assert(x >= 0 && x < 3);
    return p[3];
  }

  int nzero()
  {
    int nz=0;
    for(auto i:p)
    {
      if(i == 0)
        nz++;
    }
    return nz;
  }

//this is implemented by Chris, which is designed for file_name
//devide_by=2 connect my convention with Chris, and - is replaced by _
  std::string file_str(const int divide_by = 1) const{
    std::ostringstream os;
    for(int i=0;i<3;i++)
    {
      if(p[i] < 0) os << '_';
      assert(abs(p[i]) % divide_by == 0 && "Error: when convert basemom to file_str, has to make sure mom is integer multiples of devide num\n");
      os << abs(p[i]/divide_by);
    }
    return os.str();
  }

  basemom operator-()
  {
    return basemom(-p[0], -p[1], -p[2]);
  }
  
  bool operator==(const basemom &r) const
  {
    return p[0]==r.p[0] && p[1]==r.p[1] && p[2]==r.p[2] ;
  }
  
  bool operator!=(const basemom &r) const
  {
    return p[0]!=r.p[0] || p[1]!=r.p[1] || p[2]!=r.p[2] ;
  }

  basemom &operator+=(const basemom &r)
  {
    for(int i=0; i<3; i++)
      p[i] += r.p[i];
    return *this;
  }

  basemom operator+(const basemom &r) const
  {
    basemom tmp(p[0],p[1],p[2]);
    tmp += r;
    return tmp;
  }

  basemom &operator-=(const basemom &r)
  {
    for(int i=0; i<3; i++)
      p[i] -= r.p[i];
    return *this;
  }

  basemom operator-(const basemom &r) const
  {
    basemom tmp(p[0],p[1],p[2]);
    tmp -= r;
    return tmp;
  }
};

class pion_basemom_container
{
  std::array<basemom,8> basemom_data;
  int underline_component[2] = {2,-2};

public:

  pion_basemom_container()
  {
    int x[3];
    for(int i=0; i<8; i+=2)
    {
//Although i'm quite satisfied with the following way of initialization, it's better to be consistent with Chris's initialization in cps
//      int x = i%2;
//      int y = (i>>1)%2;
//      int z = (i>>2)%2;
//      basemom_data[i] = basemom(underline_component[x],underline_component[y],underline_component[z]);
      for(int n=0; n<3; n++)
        x[n] = 0;
      if(i!=0)
        x[i/2-1] =1;
      basemom_data[i] = basemom(underline_component[x[0]],underline_component[x[1]],underline_component[x[2]]);
      basemom_data[i+1] = -basemom_data[i];
    }
  }

  basemom &operator()(int x)
  {
    return basemom_data.at(x);
  }

  std::string operator[](int x) const
  {
    return basemom_data.at(x).file_str();
  } 
};

void code_to_pidx(int code, int &psrc1, int &psrc2, int &psnk1, int &psnk2)
{
  assert(!(code<0 || code>4095));
  psnk2 = code%8;
  psnk1 = (code>>3)%8;
  psrc2 = (code>>6)%8;
  psrc1 = (code>>9)%8;
}

void code_to_pidx(int code, int &psrc, int &psnk)
{
  assert(!(code<0 || code>63));
  psnk = code%8;
  psrc = (code>>3)%8;
}

void pidx_to_code(int &code, int psrc1, int psrc2, int psnk1, int psnk2)
{
  assert(!(psrc1<0 || psrc1>7 || psrc2<0 || psrc2>7 || psnk1<0 || psnk1>7 || psnk2<0 || psnk2>7));
  code = 0;
  code += psrc1;
  code *= 8;
  code += psrc2;
  code *= 8;
  code += psnk1;
  code *= 8;
  code += psnk2;
}

void pidx_to_code(int &code, int psrc, int psnk)
{
  assert(!(psrc<0 || psrc>7 || psnk<0 || psnk>7));
  code = 0;
  code += psrc;
  code *= 8;
  code += psnk;
}
#endif
