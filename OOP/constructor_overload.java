public class tes {
    private int height,width;
    public tes()
    {
        height = 10;
        width = 15;
    }
    public tes (int height, int width)
    {
        this.height = height;
        this.width = width;
    }
    public static void main (String[] args)
    {
        tes b1 = new tes();
        tes b2 = new tes(20,30);
        tes b3 = new tes(50,60);
        tes b4 = new tes();

        System.out.println("For box-1: Height ="+b1.height+" width ="+b1.width);
        System.out.println("For box-2: Height ="+b2.height+" width ="+b2.width);
        System.out.println("For box-3: Height ="+b3.height+" width ="+b3.width);
        System.out.println("For box-4: Height ="+b4.height+" width ="+b4.width);
    }
}
