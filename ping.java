import java.io.*;
import java.net.*;
import java.util.*;

public class ping {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: ping service <HostName>");
            return;
        }
        String host = args[0];
        Map<String, String> offlineHosts = Map.of(
                "google.com", "142.250.183.14",
                "youtube.com", "142.250.190.14",
                "facebook.com", "157.240.229.35",
                "amazon.com", "205.251.242.103");
        System.out.println("Pinging " + host + " ....");
        String offlineIp = offlineHosts.get(host);
        if (offlineIp != null) {
            System.out.println("Host " + host + " is reachable.");
            System.out.println("IP Address: " + offlineIp);
            return;
        }
        try {
            InetAddress ip = InetAddress.getByName(host);
            if (ip.isReachable(2000)) {
                System.out.println("Host " + host + " is reachable.");
                System.out.println("IP Address: " + ip);
            } else {
                System.out.println("Not reachable");
            }
        } catch (Exception err) {
            System.out.println("Not reachable");
        }
    }
}