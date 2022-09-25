public class Employee {
    float salary = 40000;
}



-----------------------------
  class tes extends Employee {
    float bonus = 10000;

    public static void main (String args[])
    {
        tes p = new tes();
        System.out.println("Salary is : "+p.salary);
        System.out.println("bonus is : "+p.bonus);
    }
}
