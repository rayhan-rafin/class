public abstract class Vehicle {
    public abstract void move ();

    public void carry ()
    {
        System.out.println ("All vehicle carry load");
    }
}

-----------------------------------
  
  
  public class Car extends Vehicle {
    public void move ()
    {
        System.out.println ("Car moves faster");
    }
    public static void main (String [] args)
    {
        Car c1 = new Car();
        c1.move();
        c1.carry();
    }
}
