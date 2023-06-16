import java.util.Stack;

class postfix {
    public static void main(String[] args) {
        String p = "2+3*3";
        System.out.println(evalute(p));
        
    }
    static int evalute(String p){
        Stack<Integer> values = new Stack<>();
        Stack<Character> symbols = new Stack<>();
        for(char val:p.toCharArray()){
            if(isDigit(val)){
                values.push((int)val - 48);
                continue;
            }
            if(val == '('){
                symbols.push(val);
                continue;
            }
            if(val == ')'){
                while(symbols.peek() != '('){
                    int b = values.peek();
                    values.pop();
                    int a = values.peek();
                    values.pop();
                    char op = symbols.peek();
                    int re = applyOp(a, b, op);
                    values.push(re);
                }
                symbols.pop();
                continue;
            }
            if(val == '+'||val =='-'||val=='*'||val=='/'){
                while(!symbols.isEmpty()&&precedence(val) < precedence(symbols.peek())){
                    int b = values.pop();
                    int a = values.pop();
                    int op = symbols.pop();
                    int re = applyOp(a, b, val);
                    values.push(re);
                }
                symbols.push(val);
                continue;
            }
        }
        while(!symbols.isEmpty()){
            int b = values.pop();
            int a = values.pop();
            char op = symbols.pop();
            int re = applyOp(a, b, op);
            values.push(re);
        }
        int result = values.pop();
        return result;
    }
    static boolean isDigit(char val) {
        int k = (int) val - 48;
        if (k >= 0 && k <= 9) {
            return true;
        }
        return false;
    }

    static int precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return 0;
    }

    static int applyOp(int a, int b, char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }
        return 0;
    }
}