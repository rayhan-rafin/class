import java.util.Scanner;
public class add {
    public static void main (String[] args)
    {
        Scanner input = new Scanner (System.in);
        System.out.println("Enter first number: ");
        int a = input.nextInt();
        System.out.println("Enter Second number: ");
        int b = input.nextInt();
        System.out.println("The sum of two numbers: "+(a+b));
    }
}
