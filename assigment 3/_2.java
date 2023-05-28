import java.util.Scanner;
import java.util.Arrays;
public class _2 {
    public static void main(String[] args) {
        Scanner input  = new Scanner(System.in);
        int len = input.nextInt();
        int arr[] = new int[len*2];
        int a = 0,b=1; 
        for(int i = 0;i<len*2;i++){
            if(i<len){
                arr[a] = input.nextInt(); 
                a+=2;
            }else{
                arr[b] = input.nextInt();
                b+=2;
            }
        }
        input.close();
        System.out.println(Arrays.toString(arr));
        return;
    }
}
