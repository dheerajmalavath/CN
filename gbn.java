import java.util.Random;

public class gbn {
    static final int WINDOW_SIZE = 4, TOTAL_FRAMES = 10, TIMEOUT = 3000;
    static Random rand = new Random();

    static void sendFrame(int frame) {
        System.out.println("[Sender] Frame " + frame + (rand.nextInt(5) == 0
                ? " lost during transmission."
                : " sent successfully."));
    }

    static boolean receiveAck(int frame) {
        if (rand.nextInt(7) == 0) {
            System.out.println("[Receiver] ACK for Frame " + frame + " lost.");
            return false;
        }
        System.out.println("[Receiver] ACK for Frame " + frame + " received successfully.");
        return true;
    }

    public static void main(String[] args) {
        System.out.println("[Sender] Starting Sliding Window Protocol with Go-Back-N.");

        int base = 0, next = 0;
        boolean[] acks = new boolean[TOTAL_FRAMES];
        long[] timers = new long[TOTAL_FRAMES];

        while (base < TOTAL_FRAMES) {
            while (next < base + WINDOW_SIZE && next < TOTAL_FRAMES) {
                if (!acks[next]) {
                    sendFrame(next);
                    timers[next] = System.currentTimeMillis();
                }
                next++;
            }

            for (int i = base; i < next; i++) {
                if (acks[i])
                    continue;
                if (receiveAck(i)) {
                    acks[i] = true;
                    while (base < TOTAL_FRAMES && acks[base]) {
                        System.out.println("[Sender] Sliding window. Base frame is now " + (++base) + ".");
                    }
                } else if (System.currentTimeMillis() - timers[i] > TIMEOUT) {
                    System.out.println("[Sender] Timeout for Frame " + i + ". Resending all frames from " + base + ".");
                    next = base;
                    break;
                }
            }
        }

        System.out.println("[Sender] All frames sent and acknowledged successfully.");
        System.out.println("[Sender] Transmission completed.");
    }
}