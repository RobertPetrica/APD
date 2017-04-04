package matrix1;

//Thread Class
class MatrixMultiplier implements Runnable {
    
    private final Inmultire mul;
    
    public MatrixMultiplier(Inmultire mul){
        this.mul=mul;
    }
    
    public void run() {
        mul.multiplyMatrix();
    }
}