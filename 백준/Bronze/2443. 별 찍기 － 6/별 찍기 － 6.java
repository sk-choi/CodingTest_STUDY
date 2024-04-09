import java.lang.*;
import java.io.*;
import java.util.Scanner;

// The main method must be in a class named "Main".
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j < i; j++){
                System.out.print(" ");
            }
            for (int k = 2*n-i; k >= i; k--){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}