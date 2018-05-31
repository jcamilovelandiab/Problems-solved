import java.util.Scanner;
import java.math.BigInteger;

public class Main{
	final static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		
		while(sc.hasNextBigInteger()){
			BigInteger B = sc.nextBigInteger();
			BigInteger P = sc.nextBigInteger();
			BigInteger M = sc.nextBigInteger();
			System.out.println(B.modPow(P,M));
		}
	}
}