import java.util.Scanner;

class Conversor {

    private static final String[] SIZES = {
        "B", "KB", "MB", "GB", "TB", "PB",
        "EB", "ZB", "YB"
    };

    public static void main(String[] args) {
        double num = Double.parseDouble(new Scanner(System.in).nextLine());

        byte sizeIndex = (byte) (Math.log(num) / Math.log(1024));

        num /= Math.pow(1024, sizeIndex);

        System.out.format(
            "%.2f %s\n",
            num,
            SIZES[(sizeIndex >= SIZES.length ? 8 : sizeIndex)]
        );
    }
} 
