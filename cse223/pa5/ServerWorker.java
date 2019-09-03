import java.util.Map;
import java.util.Map.Entry;
import java.util.Queue;
import java.util.Set;
import java.util.HashSet;

public class ServerWorker extends Thread {
    private Map<Long, ClientHandler> clients;
    private Queue<String> messages;
    private boolean done = false;

    public ServerWorker(Map<Long, ClientHandler> c, Queue<String> m) {
        clients = c;
        messages = m;
    }

    public void run() {
        while (!done) {
            String m = messages.poll();
            if (m != null) {
                Set<Long> toRemove = new HashSet<Long>();
                for (Map.Entry<Long, ClientHandler> entry : clients.entrySet()) {
                    ClientHandler c = entry.getValue();
                    // checking if the client is still alive, else remove
                    if (!c.isAlive()) {
                        toRemove.add(c.getId());
                    } else {
                        c.send(m);
                    }
                }
                clients.keySet().removeAll(toRemove);
            }
        }
    }

    public void close() {
        done = true;
    }

}
