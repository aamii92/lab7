abstract class TwoDShape implements Shape {
    protected int x, y, r;
    protected String name;

    public TwoDShape(String name, int x, int y, int r){
        this.x = x;
        this.y = y;
        this.r = r;
        this.name = name;
    }
    @Override
    public String toString() {
        return  this.name + "(x=" + x + ", y=" + y + " , r=" + r + ")";
    }
    public abstract double Area();
    public abstract double Perimeter();
}
