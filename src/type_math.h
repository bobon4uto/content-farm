#ifdef    MONO_BUILD
#define TYPE_MATH_IMPLEMENTATION
#undef MONO_BUILD
#endif // MONO_BUILD
#ifndef    _TYPE_MATH_H_
#define    _TYPE_MATH_H_
// type_math interface

// :macro
#define m_min(a, b) ( (a) > (b) ? (b) : (a) )
#define m_max(a, b) ( (a) > (b) ? (a) : (b) )

unsigned char uc_lerp(unsigned char start, unsigned char end, float pos);

#ifdef      TYPE_MATH_IMPLEMENTATION
// type_math implementation

unsigned char uc_lerp(unsigned char start, unsigned char end, float pos) {
  unsigned char ret = 0;
  if (end >= start) {
    unsigned char diff = end - start;
    ret = start + (unsigned char)(((float)diff) * pos);
  } else {
    unsigned char diff = start - end;
    ret = start - (unsigned char)(((float)diff) * pos);
  }
  return ret;
}


#endif   // TYPE_MATH_IMPLEMENTATION
#endif   //_TYPE_MATH_H_

