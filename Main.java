import java.util.Random;

public class Main {
    public static void main(String[] args){
        Random rand = new Random(); 
        
        // 2. x, y, r-д 1-ээс 10 хүртэлх санамсаргүй утга оноох
        int x_rand = rand.nextInt(10) + 1; 
        int y_rand = rand.nextInt(10) + 1;
        int r_rand = rand.nextInt(10) + 1;
    Circle c1  = new Circle("c1", x_rand, y_rand, r_rand);   
    Circle c2  = new Circle();
    Circle c3  = new Circle();

    Square s1 = new Square();
    Square s2 = new Square();
    Square s3 = new Square();

    Triangle t1 = new Triangle();
    Triangle t2 = new Triangle();
    Triangle t3 = new Triangle();

    System.out.println("circle random objects: ");
    System.out.println(c1);
    System.out.println(c2);
    System.out.println(c3);
    System.out.println("square random objects: ");
    System.out.println(s1);
    System.out.println(s2);
    System.out.println(s3);
    System.out.println("triangle random objects: ");
    System.out.println(t1);
    System.out.println(t2);
    System.out.println(t3);
    
    }
   
 
}
