public class student {
	static int id;
	static String name;
	
	static void display() {
		System.out.println("ID :"+id);
		System.out.println("Name :"+name);
	}
	
	
	static {    // static block to assign static value,blocks are executed first
		id = 123;
		name = "Rayhan";
		System.out.println("Hello world");
	}
}

-----------------------------
public class test {
	public static void main(String[] args) {
		student.display();
	}

}
