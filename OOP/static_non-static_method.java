public class test {

	public static void main(String[] args) {
		student ob=new student();
		ob.show();
		student.display();
	}

}
-------------------

public class student {
	void show() {
		System.out.println("It is a non-static method");
	}
	static void display () {
		System.out.println("It is a static method");
	}
}
