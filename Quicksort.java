public class Quicksort {

	// Versão simplificada do particiona que usa um vetor auxiliar.
	// É um pouco diferente da versão "clássica".

	public static int particiona(int [] a, int ini, int fim){

		int [] b = new int[fim - ini + 1];
		int x = a[ini];
		int k = 0;

		for(int i = ini; i <= fim; i++){

			if(a[i] < x){

				b[k] = a[i];
				k++;
			}
		}

		int q = k - 1;

		for(int i = ini; i <= fim; i++){

			if(a[i] >= x){

				b[k] = a[i];
				k++;
			}
		}

		for(k = 0; k < b.length; k++){

			a[ini + k] = b[k];
		}

		if(q < 0) q = 0;

		print(b); System.out.println("q = " + (ini + q));
	
		return ini + q;
	}

	public static void quicksort(int [] a, int ini, int fim){

		if(ini < fim){

			int q = particiona(a, ini, fim);
			quicksort(a, ini, q);
			quicksort(a, q + 1, fim);
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

		int [] a = { 5, 3, 8, 2, 7, 10, 1, 4, 0 };
		//int [] a = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		print(a);
		quicksort(a, 0, a.length - 1);
		System.out.println(check(a));
		print(a);		
	}
}
