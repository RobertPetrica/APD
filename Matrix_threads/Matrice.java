package matrix1;

import java.util.Random;
public class Matrice {
    
    //creare matrici
    static int[][] matrice1 = new int[3][3];
    static int[][] matrice2 = new int[3][3];
    static int[][] rezultat = new int[3][3];
    public static void main(String [] args){
        
        //creare elemente aleator
        Random rand = new Random();
        
        
        //completare prima matrice cu valori aleatoare
        for (int i = 0; i < matrice1.length; i++) {
            for (int j = 0; j < matrice1[i].length; j++) {
                matrice1[i][j]=rand.nextInt(10);
            }
        }
        
        //completare a doua matrice cu valori aleatoare
        for (int i = 0; i < matrice2.length; i++) {
            for (int j = 0; j < matrice2[i].length; j++) {
                matrice2[i][j]=rand.nextInt(10);
            }
        }
        //afisarea primei matrice
        System.out.println("Prima matrice:");
        for (int i = 0; i < matrice1.length; i++) {
            for (int j = 0; j < matrice1[i].length; j++) {
                System.out.print(matrice1[i][j]+" ");
            }
            System.out.println();
        }    
        //afisarea a doua matrice
        System.out.println("\nA doua matrice:");
        for (int i = 0; i < matrice2.length; i++) {
            for (int j = 0; j < matrice2[i].length; j++) {
                System.out.print(matrice2[i][j]+" ");
            }
            System.out.println();
        }
        try{
            //Object of multiply Class
            Inmultire multiply = new Inmultire(3,3);
            
            //fire de executie
            MatrixMultiplier thread1 = new MatrixMultiplier(multiply);
            MatrixMultiplier thread2 = new MatrixMultiplier(multiply);
            MatrixMultiplier thread3 = new MatrixMultiplier(multiply);
            
            //Implementarea firelor
            Thread fir1 = new Thread(thread1);
            Thread fir2 = new Thread(thread2);
            Thread fir3 = new Thread(thread3);
            
            //pornirea firelor
            fir1.start();
            fir2.start();
            fir3.start();
            
            fir1.join();
            fir2.join();
            fir3.join();
            
        }
        catch (Exception e) {
            e.printStackTrace();
        }
        //afisarea rezultatului
        System.out.println("\n\nRezultat:");
        for (int i = 0; i < rezultat.length; i++) {
            for (int j = 0; j < rezultat[i].length; j++) {
                System.out.print(rezultat[i][j]+" ");
            }
            System.out.println();
        }
    }
    
}