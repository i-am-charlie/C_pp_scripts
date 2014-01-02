#include "stdio.h"
#include "math.h"

/**
 * \brief This function will print a number to the console in the given base.
 * \param num The number to convert
 * \param base The base in which to print (2..16)
 */
void printNumInBase(int num, int base) {
  // Loop variable(s)
   int i;
  
  // Create a static array of the digits for use up to base 16
  char digits[] = {'0', '1', '2', '3',
                   '4', '5', '6', '7',
                   '8', '9', 'A', 'B',
                   'C', 'D', 'E', 'F'};

  // Determine the number of digits in the final string
  int length = (int)(log(num)/log(base) + 0.5);

  // Print out each digit
  for (i = 0; i < length; ++i) {
    // Use the base digit calculation
    int digit = (int)(num / pow(base, length-i-1)) % base;

    // Print out the determined character
    printf("%c", digits[digit]);
  }
  
  // Print out a newline at the end for good measure
  printf("\n");
}
  
/**
* \brief Entry point for the program
*/
int main() {
  // Create a integral value
  int two = 2;
  
  // Create variables for later
  int six, nine;
  
  // Increment the value of two
  two++;
  
  // Assign to new integer values
  six = 2 * two;
  nine = two * two;
  
  // Print values
  printf("What do you get when you multiply %d by %d?\n", six, nine);
  
  // Print the answer, decrementing two inline
  printNumInBase(six * nine, six + nine - --two);
}
