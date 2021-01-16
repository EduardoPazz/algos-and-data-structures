class Heap {

	int [] heap;
	int size;

	public Heap(int [] a){

		heap = new int[a.length];
		size = heap.length;

		for(int i = 0; i < a.length; i++) heap[i] = a[i];
		for(int i = a.length - 1; i >= 0; i--) heapfy(i);
	}

	private int left(int i){

		return 2 * i + 1;
	}

	private int right(int i){

		return 2 * i + 2;
	}

	private int parent(int i){

		return (i - 1)/2;
	}

	private void heapfy(int i){

		int max_index = i;

		if(left(i) < size && heap[left(i)] > heap[max_index]) {

			max_index = left(i);
		}

		if(right(i) < size && heap[right(i)] > heap[max_index]) {

			max_index = right(i);
		}

		if(max_index != i){

			int temp = heap[i];
			heap[i] = heap[max_index];
			heap[max_index] = temp;
			heapfy(max_index);
		}	
	}

	public int extractMax(){

		int toReturn = heap[0];

		heap[0] = heap[size - 1];
		size--;

		heapfy(0);

		return toReturn;	
	}

	public void print(){

		System.out.print("Heap:");

		for(int i = 0; i < size; i++){

			System.out.print(" " + heap[i]);			
		}

		System.out.println();
	}
}

public class Heapsort {
	
	// métodos auxiliares

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

	// Heapsort - versão simplificada: estrutura heap implentada fora do array a. 

	public static void heapsort(int [] a){

		Heap heap = new Heap(a);
	
		for(int j = a.length - 1; j >= 0; j--){

			a[j] = heap.extractMax();
		}
	}

	public static void main(String [] args){

		int [] a = { 5, 3, 8, 2, 7, 10, 1, 4, 0 };
		//int [] a = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		print(a);
		heapsort(a);
		System.out.println(check(a));
		print(a);		
	}
}
