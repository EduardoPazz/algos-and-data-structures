import java.util.*;

public class Busca {

	// Nesta classe são implementadas 3 buscas: sequencial, binária e tabela de espalhamento.
	// A implementação da tabela de espalhamento não está muito elegante pois não tira proveito da orientação a objetos.

	public static final int Q = 53;

	public static int h(int x){

		return x % Q;
	}
	public static List [] newTable(){

		List [] T = new LinkedList[Q];

		for(int i = 0; i < T.length; i++) T[i] = new LinkedList();

		return T;
	}

	public static void insere(List [] T, int x){
   
		T[h(x)].add(x);
	}

	public static boolean busca(List [] T, int x){
		
		return T[h(x)].contains(x);		
	}

	public static boolean sequencial(int [] a, int x){

		for(int i = 0; i < a.length; i++){

			if(a[i] == x) return true;
		}

		return false;
	}

	public static boolean busca_bin(int [] a, int x, int ini, int fim){

		if(ini <= fim){
			
			int med = (ini + fim) / 2;
			if(x == a[med]) return true;
			if(x < a[med]) return busca_bin(a, x, ini, med - 1);
			if(x > a[med]) return busca_bin(a, x, med + 1, fim);
		}

		return false;
	}

	public static void main(String [] args){

		int [] a = { 83, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33 };
		List [] T = newTable();

		for(int x : a) insere(T, x); // inserções na tabela de espalhamento...

		// buscas...
		for(int x = 0; x < 100; x++){

			System.out.println("seq(" + x + "): " + sequencial(a, x));
			System.out.println("bin(" + x + "): " + busca_bin(a, x, 0, a.length - 1));
			System.out.println("tab(" + x + "): " + busca(T, x));
			System.out.println("check: " + (sequencial(a, x) == busca_bin(a, x, 0, a.length - 1)) + " " + (sequencial(a, x) == busca(T, x)));
			System.out.println("-------------------------------------------------------------------");
		}
	}
}
