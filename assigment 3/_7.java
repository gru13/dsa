public class _7 {
    public static void main(String[] args) {
        int arr[] = {5,1,1,1};
        int k = 0;
        int count = 0;
        while(arr[k] != 0){
            for(int i = 0;i<arr.length;i++){
                if(arr[i] != 0){
                    arr[i]--;
                    count++;
                }
            }
        } 
        System.out.println("THE time taken is " + count);

    }
}
