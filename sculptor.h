#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <string>
#include <vector>

using namespace std;

struct Voxel {

  int r,g,b,a;
  bool isOn;
};

class Sculptor {
protected:

  Voxel ***v;
  int nx,ny,nz;
  int r,g,b,a;

public:

  Sculptor(int tx,int ty,int tz);

  void setColor(int _r, int _g, int _b, int alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  vector<std::vector<Voxel>> readMx (int dim, int plane);
  void writeOFF(const string filename);

  void writeVECT(const string filename);

  ~Sculptor();
};
#endif // SCULPTOR_H
