/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */

 #include "deletable_primes.h"
 #include <math.h>

 unsigned long remove_digit(int index, unsigned long number)
 {
   unsigned long leftNumber = 0;
   unsigned long rightNumber = 0;
   unsigned long removedNumber = 0;

   if (index == 0)
   {
     return number / 10;
   }

   leftNumber =number/ pow(10 , index + 1);
   rightNumber = number % (unsigned long)pow(10 , index);
   removedNumber =leftNumber * pow(10 , index) + rightNumber;
   return removedNumber;
 }
 int get_ways(unsigned long number)
 {
    int length = 0;
    for (int i = 0; i < get_length(number); i++)
    {
      if (get_length(number) == 1)
      {
        if (is_prime(number))
        {
          return 1;
        }
        return 0;
      }
      else if (is_prime(remove_digit(i,number)))
      {
        length += get_ways(remove_digit(i,number));
       }
     }
    return length;
 }
 bool is_prime(unsigned long number)
 {
    if (number == 1)
    {
      return false;
    }
    else if (number == 2)
    {
       return true;
    }
    else if ( number % 2 ==0)
    {
       return false;
    }

    unsigned long sqroot = sqrt(number);
    for (unsigned long i = 3; i <= sqroot; i += 2 )
    {
       if (!(number % i))
       {
          return false;
       }
    }
    return true;
 }
 int get_length(unsigned long number)
{
  int length = 0;
  while (number > 0)
  {
     length++;
     number /= 10;
  }

  return length;
}
