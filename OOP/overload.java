public class main {
    public static void main(String[] args)
    {
        teacher ob1= new teacher();
        teacher ob2= new teacher("abcd","CSE",32);
        teacher ob3= new teacher("efgh","GED");
        ob2.display();
        ob3.display();
    }
}
--------------
public class teacher {
    String name,dept;
    int age;
    teacher()
    {
        System.out.println("No input.");
    }
    teacher(String n, String d, int a) {
        name=n;
        dept=d;
        age=a;
    }
    teacher(String n, String d) {
        name=n;
        dept=d;
    }
    void display()
    {
        System.out.println("Name\t\t:"+name);
        System.out.println("Department\t:"+dept);
        System.out.println("Age\t\t\t:"+age);
        System.out.println();
    }
}
