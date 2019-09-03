import java.net.ServerSocket;
import java.net.Socket;
import java.util.Map;
import java.util.HashMap;
import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

public class Server extends Thread {
    private Map<Long, ClientHandler> clients;
    private ConcurrentLinkedQueue<String> messages;
    private ServerWorker worker;
    private boolean done = false;
    public static final int port = 1221;

    public Server() {
        clients = new HashMap<Long, ClientHandler>();
        messages = new ConcurrentLinkedQueue<String>();
        worker = new ServerWorker(clients, messages);
    }

    public void run() {
        worker.start();
        try {
            ServerSocket server = new ServerSocket(port);
            System.out.printf("Server Started on %d\n", port);
            while (!done) {
                Socket s = server.accept();
                ClientHandler c = new ClientHandler(messages, s);
                c.start();
                clients.put(c.getId(), c);
            }
            server.close();
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            worker.close();
        }
    }

    public void close() {
        done = true;
    }
}
