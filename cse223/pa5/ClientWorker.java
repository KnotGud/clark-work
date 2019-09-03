import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

class ClientWorker extends Thread {
    private Socket conn;
    private boolean done = false;

    public ClientWorker(Socket s) {
        conn = s;
    }

    public void run() {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(conn.getInputStream()));
            String message = null;
            while (!done && (message = in.readLine()) != null) {
                System.out.println(message);
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
    
    public void close() {
        done = true;
    }
}
