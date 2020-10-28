public class Main{
	public static void main(String[] args) {
		double arr[][] = {
			{2,-1,0,1},
			{-1,2,-1,0},
			{0,-1,2,1}
		};

		double syoki[] = {1,1,1};

		for(int i=0;i<30;i++){
			double h = 0;
			for(int l=0;l<syoki.length;l++){
				double p = 0;
				for(int m=0;m<syoki.length;m++){
					if(m==l){
						continue;
					}
					p+=arr[l][m]*syoki[l];
				}
				h = (arr[l][arr[l].length-1]-p)/arr[l][l];
			}
			if(Math.abs(syoki[l] - h)<0.0001){
				syoki[l] = h;
				break;
			}
			syoki[l] = h;
		}

		for (double k: syoki){
			System.out.println(String.format("%5.3f",k));
		}
	}
}
