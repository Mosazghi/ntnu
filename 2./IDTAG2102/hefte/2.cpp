#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


template <typename Key, typename T>
class Map {
  
  private:
    Key* key;
    T* data; 
    int antall, kapasitet; 

    int getKeyIndex(const Key k) {
      int i = 0;

      while (i < antall) {
        if(key[i] == k) {
          cout << "\nindex: " << i; 
          return i;
          break;
        }
        i++;
      }
      return -1;       
    }
   
  public:
    Map(const int kapasitet = 100) {this->kapasitet = kapasitet; antall = 0; key = new Key[kapasitet]; data = new T[kapasitet];}
    ~Map() {delete[] key; delete[] data;};
    
    void display() {
      if(!empty()) {
        for (int i = 0;  i < antall;  i++)
          cout << " **" << key[i] << ": " << data[i] << "**";
        cout << "\n\t'antall': " << antall << ", kap: "<<  kapasitet << '\n';
      }
    }

    bool empty() {return antall == 0;}

    void push(const Key k, const T t) {
      if(antall < kapasitet) {
        if(!findKey(k)) {
          key[antall] = k; 
          data[antall] = t;
          antall++; 
        } else
            cout << "\nKey already exist!\n";
      } else
          cout << "\nMap size exceeded!\n";
    }

    bool findKey(const Key k) {
      return find(key, key + antall, k) != key + antall;
    }

    T getData(const Key k) {
      if(findKey(k) < 0) {
        cout << "\nKey does not exist!\n";
        return T();
      }

      int keyIndex = getKeyIndex(k);
      if(keyIndex) {
        return data[keyIndex];
      } 
      return T();
    }

    void put(const Key k, const T t) {
      int keyIndex; 
      if(!empty()) {
        keyIndex = getKeyIndex(k);       
        if(keyIndex > 0) {
          cout << "\nGot index: " << keyIndex << endl;
          data[keyIndex] = t; 
        } else
            cout << "\nKey does not exist\n";
      } else
          cout << "\nMap empty!\n";
    }

    void remove(const Key k) {
      Key* newKey; 
      T* newData; 

      if(!empty()) {
        if(findKey(k)) {
          newKey = new Key[kapasitet];
          newData = new T[kapasitet];
          for(int i = 0; i < antall; i++) {
            if(key[i] != k) {
              newKey[i] = key[i];
              newData[i] = data[i];
            }
          }
          antall--;
          delete [] key;  
          delete [] data;

          key = newKey; 
          data = newData;
        } else
          cout << "\nKey not found!\n";
      } else
          cout << "\nMap empty!\n";
    }

};

int main() {
  Map<string, string> m;
  m.push("Gjovik", "Nyligst");
  m.push("Levanger", "First & Best");
  m.push("Trondheim", "Master");
  m.push("Oslo", "Jobss");
  m.display();
  m.remove("Oslo");
  m.remove("Levanger");
  m.display();
  return 0;
}
 
