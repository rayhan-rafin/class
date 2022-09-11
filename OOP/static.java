
public class test {

	public static void main(String[] args) {
		student ob=new student("Rayhan","213-15-4278",21);
		ob.show();
		student ob1 = new student("Hisham","213-15-4270",20);
		ob1.show();
	}

}
-----------------

public class student {

	String name,id;
	int age;
	static String varsity_name = "DIU";
	student(String n,String i,int a){
		name = n;
		id = i;
		age =a;
	}
	void show() {
		System.out.println("Name: "+name);
		System.out.println("ID: "+id);
		System.out.println("Age: "+age);
		System.out.println("University: "+varsity_name);
	}
}
