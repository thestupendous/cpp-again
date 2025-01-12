class MeriClass
{
  int x, y, z;

  // This method lets cereal know which data members to serialize
  template<class Archive>
  void serialize(Archive & archive)
  {
    archive( x, y, z ); // serialize things by passing them to the archive
  }
};



