public class add {
    public static void main (String[] args)
    {
        double d = 100.4;
        int i = (int)d;                          //explicit type casting required, big to small data type (auto conversion: small to big)
                                                //precedence:
                                               //double > float > long > int > short > byte
        System.out.println("Double value "+d);
        System.out.println("Integer value "+i);
    }
}
