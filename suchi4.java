public class Main{
	public static double data[][] = {{1,2},{3,5},{4,4},{7,8},{10,10}};
	//public static double data[][] = {{0,1},{1,2},{2,1},{3,0},{4,4}};
	public static int N= data.length;
	public static int M=1;
	public static double a[][] = new double[(int) (M+1)][(int) (M+2)];
	public static void main(String[] args) {
		for(int i=0;i<M+1;i++){
			for (int l=0;l<M+2;l++) {
				a[i][l] = 0;
			}
		}

		for(int i=0;i<M+1;i++){
			for (int l=0;l<M+1;l++) {
				for (int k=0;k<N;k++) {
					a[l][i] += Math.pow(data[k][0], (double)(i+l));
				}
			}
		}

		for (int i=0;i<M+1;i++) {
			for (int j=0;j<N;j++) {
				a[i][M+1] += data[j][1] * Math.pow(data[j][0], (double)i);
			}
		}

		if(jordan() != 1){
			for (int i=0;i<M+1;i++) {
				System.out.println(""+i+" "+a[i][M+1]);
			}
		}else{
			System.out.println("error");
		}
	}

	public static int jordan() {
		double pivot, delta;
		int re = 0;
		for (int i=0;i<M+1;i++) {
			pivot = a[i][i];
			if(Math.abs(pivot) < 0.0001){
				re=1;
				break;
			}

			for (int j=i;j<M+2;j++) {
				a[i][j] /= pivot;
			}

			for (int j=0;j<M+1;j++) {
				delta = a[j][i];
				for (int k=i;k<M+2;k++) {
					if(j!=i){
						a[j][k] -= delta * a[i][k];
					}
				}
			}
		}

		return re;
	}
}
