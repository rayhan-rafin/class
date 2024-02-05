//project 1
public class main {
    public static void main(String[] args) {
//        DOG obj = new DOG();
//        obj.eat();
//        obj.bark();
        BabyDog obj2 = new
                BabyDog();
        obj2.sleep();
        obj2.eat();
        obj2.bark();
 
    }
}
 
class animal{
    public void eat(){
        System.out.println("IT can eat");
    }
}
public class DOG extends animal{
    public void bark(){
        System.out.println("Dog is barking");
    }
}
 
public class BabyDog extends DOG
{
    public void sleep(){
        System.out.println("Sleeping baby dog");
    }
}
