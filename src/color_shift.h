#ifdef    MONO_BUILD
#define COLOR_SHIFT_IMPLEMENTATION
#undef MONO_BUILD
#endif // MONO_BUILD
#ifndef    _COLOR_SHIFT_H_
#define    _COLOR_SHIFT_H_
// color_shift interface

#include <raylib.h>
#include "type_math.h"

typedef struct sColorShift {
  Color color_start;
  Color color_end;
  float progress;
} ColorShift;

ColorShift cs_new(Color start, Color end);
void cs_update(ColorShift* self);
Color cs_get_color(ColorShift self);

#ifdef      COLOR_SHIFT_IMPLEMENTATION
// color_shift implementation

ColorShift cs_new(Color start, Color end) {
  ColorShift self = {0};

  self.color_start = start;
  self.color_end   = end;

  self.progress    = 0.0f;

  return self;
}
void cs_update(ColorShift* self) {
  self->progress += 0.01f;
  if (self->progress > 1.0f) {
    self->progress = 0.0f;
  };
}
Color cs_get_color(ColorShift self) {
  Color lerped = {0};
  lerped.r = uc_lerp(self.color_start.r, self.color_end.r, self.progress);
  lerped.g = uc_lerp(self.color_start.g, self.color_end.g, self.progress);
  lerped.b = uc_lerp(self.color_start.b, self.color_end.b, self.progress);
  lerped.a = uc_lerp(self.color_start.a, self.color_end.a, self.progress);

  return lerped;
}


#endif   // COLOR_SHIFT_IMPLEMENTATION
#endif   //_COLOR_SHIFT_H_

