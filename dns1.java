import java.util.*;
public class dns1 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        HashMap<String,String> dns = new HashMap<>();
        dns.put("google.com", "142.250.183.14");
        dns.put("youtube.com", "142.250.190.14");
        dns.put("facebook.com", "157.240.229.35");
        dns.put("amazon.com", "205.251.242.103");

        System.out.print("Enter a domain: ");
        String domain = sc.nextLine();
        if(dns.containsKey(domain)){
            System.out.println("IP address: "+dns.get(domain));
        }else{
            System.out.println("Invalid Domain!!");
        }
        sc.close();
    }
}
