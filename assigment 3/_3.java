import java.util.Scanner;

public class _3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int len = input.nextInt();
        int max = 0;
        int cur = 0;
        for(int i = 0;i<len;i++){
            if(input.nextInt() == 1){
                cur++;
            }else{
                max = Math.max(max, cur);
                cur = 0;
            }
        }
        max = Math.max(max, cur);
        System.out.println(max);
        input.close();
        return;
    }    
}
