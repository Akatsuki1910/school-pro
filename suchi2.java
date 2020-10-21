public class Main{
	public static void main(String[] args) {
		double arr[][] = {
			{1,1,1,10},
			{1,4,2,17},
			{2,3,1,17}
		};

		double[] ans = new double[3];

		for (int i=0;i<arr.length;i++) {
			double def1 = arr[i][i];
			for (int l=i;l<arr[i].length;l++) {
				arr[i][l]/=def1;
			}
			for (int m=i+1;m<arr.length;m++) {
				double def2 = arr[m][i];
				for (int n=i;n<arr[m].length;n++) {
					arr[m][n]-=arr[i][n]*def2;
				}
			}
		}

		// for (int i=0;i<arr.length;i++) {
		// 	for (int l=0;l<arr[i].length;l++) {
		// 		System.out.print(String.format("%10.3f",arr[i][l]));
		// 	}
		// 	System.out.println();
		// }

		for (int i=arr.length-1;i>=0;i--) {
			double p = 0;
			for (int l=arr.length-1, q=0;l>i;l--, q++) {
				p+=arr[i][arr[i].length-2-q]*ans[ans.length-1 -q];
			}
			ans[i]=arr[i][arr[i].length-1]-p;
		}

		for (double i: ans){
			System.out.println(String.format("%5.3f",i));
		}
	}
}
