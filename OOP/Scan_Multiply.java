import java.util.Scanner;
public class add {
    public static void main (String[] args)
    {
        Scanner input = new Scanner (System.in);
        System.out.println("Enter first number: ");
        double a = input.nextDouble();
        System.out.println("Enter Second number: ");
        double b = input.nextDouble();
        System.out.println("Enter Third number: ");
        double c = input.nextDouble();
        System.out.println("The sum of two numbers: "+(a*b*c));
    }
}
