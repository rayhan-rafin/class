//project2
public class main {
    public static void main(String[] args) {
        Bank b = new Bank();
        System.out.println(b.getRateOfInterest());
        ISIB is = new ISIB();
        System.out.println(is.getRateOfInterest());
        IFIC ific = new IFIC();
        System.out.println(ific.getRateOfInterest());
    }
}
public class IFIC extends Bank {
    public int getRateOfInterest() {
        return base * 10;
    }
}
public class ISIB extends Bank {
    public int getRateOfInterest(){
        return base *5;
    }
}
public class Bank{
    public int base = 500;
    public int getRateOfInterest(){
        return base;
    }
 
}
