public class SimpleCalculation {
    public static void main(String[] args) {
        System.out.println(new Calculator().calculate());
    }
}

class Calculator {
    public int calculate() {
        return 10 + (10 * 18);
    }
}
