#include <cmath>
#include "vec.hh"

vec::vec() : vec(0, 0, 0){};
vec::vec(float x, float y, float z) : x(x), y(y), z(z){};

vec operator-(vec v)
{
  return vec(-v.x, -v.y, -v.z);
}

vec vec::operator+(vec o)
{
  return vec(x + o.x, y + o.y, z + o.z);
}

vec &vec::operator+=(vec o)
{
  x += o.x;
  y += o.y;
  z += o.z;
  return *this;
}

vec vec::operator-(vec o)
{
  return vec(x - o.x, y - o.y, z - o.z);
}

vec vec::operator*(float c)
{
  return c ? vec(x * c, y * c, z * c) : vec();
}

vec vec::operator*(vec o)
{
  return vec(x * o.x, y * o.y, z * o.z);
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

vec vec::cross(vec o)
{
  return vec(y * o.z - z * o.y, z * o.x - x * o.z, x * o.y - y * o.x);
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

vec vec::clamp()
{
  return vec(std::clamp(x, 0.0f, 1.0f),
             std::clamp(y, 0.0f, 1.0f),
             std::clamp(z, 0.0f, 1.0f));
}

std::ostream &
operator<<(std::ostream &os, vec v)
{
  os << "{ " << v.x << ',' << v.y << ',' << v.z << " }";
  return os;
}
