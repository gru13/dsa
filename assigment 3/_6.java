import java.util.Stack;

//  '(', ')', '{', '}', '[' and ']
public class _6 {
    public static void main(String[] args) {
        
        String str = "{{[]}{[]()";
        Stack<Character> stk = new Stack<Character>();
        for(char ch : str.toCharArray()){
            if(ch == '(' || ch == '[' || ch == '{'){
                stk.push(ch);
            }else{
                if(ch == '}' && stk.peek() == '{'){stk.pop();}
                else if(ch == ')' && stk.peek() == '('){stk.pop();}
                else if(ch == ']' && stk.peek() == '['){stk.pop();}
                else{stk.push(ch);}
            }
        }
        System.out.println(stk.isEmpty());
    }
}
