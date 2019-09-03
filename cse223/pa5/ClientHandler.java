import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Queue;
import java.util.concurrent.ArrayBlockingQueue;

public class ClientHandler extends Thread {
    private Queue<String> mQueue;
    private Socket conn;
    private boolean done = false;

    public ClientHandler (Queue<String> in, Socket s) {
        mQueue = in;
        conn = s;
    }

    public void run() {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(conn.getInputStream()));
            String line = "";
            while (!done) {
                line = in.readLine();
                mQueue.add(line);
            }
            conn.close();
        } catch (Exception e) {
            // swallowing error when user disconnects
            // System.out.print(e)
        }
    }

    public void send(String message) {
        try {
            PrintWriter out = new PrintWriter(conn.getOutputStream());
            out.println(message);
            out.flush();
        } catch (IOException e) {
            close();
        }
    }

    public void close() {
        done = true;
    }
}
