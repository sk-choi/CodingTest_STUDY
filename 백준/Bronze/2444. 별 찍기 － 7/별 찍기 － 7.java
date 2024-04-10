import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
		// 상단
		for (int i = 1; i <= n; i++){
			for (int j = n- i; j >= 1; j--){
				System.out.print(' ');
			}
			for (int k = 1; k <= 2*i-1; k++) {
				System.out.print('*');
			}
			System.out.println();
		}
		
		// 하단
		for (int i = 1; i <= n-1; i++) {
			for (int j = 1; j <= i; j++) {
				System.out.print(' ');
			}
			for (int k = 2*(n-1) - i; k >= i; k--) {
				System.out.print('*');
			}
			System.out.println();
		}
    }
}