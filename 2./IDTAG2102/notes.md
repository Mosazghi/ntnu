# Attention

### Sletter siste og minker antall

```cpp
T pop() {                     
      if (!empty())           
          return (data[--antall]);    // <- Siste har indeks:  antall-1 
      else
          cout << "\nStack is empty!\n\n";      
      return T();
  }
```
