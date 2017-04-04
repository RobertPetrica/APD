package matrix1;

//Multiply Class
class Inmultire extends Matrice {
    
    private int i;
    private int j;
    private int k;
    
    public Inmultire(int i, int j){
        this.i=i;
        this.j=j;
        k=0;
    }
    
    //inmultirea matricilor
    public synchronized void multiplyMatrix(){
        
        int sum=0;
        int a=0;
        for(a=0;a<i;a++){
            sum=0;
            for(int b=0;b<j;b++){
                sum+=matrice1[k][b]*matrice2[b][a];
            }
            rezultat[k][a]=sum;
        }
        
        if(k>=i)
            return;
        k++;
    }
}