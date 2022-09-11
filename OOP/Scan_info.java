import java.util.Scanner;
public class add {
    public static void main (String[] args)
    {
        Scanner input = new Scanner (System.in);
        System.out.println("Enter Name: ");
        String name = input.next();
        System.out.println("Enter ager: ");
        int age = input.nextInt();
        System.out.println("Enter cgpa: ");
        double cgpa = input.nextDouble();
        System.out.println("Enter department: ");
        String dept = input.nextLine();
        System.out.println("Name is: "+name);
        System.out.println("age is: "+age);
        System.out.println("cgpa is: "+cgpa);
        System.out.println("dept is: "+dept);
    }
}
