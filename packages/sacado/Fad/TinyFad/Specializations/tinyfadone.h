// @HEADER
// *****************************************************************************
//                           Sacado Package
//
// Copyright 2006 NTESS and the Sacado contributors.
// SPDX-License-Identifier: LGPL-2.1-or-later
// *****************************************************************************
// @HEADER

#ifndef _tinyfadone_h_
#define _tinyfadone_h_

//*********************************************************
// This file is generated by generate.cc.
// Use this file for any modification
//*********************************************************

template <class T> class TinyFad<1,T> {
public:
  typedef T value_type;
  typedef T grad_type;
protected:

  int n;
  T val_;

  T dx0_;


public:
  void diff(const size_t ith, const size_t sz){
     n = ith+1;
     dx0_ = T(0.);

     switch(ith){
     case 0 : dx0_ = T(1.);break;
     default : std::cout << "ith = " << ith << "  out of definition set" << std::endl;exit(1);
     }
  }

  TinyFad(const T& ind, const int ini) : n(ini+1), val_(ind) {
     dx0_ = T(0.);

     switch(ini){
     case 0 : dx0_ = T(1.);break;
     default : std::cout << "ini = " << ini << "  out of definition set" << std::endl;exit(1);
     }
  }
  TinyFad() : n(0), val_(0.) {
     dx0_ = T(0.);
  }
  TinyFad(const No_Initialization &): n(0) {}
  TinyFad(const T& in) : n(0), val_(in) {
     dx0_ = T(0.);
  }
  TinyFad(const TinyFad<1,T> & in) : n(0), val_(in.val_) {
     dx0_ = in.dx0_;
  }

  ~TinyFad() {}

  int    N()       const {return n-1;}

  const T& val()     const { return val_;}
  T& val()                 { return val_;}

  const T& d0() const { return dx0_;}
  T& d0() { return dx0_;}

  T& dx(int i){
     switch(i){
     case 0 : return dx0_;
     default : std::cout << "i out of bounds" << std::endl;exit(1);
     }
  }
  const T& dx(int i) const {
     switch(i){
     case 0 : return dx0_;
     default : std::cout << "i out of bounds" << std::endl;exit(1);
     }
  }
  T& d(int i){
     switch(i){
     case 0 : return dx0_;
     default : std::cout << "i out of bounds" << std::endl;exit(1);
     }
  }
  const T& d(int i) const {
     switch(i){
     case 0 : return dx0_;
     default : std::cout << "i out of bounds" << std::endl;exit(1);
     }
  }

  TinyFad<1,T> & operator = (const TinyFad<1,T> & in){
     val_ = in.val_;

     dx0_ = in.dx0_;

     return *this;
  }

  TinyFad<1,T> & operator = (const T & in){
     val_ = in;

     dx0_ = T(0.);

     return *this;
  }

  TinyFad<1,T> & operator += (const TinyFad<1,T> & in){
     dx0_ += in.dx0_;
     val_ += in.val_;


    return *this;
  }
  TinyFad<1,T> & operator -= (const TinyFad<1,T> & in){
     dx0_ -= in.dx0_;
     val_ -= in.val_;

     return *this;
  }
  TinyFad<1,T> & operator *= (const TinyFad<1,T> & in){
     dx0_ = dx0_ * in.val_ + val_ * in.dx0_;
     val_ *= in.val_;

     return *this;
  }
  TinyFad<1,T> & operator /= (const TinyFad<1,T> & in){
     if (in.val_ == 0.) error("TinyFad & TinyFad::operator /= (const TinyFad & in), dividing by 0");
     dx0_ = ( dx0_ * in.val_ - val_ * in.dx0_ ) / in.val_ / in.val_ ;
     val_ /= in.val_;

     return *this;
  }

  TinyFad<1,T> & operator += (const T & in){     val_ += in;

     return *this;
  }
  TinyFad<1,T> & operator -= (const T & in){     val_ -= in;

     return *this;
  }
  TinyFad<1,T> & operator *= (const T & in){
     val_ *= in;

     dx0_ *= in;

     return *this;
  }
  TinyFad<1,T> & operator /= (const T & in){
     if ( in == T(0.) ) error("TinyFad & TinyFad::operator /= (const T & in), dividing by 0");
     val_ /= in;

     dx0_ /= in;

     return *this;
  }

  TinyFad<1,T> operator++(int){
     TinyFad<1,T> tmp(*this);
     tmp.val_++;
     return tmp;
  };
  TinyFad<1,T> operator--(int){
     TinyFad<1,T> tmp(*this);
     tmp.val_--;
     return tmp;
  };
  TinyFad<1,T> & operator++(){     ++val_;
     return *this;
  }
  TinyFad<1,T> & operator--(){     --val_;
     return *this;
  }
};


template <class T> inline TinyFad<1,T> operator + (const TinyFad<1,T>& in)
{
  return TinyFad<1,T>(in);
}

template <class T> inline TinyFad<1,T> operator - (const TinyFad<1,T>& in)
{
  TinyFad<1,T> tmp;
  tmp -= in;
  return tmp;
}

template <class L, class R> inline
TinyFad<1,typename NumericalTraits<L,R>::promote >
operator +(const TinyFad<1,L>& un, const TinyFad<1,R>& deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  No_Initialization nothing;
  TinyFad<1,value_type> tmp( nothing );

  tmp.d0() = un.d0() + deux.d0();

  tmp.val() = un.val() + deux.val();

  return tmp;
}

template <class L, class R> inline
TinyFad<1,typename NumericalTraits<L,R>::promote>
operator +(const TinyFad<1,L>& un, const R& deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  No_Initialization nothing;
  TinyFad<1,value_type> tmp( nothing );

  tmp.d0() = un.d0();

  tmp.val() = un.val() + deux;

  return tmp;
}

template <class L, class R> inline
TinyFad<1,typename NumericalTraits<L,R>::promote >
operator +(const L& un, const TinyFad<1,R>& deux) {
  return operator +(deux,un);
}

template <class L, class R> inline
TinyFad<1,typename NumericalTraits<L,R>::promote >
operator *(const TinyFad<1,L>& un, const TinyFad<1,R>& deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  No_Initialization nothing;
  TinyFad<1,value_type> tmp( nothing );

  tmp.d0() = un.d0()*deux.val() + un.val() * deux.d0();

  tmp.val() = un.val() * deux.val();

  return tmp;
}

template <class L, class R> inline
TinyFad<1,typename NumericalTraits<L,R>::promote >
operator *(const TinyFad<1,L>& un, const R& deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  No_Initialization nothing;
  TinyFad<1,value_type> tmp( nothing );

  tmp.d0() = un.d0()*deux;

  tmp.val() = un.val() * deux;

  return tmp;
}

template <class L, class R> inline
TinyFad<1,typename NumericalTraits<L,R>::promote >
operator *(const L& un, const TinyFad<1,R>& deux) {

  return operator *(deux,un);
}


template <class L, class R> inline
TinyFad<1,typename NumericalTraits<L,R>::promote >
operator -(const TinyFad<1,L> & un, const TinyFad<1,R> & deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  No_Initialization nothing;
  TinyFad<1,value_type> tmp( nothing );

  tmp.d0() = un.d0() - deux.d0();

  tmp.val() = un.val() - deux.val();

  return tmp;
}

template <class L, class R> inline
TinyFad<1,typename NumericalTraits<L,R>::promote>
operator -(const L & un, const TinyFad<1,R> & deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  No_Initialization nothing;
  TinyFad<1,value_type> tmp( nothing );

  tmp.d0() -= deux.d0();

  tmp.val() = un - deux.val();

  return tmp;
}

template <class L, class R> inline
TinyFad<1, typename NumericalTraits<L,R>::promote >
operator -(const TinyFad<1,L> & un, const R & deux) {
  typedef typename NumericalTraits<L,R>::promote value_type;

  No_Initialization nothing;
  TinyFad<1,value_type> tmp( nothing );

  tmp.d0() = un.d0();

  tmp.val() = un.val() - deux;

  return tmp;
}

template <class L, class R> inline
TinyFad<1, typename NumericalTraits<L,R>::promote >
operator /(const TinyFad<1,L> & un, const TinyFad<1,R> & deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  if (deux.val() == 0.) error("TinyFad & TinyFad::operator /(const TinyFad<1,L> & un, const TinyFad<1,R> & deux), dividing by 0");

  No_Initialization nothing;
  TinyFad<1,value_type> tmp( nothing );
  value_type dval = deux.val();

  tmp.d0() = ( un.d0()* deux.val() - un.val() * deux.d0() ) / dval / dval ;

  tmp.val() = un.val() / dval;

  return tmp;
}

template <class L, class R> inline
TinyFad<1, typename NumericalTraits<L,R>::promote >
operator /(const L & un, const TinyFad<1,R> & deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  if (deux.val() == 0.) error("TinyFad & TinyFad::operator /(const L & un, const TinyFad<1,R> & deux), dividing by 0");

  No_Initialization nothing;
  TinyFad<1,value_type> tmp( nothing );
  value_type dval = deux.val();

  tmp.d0() = - un * deux.d0()  / dval / dval ;

  tmp.val() = un / dval;

  return tmp;
}

template <class  L, class R> inline
TinyFad<1, typename NumericalTraits<L,R>::promote >
operator /(const TinyFad<1,L> & un, const R & deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  if (deux == 0.) error("TinyFad & TinyFad::operator /(const TinyFad<1,L> & un, const R & deux), dividing by 0");

  No_Initialization nothing;
  TinyFad<1,value_type> tmp( nothing );

  tmp.d0() = un.d0()  / deux;

  tmp.val() = un.val() / deux;

   return tmp;
}

template <class T> TinyFad<1,T> exp (const TinyFad<1,T>& in)
{
  TinyFad<1,T> tmp(exp(in.val()));

  tmp.d0() = in.d0()*exp(in.val());

  return tmp;
}

template <class T> TinyFad<1,T> log (const TinyFad<1,T>& in)
{
  if ( in.val() <= 0) error("TinyFad log (const TinyFad& in) : zero or negative value");
  TinyFad<1,T> tmp(log(in.val()));

  tmp.d0() = in.d0() / in.val();

  return tmp;
}

template <class T> TinyFad<1,T> sqrt (const TinyFad<1,T>& in)
{
  if ( in.val() < 0. ) error("TinyFad<1,T> sqrt (const TinyFad& in) : negative value");
  TinyFad<1,T> tmp(sqrt(in.val()));

  bool test=true;
  if ( in.val() == T(0.) ){
    if ( in.d0() != T(0.) ) test = false;

    if ( !test )
      error("TinyFad<1,T> sqrt (const TinyFad& in) : null value");
  }
  else {
    tmp.d0() = in.d0() / sqrt(in.val()) / 2.;
  }

  return tmp;
}

template <class T> TinyFad<1,T> sin (const TinyFad<1,T>& in)
{
  TinyFad<1,T> tmp( sin(in.val()) );

  tmp.d0() = in.d0() * cos( in.val() );

  return tmp;
}

template <class T> TinyFad<1,T> cos (const TinyFad<1,T>& in)
{
  TinyFad<1,T> tmp(cos(in.val()));

  tmp.d0() = - in.d0() * sin( in.val() );

  return tmp;
}

template <class T> TinyFad<1,T> tan (const TinyFad<1,T>& in)
{
  if ( in.val() == 0) error("TinyFad tan (const TinyFad& in) undiefined in 0.");
  TinyFad<1,T> tmp(tan(in.val()));

  T cosinus = cos(in.val());
  tmp.d0() = in.d0() / cosinus / cosinus;

  return tmp;
}

template <class T> TinyFad<1,T> pow (const TinyFad<1,T>& in, double e)
{
  TinyFad<1,T> tmp(pow(in.val(), e));

  tmp.d0() = e*in.d0()*pow(in.val(), e-1);

  return tmp;
}

template <class T> TinyFad<1,T> pow (const TinyFad<1,T>& un, const TinyFad<1,T>& deux)
{
  if (un.val() == 0) error("TinyFad pow (const TinyFad& un, const TinyFad& deux), un = 0. ");
  TinyFad<1,T> tmp(pow(un.val(), deux.val()));

  tmp.d0() = deux.d0() * log(un.val()) * pow(un.val(), deux.val())
	    + deux.val() * un.d0() * pow(un.val(), deux.val()-1);

  return tmp;
}

template <class T> TinyFad<1,T> pow (const TinyFad<1,T>& in, const int e)
{
  TinyFad<1,T> tmp( std::pow((double)in.val(), (double)e) );

  tmp.d0() = e*in.d0()*std::pow((double)in.val(), (double)e-1);

  return tmp;
}

template <class T> TinyFad<1,T> abs (const TinyFad<1,T>& in)
{
  int sign = in.val() > 0? 1:0;

  if (sign) return in;
  else return (-in);
}

template <class T> std::ostream& operator << (std::ostream& os, const TinyFad<1,T>& a)
{
  os.setf(std::ios::fixed,std::ios::scientific);
  os.width(12);
  os << a.val() << "  [";

  os.width(12);
  os << a.d0();

  os << "]";

  return os;
}


#endif
