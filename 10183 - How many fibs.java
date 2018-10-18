import java.math.*;
import java.util.*;

public class Main {
	
	static ArrayList<BigInteger> fibo=new ArrayList<BigInteger>();
	
	static void Fibonacci() {
		fibo.add(BigInteger.ONE);
		BigInteger n=fibo.get(fibo.size()-1);
		BigInteger limit=BigInteger.valueOf(10);
		limit=limit.pow(100);
		while(n.compareTo(limit)<=0) {
			fibo.add(n);
			n = fibo.get(fibo.size()-1).add(fibo.get(fibo.size()-2));
		}
		//for(BigInteger b: fibo) System.out.println(b);
	}
	
	public static void main(String args[]) {
		Fibonacci();
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			BigInteger a=sc.nextBigInteger();
			BigInteger b=sc.nextBigInteger();
			if(a.compareTo(BigInteger.ZERO)==0 && b.compareTo(BigInteger.ZERO)==0) break;
			int answer=0;
			for(int i=1; i<fibo.size(); i++) {
				if(fibo.get(i).compareTo(a)>=0 && fibo.get(i).compareTo(b)<=0) answer++;
				if(fibo.get(i).compareTo(b)==1) break;
			}
			System.out.println(answer);
		}
	}
}
