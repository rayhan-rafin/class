//project3
public class main {
    public static void main(String[] args) {
        drawings obj = new drawings();
        obj.a();
        obj.b();
        obj.c();
        obj.d();
 
    }
}
interface drawable {
    void a();
    void b();
    void c();
    void d();
}
public class drawings  implements  drawable{
    public void a(){
        System.out.println("I am A");
    }
    public void b(){
        System.out.println("I am b");
    }
    public void c(){
        System.out.println("I am c");
    }
    public void d(){
        System.out.println("I am d");
    }
}
