// java program to find non-repeating value in an array
public class Main{
    static int nonRepeating(int[] arr, int n){
        //loop for checking each element
        for (int i = 0; i < n; i++) {
            int j;
            //checking if element is in array
            for(j = 0;j < n; j++){
                if(i != j && arr[i] == arr[j])
                    break;

                //if ith element is not present in array except at ith index then return element
                if(j == n){
                    return arr[i];
                }

            }

        }
        return -1;
    }
    public static void main(String[] args){
        int[] arr = {6,9,4,9,6,7,4};
        int n = arr.length;

        System.out.println(nonRepeating(arr, n));
    }
}