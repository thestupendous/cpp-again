class MeriClass
{
	public:
  int x, y, z;

  // This method lets cereal know which data members to serialize
  template<class Archive>
  void serialize(Archive & archive)
  {
    archive( x, y, z ); // serialize things by passing them to the archive
  }
  MeriClass():x(0),y(0),z(0){}
  MeriClass(int a,int b,int c)
  {
	  x=a;
	  y=b;
	  z=c;
  }

};



