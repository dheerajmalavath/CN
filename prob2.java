import java.util.*;

public class prob2 {
    static String computeCRC(String input, String poly) {
        char[] temp = input.toCharArray();
        int n = poly.length();
        for (int i = 0; i < temp.length - n; i++) {
            if (temp[i] == '1') {
                for (int j = 0; j < n; j++) {
                    temp[i + j] = (temp[i + j] == poly.charAt(j)) ? '0' : '1';
                }
            }
        }
        return new String(temp, temp.length - n + 1, n - 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter data to be transmitted: ");
        String data = sc.next();
        System.out.print("Enter the generating polynomial");
        String poly = sc.next();
        String padded = data + "0".repeat(poly.length() - 1);
        String crc = computeCRC(padded, poly);
        String sent = data + crc;
        System.out.println("Data padded with 0: " + padded);
        System.out.println("CRC value: " + crc);
        System.out.println("Sent data: " + sent);
        System.out.print("\n enter recieved data: ");
        String s1 = sc.next();
        String rem = computeCRC(s1, poly);
        if (rem.contains("1")) {
            System.out.println("Error Detected!!");
        } else {
            System.out.println("No error detected...");
        }
    }
}
