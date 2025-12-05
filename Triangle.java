import java.util.Random;

public class Triangle extends TwoDShape {
    protected int x1, y1;
    protected int x2, y2;
    public Triangle (String name, int x, int y, int r){
        super(name, x, y, r);
    }
    private static int tCount = 0;
    public Triangle() {
        Random rand = new Random();
        int x_rand = rand.nextInt(10) + 1; 
        int y_rand = rand.nextInt(10) + 1;
        int r_rand = rand.nextInt(10) + 1;
        tCount++; 
        String name = "triangle_" + tCount;

        super(name, x_rand, y_rand, r_rand);
        CalculateOther();
    }
     @Override
    public double Area(){
        return r * r * (Math.sqrt(3) / 4);
    }
     @Override
    public double Perimeter(){
        return 3 * r;
    }
    public void CalculateOther() {  // Бусад цэгүүдийн координатыг тооцох функц
       x1 = x - (r / 2); // зүүн доод цэг
       y1 = y - r;

       x2 = x + (r / 2); // баруун доод цэг
       y2 = y - r;
   }
   @Override
    public String toString(){
        return " triangle period and side " + this.name + "[x=" + x + 
               ", y="+ y + 
               ", r=" + r +
               " lower left corner " + "[x=" + x1 + 
               ", y="+ y1 + 
               " lower right corner " + "[x=" + x2 + 
               ", y="+ y2 + 
               " area " + Area() +
               ", P=" + Perimeter()+ "]";

    }
    
}
