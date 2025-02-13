#include <fstream>
#include <iostream>

struct GameObject {
  int field1;
  short field2;
  bool active;
  char padding[1]; // can put interesting value here
                   // to make it meaningful
	GameObject(){}

  GameObject(int f1, short f2, bool ac) : field1(f1), field2(f2), active(ac) {}

  // serialize function
  void Serialize(std::ostream &os) const {
    os.write(reinterpret_cast<const char *>(&field1), sizeof(field1));
    os.write(reinterpret_cast<const char *>(&field2), sizeof(field2));
    os.write(reinterpret_cast<const char *>(&active), sizeof(active));
    os.write(padding, sizeof(padding));
  }

  void Deserialize(std::istream &is) {
    is.read(reinterpret_cast<char *>(&field1), sizeof(field1));
    is.read(reinterpret_cast<char *>(&field2), sizeof(field2));
    is.read(reinterpret_cast<char *>(&active), sizeof(active));
    is.read(padding, sizeof(padding));
  }
};

  std::ostream &operator<<(std::ostream &os, const GameObject &g1) {
    os << g1.field1 << ' ' << g1.field2 << ' ' << g1.active;
    return os;
  }

  int main() {
    // start new scope - jisse apni std::ofstream apneaap close()
    //   ho jayegi
    {
      std::cout << "sizeof GAmeobject " << sizeof(GameObject) << '\n';
      GameObject g1(450, -3, 0);
      std::cout << g1 << '\n';

      // write to file - text version
      std::ofstream oStream("game-save.txt");
      oStream << g1 << '\n';

      // write to file - text version
      std::ofstream oStreamBin("game-save.bin", std::ios::binary);
      g1.Serialize(oStreamBin);
		}


		//second try - bin file read karne ko
		{
			//deserialize 
			GameObject g2;
			std::ifstream iStreamBin("game-save.bin",std::ios::binary);
			g2.Deserialize(iStreamBin);
			std:: cout << "read object " << g2 << '\n';
    }

    return 0;
  }
