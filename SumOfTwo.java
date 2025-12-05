import java.util.Scanner;

public class SumOfTwo {

	public static void main(String[] args) {
		int firstNum;
		double secondNum;
		String str="";
		Scanner scanf = new Scanner(System.in);
		
		firstNum = scanf.nextInt();
		secondNum = scanf.nextDouble();
		
		str+= "(";
		if(firstNum<0)
			str=str+"";
		else str=str+"+";
		
		str += firstNum;		
		str+= ") + (";
		if(secondNum<0)
			str=str+"";
		else str=str+"+";
		
		str += secondNum;
		str+=") = "+(firstNum+secondNum);
		System.out.println(str);
	}
}
