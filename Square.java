import java.util.Random;

public class Square extends TwoDShape {
    protected int x1, y1; // баруун дээд
    protected int x2, y2; // баруун доод
    protected int x3, y3; // зүүн доод
     
    public Square (String name, int x, int y, int r){
        super(name, x, y, r);
    }
    private static int sCount = 0;
    public Square() {
        Random rand = new Random();
        int x_rand = rand.nextInt(10) + 1; 
        int y_rand = rand.nextInt(10) + 1;
        int r_rand = rand.nextInt(10) + 1;
        sCount++; 
        String name = "square_" + sCount;

        super(name, x_rand, y_rand, r_rand); 
        CalculateOther();
    }
     @Override
    public double Area() {
        return r * r;
    }
     @Override
    public double Perimeter() {
        return 4 * r;
    }
   
    public void CalculateOther(){
        x1 = x+r;
        y1 = y;
        x2 = x1;
        y2 = y-r;
        x3 = x;
        y3 = y2;
    }
    @Override
    public String toString(){
        return " square top right point and side length " + this.name + "[x=" + x + 
               ", y="+ y + 
               ", r=" + r +
               " top right point " + "[x=" + x1 + 
               ", y="+ y1 + 
               " lower right corner " + "[x=" + x2 + 
               ", y="+ y2 + 
               " lower left corner " + "[x=" + x3 + 
               ", y="+ y3 + 
               " area " + Area() +
               ", P=" + Perimeter()+ "]";
    }

}



