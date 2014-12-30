//O(n^2) && memory O(1)

public static void main()
{
       int[] numbers = { 5, 8, 14, 1, 5678 };
       bubblesort(numbers);
}

static void bubblesort(int[] numbers)
{
        int tempVar;
        for (int i = 0; i < numbers.length; i++)
        {
                 for(int j = 0; j < numbers.length; j++)
                 {
                         if(numbers[i] > numbers[j + 1])
                         {
                         tempVar = numbers [j + 1];
                         numbers [j + 1]= numbers [i];
                         numbers [i] = tempVar;
                         }
                 }
        }
        for (int i = 0; i < numbers.length; i++)
        {
                  System.out.println(numbers[i].toString());
        }

}