public class _4 {
    public static void main(String[] args) {

        // The array elements
        int arr[] = { 1, 3, 0, 0, 2, 0, 0, 4 };
        int count = 0;
        int con = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = i; j < arr.length; j++) {
                for (int k = i; k <= j; k++) {
                    if (arr[k] != 0) {
                        con = 1;
                        break;
                    }
                }
                if (con == 0) {
                    count++;
                }
                con = 0;
            }
        }

        System.out.println("The subarrays number of subarray contains zero is " + count);
    }
}