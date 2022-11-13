public interface A {
    public void M();
}


---------------------------------------------
  public interface B {
    public void M();
}


---------------------------------------------
  public class C implements A,B {
    public void M(){
        System.out.println("Okay");
    }
}


--------------------------------------------
  public class test extends C {
    public static void main (String[] args){
        C obj = new C();
        obj.M();
    }
}
