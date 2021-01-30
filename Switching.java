/*
* Chech https://stackoverflow.com/questions/58357037/the-longest-sub-array-with-switching-elements/65967661#65967661
* for explanations
*/

public class Switching
{
    public static int switching(int[] arr, int index, int end)
    {
        try
        {
            if (arr[index] == arr[index+2])
            {
                end = index+2;
                return switching(arr, index+1, end);
            }
            
        } catch (Exception e) {}
        
        return end;
    }
    
    public static void main(String[] args)
    {
        //int[] arr = {3,2,3,2,3};
        //int[] arr = {3,2,3};
        //int[] arr = {4,4,4};
        int[] arr = {1,2,3,4,5,4,4,7,9,8,10};
        
        int best = -1;
        
        for (int i = 0; i < arr.length; i++) 
                best = Math.max(best, (switching(arr, i, 0) - i));
        
        System.out.println(best+1); // It returns, in this example, 3
    }

}
