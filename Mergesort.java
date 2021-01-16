public class Mergesort {

	public static void merge(int [] a, int ini, int med, int fim){

		int [] b = new int [fim - ini + 1];

		int k = 0;
		int i = ini;
		int j = med + 1;

		while(i <= med && j <= fim){

			if(a[i] <= a[j]){ 
				
				b[k] = a[i]; 
				i++;
			}
			else {

				b[k] = a[j];
				j++;
			}
			k++;
		}

		while(i <= med){

			b[k] = a[i]; 
			i++;
			k++;
		}

		while(j <= fim){
		
			b[k] = a[j];
			j++;
			k++;
		}

		for(k = 0; k < b.length; k++){

			a[ini + k] = b[k];
		}
	}

	public static void merge_sort(int [] a, int ini, int fim){

		if(ini < fim){

			int med = (ini + fim) / 2;
			merge_sort(a, ini, med);
			merge_sort(a, med + 1, fim);
			merge(a, ini, med, fim);
		}
	}

	public static void print(int [] a){

		System.out.print("vetor:");

		for(int i = 0; i < a.length; i++){

			System.out.print(" " + a[i]);			
		}

		System.out.println();
	}

	public static boolean check(int [] a){

		int count = 0;

		for(int i = 0; i < a.length - 1; i++){

			if(a[i] <= a[i + 1]) count++;
		}

		if(count == a.length - 1) return true;

		return false;
	}

	public static void main(String [] args){

		int [] a = { 10, 3, 8, 2, 7, 5, 1, 4, 0 };

		print(a);
		merge_sort(a, 0, a.length - 1);
		System.out.println(check(a));
		print(a);		
	}
}
