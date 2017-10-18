/**
 * Demonstrates swapping of two number using bit manipulation.
 */
public class SwapNumber {

    public static void main(String[] args) {
        Integer x = 20;
        Integer y = 10;
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
        System.out.println("x = " + x);
        System.out.println("y = " + y);
    }
}