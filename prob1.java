import java.util.*;

public class prob1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Choose the framing method:\n 1)Character Stuffing\n 2)Bit Stuffing\n Enter Your choice:");
        int choice = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter the string:");
        String str = sc.nextLine();
        if (choice == 1) {
            String stuffed = str.replace("\\", "\\\\").replace("$", "\\$");
            System.out.println("Character Stuffed Output: $" + stuffed + "$");
        } else if (choice == 2) {
            String stuffed = str.replaceAll("[^1]", "0").replace("11111", "111110");
            System.out.println("Bit stuffing output: 01111110" + stuffed + "01111110");
        } else {
            System.out.println("Invalid Choice!!");
        }
    }
}