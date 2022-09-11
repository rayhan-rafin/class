public class test {

	public static void main(String[] args) {
		student ob=new student();
		ob.show();
		student.display();
	}

}

----------------------

public class student {
	int a = 5;
	static int b = 8;
	void show() {
		display();
		System.out.println(a);
		System.out.println(b);
	}
	static void display () {
		System.out.println("static method"); //not a,cannot use non-static in static
		System.out.println(b);
	}
}
