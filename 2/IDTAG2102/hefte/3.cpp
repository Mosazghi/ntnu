#include <iostream>

int main() {
  // ( ( ( 4 + 2 ) + ( 3 * 2 ) ) + ( ( 3 + 4 ) * ( 2 * 5 ) ) )
  
  // POSTFIX (a): 
  // 4 2 + 3 2 * + 3 4 + 2 5 * * + 
  /* 
                           * 
             *       +   * * *
     _ + _ + + + _ + + + + + + + _ 

    POSTFIX (b):
      ( ( 7 * 3 ) + ( ( ( 4 * 5 ) * ( 3 + 2 ) ) * ( 6 + 3 ) ) )
      7 3 * 4 5 * 3 2 + * 6 3 + * +

                  +       +
            *   * * *   * * *
    _ * _ + + + + + + + + + + + _   
  */






  return 0;
}