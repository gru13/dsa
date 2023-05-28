import java.util.Scanner;

public class _1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int len = input.nextInt();
        input.nextLine();

        int x = 0;
        for (int i = 0; i < len; i++) {
            String operation = input.nextLine();

            if (operation.equals("X++") || operation.equals("++X")) {
                x++;
            } else if (operation.equals("X--") || operation.equals("--X")) {
                x--;
            }
        }

        System.out.println(x);
        input.close();
    }
}
/*
 * Question 1:
 * The four operations which can be performed are:
 * There is a programming language with only four operations and one variable (X).
 * i) X++
 * ii) ++X
 * iii) X—
 * iv) –X
 * X++ and ++X both increments the value of X by 1.
 * X—and –X both decrements the value of X by 1.
 * The initial value of X is 0.
 */