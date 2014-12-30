class BinarySearch 
{

  public static void main(String args[])
  {
    int c, first, last, middle, n, search, array[];
 
    //read in the user's input for the number of the total 
    Scanner in = new Scanner(System.in);
    System.out.println("Enter number of elements");
    n = in.nextInt(); 
    array = new int[n];
 
    System.out.println("Enter " + n + " integers");
 
    //read in each number in the array
    for (c = 0; c < n; c++)
      array[c] = in.nextInt();
 
    System.out.println("Enter value to find");
    search = in.nextInt();
 
    first  = 0;
    last   = n - 1;
    middle = (first + last)/2;
 
    //bubble sort O(n^2)
    while( first <= last )
    {
      if ( array[middle] < search )
        first = middle + 1;    
      else if ( array[middle] == search ) 
      {
        System.out.println(search + " found at location " + (middle + 1) + ".");
        break;
      }
      else
         last = middle - 1;

      //update the middle with new value
      middle = (first + last)/2;
   }

   //not found
   if ( first > last )
      System.out.println(search + " is not present in the list.\n");
  }
}



//in the array package there is a BinarySearch API to directly use
//Other methods of searching are Linear search and Hashing. 
//There is a binarySearch method in Arrays class which can also be used.

import java.util.Arrays;
 
class BinarySearchAPI 
{
  public static void main(String args[])
  {
    char characters[] = { 'a', 'b', 'c', 'd', 'e' };
 
    System.out.println(Arrays.binarySearch(characters, 'a'));
    System.out.println(Arrays.binarySearch(characters, 'p'));
  }
}