#pragma once

#include <vector>
#include <string>
#include "vec.hh"
#include "lodepng.h"
#include "texture.hh"

class object
{
public:
  virtual ~object() = 0;
  virtual float intersect(vec o, vec dir) = 0;
  virtual vec norm_at(vec p) = 0;
  virtual color color_at(vec p) = 0;
};

class sphere : public object
{
public:
  vec c;
  float r;
  color _color;
  sphere(float x, float y, float z, float r, color color)
      : c(x, y, z), r(r), _color(color){};
  ~sphere();
  float intersect(vec o, vec dir);
  vec norm_at(vec p);
  color color_at(vec p);
};

class plane : public object
{
public:
  float a, b, c, d;
  color _color;
  plane(float a, float b, float c, float d, color color) : a(a), b(b), c(c), d(d), _color(color){};
  ~plane();
  float intersect(vec o, vec dir);
  vec norm_at(vec p);
  color color_at(vec p);
};

class triangle : public object
{
public:
  vec p0, p1, p2, n0, n1, n2, st0, st1, st2, e1, e2;
  texture *_texture;
  color _color;
  triangle(vec p0, vec p1, vec p2, vec n0, vec n1, vec n2,
           vec st0, vec st1, vec st2, texture *texture, color color);
  ~triangle();
  float intersect(vec o, vec dir);
  vec norm_at(vec p);
  color color_at(vec p);
};

class light
{

public:
  virtual ~light() = 0;
  virtual vec dir(vec) = 0;
  virtual color intensity(vec) = 0;
  virtual float dist(vec) = 0;
};

class directional_light : public light
{
  vec _dir;
  color _color;

public:
  ~directional_light();
  directional_light(vec dir, color color) : _dir(dir), _color(color){};
  vec dir(vec o);
  color intensity(vec o);
  float dist(vec o);
};

class point_light : public light
{
  vec _pos;
  color _color;

public:
  ~point_light();
  point_light(vec pos, color color) : _pos(pos), _color(color){};
  vec dir(vec o);
  color intensity(vec o);
  float dist(vec o);
};

class scene
{
public:
  int width, height, aa = 1, d = 0;
  std::string filename;
  std::vector<object *> objects;
  std::vector<light *> lights;
};

scene parse(char *filename);
