import java.lang.Math;
import java.util.Random; 

public class Circle extends TwoDShape{
    
    public Circle (String name, int x, int y, int r){
        super(name, x, y, r);

    }
    private static int circleCount = 0;
    public Circle() {
        Random rand = new Random();
        int x_rand = rand.nextInt(10) + 1; 
        int y_rand = rand.nextInt(10) + 1;
        int r_rand = rand.nextInt(10) + 1;
        circleCount++; 
        String name = "Circle_" + circleCount;

        super(name, x_rand, y_rand, r_rand); // Энэ бол эхний мөр
    }
    @Override
    public double Area (){
        return Math.PI * r * r;
    }
    @Override
    public double Perimeter() {
        return 2 * Math.PI * r;
    }
    @Override
    public String toString(){
        // x, y, r хувьсагчууд нь хүртээмжтэй болсон тул алдаа заахгүй
        return "circle main point " + this.name + "[x=" + x + 
               ", y="+ y + 
               ", r=" + r +
               " area " + Area() + 
               ", P=" + Perimeter() + "]";
    }
}
