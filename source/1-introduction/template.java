import java.math.BigInteger;
import java.util.Scanner;
import java.util.ArrayList;

class Main{ // must be named as Main
	static ArrayList A=new ArrayList<BigInteger>();
	static void init(){
		BigInteger x = new BigInteger("1656");
		BigInteger y = BigInteger.valueOf(123);
		x = x.add(new BigInteger("4498"));
		// substract  multiply  divide  remainder
		// compare -> A.compareTo(B) < 0  A.equals(B)
		int x = A.intValue();
		long y = A.longValue();
		String s = A.toString();
	}
	public static void Main(String[] args){
		init();  int x;
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			System.out.println(">> "+in.NextInt());
}	}	}