import java.util.*;
import java.io.*;
import java.math.BigInteger;

class Main{
	public static void main(String []args) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt(), a, b;
		for(int t=0; t<tc; t++) {
			a=sc.nextInt(); b = sc.nextInt();
			if(a!=0 && b!=0) {
				int N = a*a+b*b;
				BigInteger BN = BigInteger.valueOf(N);
				System.out.println((BN.isProbablePrime(10)?"P":"C"));
			}else if(a==0) {
				System.out.println((b%4==3 ? "P":"C"));
			}else if(b==0) {
				System.out.println((a%4==3 ? "P":"C"));
			}
		}
		sc.close();
	}
}