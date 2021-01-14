import java.util.Scanner;

class Conversor {

    private static final String[] SIZES = {
        "B", "KB", "MB", "GB", "TB", "PB",
        "EB", "ZB", "YB"
    };

    public static void main(String[] args) {
        double num = Double.parseDouble(new Scanner(System.in).nextLine());

        byte sizeIndex = 0;
        while (num >= 1024.0) {
            num /= 1024.0;
            sizeIndex++;
        }

        System.out.format(
            "%.2f %s\n",
            (num < 1 ? 1 : num),
            SIZES[(sizeIndex >= SIZES.length ? 8 : sizeIndex)]
        );
    }
} 
