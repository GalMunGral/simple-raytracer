
#include <cmath>
#include "vec.hh"

vec::vec() : vec(0, 0, 0){};
vec::vec(float x, float y, float z) : x(x), y(y), z(z){};

vec vec::operator+(vec o)
{
  return vec(x + o.x, y + o.y, z + o.z);
}

vec vec::operator-(vec o)
{
  return vec(x - o.x, y - o.y, z - o.z);
}

vec vec::operator*(float c)
{
  return vec(x * c, y * c, z * c);
}

vec operator*(float c, vec v)
{
  return v * c;
}

vec vec::operator/(float c)
{
  return vec(x / c, y / c, z / c);
}

float vec::dot(vec o)
{
  return x * o.x + y * o.y + z * o.z;
}

float vec::squared_norm()
{
  return dot(*this);
}

float vec::norm()
{
  return sqrt(squared_norm());
}

vec vec::normalize()
{
  return operator/(norm());
}

std::ostream &operator<<(std::ostream &os, vec v)
{
  os << "{ " << v.x << ',' << v.y << ',' << v.z << " }";
  return os;
}

std::ostream &operator<<(std::ostream &os, color c)
{
  os << "{ " << c.r << ',' << c.g << ',' << c.b << ',' << c.a << " }";
  return os;
}