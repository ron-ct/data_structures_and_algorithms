public class Main{

    // by use of approach called BruteForce.
         public static void rotate(int[] arr, int k){
            int j;
            while(k > 0) {
                int temp = arr[arr.length - 1];
                for (j = arr.length - 1; j > 0; j--){
                    arr[j] = arr[j - 1];}

            arr[j] = temp;
            k--;
            }
        }

    // By approach called reversal algorithm
    public static void rotateByK(int[] arr, int k){
        int len = arr.length;
        k = k % len;

        reverse(0, len - k - 1, arr);
        reverse(len-k,len-1, arr);
        reverse(0, len-1, arr);
    }

    private static void reverse(int start, int end, int[] arr){
        while(start < end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }


    public static void main(String[] args){
        int[] arr = {1,2,3,4,5,6,7,8};
        int k = 5;
        rotateByK(arr, k);
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
        rotate(arr, k);
        for (int i = 0; i < arr.length; i ++){
            System.out.println(arr[i]);
        }
    }
}