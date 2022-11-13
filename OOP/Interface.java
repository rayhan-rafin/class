public interface A {
    public abstract void M();      //same with no abstract keyword,interface is 100% abstract; auto added when inteface created.
}


---------------------------------------------
 public interface B {
    public abstract void M();
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
